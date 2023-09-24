import os
import sys
import re
from PIL import Image
from io import BytesIO

# solution for an error:
# .\pip3.8.exe install pipwin
#  pipwin install cairocffi


def logging (str):
    # print(f"[{__file__.split('/')[-1].split(chr(92))[-1].split('.')[-2]}] {str}")
    print(f"[convert_icons_to_code] {str}")

# Check whether cairosvg is installed
try:
    import cairosvg
except ImportError:
    logging("Error: The library 'cairosvg' is not installed. Please install it with 'pip install cairosvg' and run the programme again.")
    sys.exit(0)

try:
    import numpy as np
except ImportError:
    logging("Error: The library 'numpy' is not installed. Please install it with 'pip install numpy' and run the programme again.")
    sys.exit(0)

base_folder = "icon_templates"
output_folder = "src/Item/"

# Set resolutions for the icons
resolutions = [(8, 8), (16, 16), (24, 24), (32, 32), (40, 40), (48, 48), (56, 56), (64, 64), (72, 72), (80, 80), (88, 88), (96, 96)]

def read_svg(svg_file, name):
    with open(svg_file, encoding="utf8") as fileHandle:
        svg = fileHandle.read()

    svg_pattern = r'<svg[^>]*transform="([^"]*)"[^>]*>'
    svg_match = re.search(svg_pattern, svg)

    # Since transform with rotation and matrix cause an error and therefore a black image, this SVG parameter is removed.
    if svg_match:
        svg_transform_value = svg_match.group(1)
        
        # Extrahieren der rotate- und matrix-Werte
        rotate_match = re.search(r'rotate\(([^)]*)\)', svg_transform_value)
        matrix_match = re.search(r'matrix\(([^)]*)\)', svg_transform_value)
        
        # Wenn entweder rotate oder matrix vorhanden ist, entferne das transform-Attribut
        if rotate_match or matrix_match:
            svg = re.sub(svg_pattern, lambda m: m.group().replace(f'transform="{svg_transform_value}"', ''), svg)
            
        rotate_value = rotate_match.group(1) if rotate_match else None
        matrix_value = matrix_match.group(1) if matrix_match else None
        
        logging(f'icon {name} has rotate={rotate_value} and matrix=[{matrix_value}] that unfortunately had to be removed')
    
    return svg

def convert_to_c_array (svg, resolution, name):
    svg_data = cairosvg.svg2png(bytestring=svg, output_width=resolution[0], output_height=resolution[1], background_color="white")
    img = Image.open(BytesIO(svg_data))
    if img.getcolors() == [(img.width * img.height, (0, 0, 0, 255))]:
        logging(f"WARN: Conversion from {name} Failed")
    
    inverted_image = Image.new("RGB", img.size)
    inverted_data = np.array(img)
    inverted_data = 255 - inverted_data
    inverted_pixels = [tuple(map(int, pixel)) for pixel in inverted_data.reshape(-1, 3)]
    expected_size = img.width * img.height * 3
    if inverted_data.size != expected_size:
        logging(f"ERROR: Die Größe des invertierten Daten-Arrays stimmt nicht mit der Bildgröße überein. ({inverted_data.size=}, {expected_size=}, {img.size})")
        return ""
    
    inverted_image.putdata(inverted_pixels)
    
    c_array = ""
    for y in range(resolution[1]):
        for x in range(0, resolution[0], 8):  # Lese 8 Pixel gleichzeitig ein
            byte_value = 0
            for i in range(8):
                if x + i < resolution[0]:
                    pixel_value = inverted_image.getpixel((x + i, y))
                    grayscale_value = int(0.2989 * pixel_value[0] + 0.5870 * pixel_value[1] + 0.1140 * pixel_value[2])
                    if grayscale_value > 128:  # Schwellenwert für Schwarz/Weiß
                        byte_value |= 1 << (7 - i)  # Setze das entsprechende Bit
            c_array += f"0x{byte_value:02X}, "

    return c_array


def main():
    # Check if the input folder exists
    if not os.path.exists(base_folder):
        logging(f"Error: The base folder {base_folder} does not exist.")
        sys.exit(0)

    # Öffnen Sie die Ausgabedatei im Schreibmodus
    output_file_path = os.path.join(output_folder, "icon_bitmaps.h")
    with open(output_file_path, "w") as output_file:
        output_file.write('#pragma once\n')
        output_file.write('#include <Arduino.h>\n')
        output_file.write('#include <vector>\n')
        output_file.write('#include <tuple>\n')
        output_file.write('#include "Item.h"\n')
        output_file.write('#define ICONPACK_default\n\n')

        # pass the resolutions to the C++ code
        resolution_str = ', '.join([f"{w}, {h}" for w, h in resolutions])
        output_file.write(f"const std::vector<uint16_t> icon_resolutions = {{ {resolution_str} }};\n\n")

        icons = {}

        # Loop through all subfolders in the base folder
        for subfolder in os.listdir(base_folder):
            subfolder_path = os.path.join(base_folder, subfolder)

            # Check whether it is a folder
            if not os.path.isdir(subfolder_path):
                continue

            output_file.write(f"#ifdef ICONPACK_{subfolder}\n")
            icons[subfolder] = []

            # Loop through all files in the subfolder
            for filename in os.listdir(subfolder_path):
                if not filename.endswith(".svg"):
                    continue

                svg_file_path = os.path.join(subfolder_path, filename)
                icon_name = os.path.splitext(filename)[0]  # icon_name = filename (without ending)

                # get svg file content
                svg = read_svg(svg_file_path, icon_name)

                names = []
                icons[subfolder].append(icon_name)

                output_file.write(f"// Icon: {icon_name}\n")

                # Loop through the different resolutions
                for res in resolutions:

                    names.append(f"_ICON_{icon_name}_{res[0]}_{res[1]}")
                    output_file.write(f"const unsigned char {names[-1]}[] PROGMEM = {{")
                    output_file.write(convert_to_c_array(svg, res, icon_name))
                    output_file.write("};\n")

                str = ", ".join(names)
                output_file.write(f"const unsigned char* PROGMEM ICON_{icon_name}[] = {{ {str} }};\n\n")
            
            output_file.write(f"#endif // {subfolder}\n\n")

        output_file.write("Icon* createIcon(const std::string str, const double scale, const Color& color) {\n")
        for key, value in icons.items():
            output_file.write(f"\t#ifdef ICONPACK_{key}\n")
            for icon_name in value:
                output_file.write(f'\tif (str == "{icon_name}") return new Icon(ICON_{icon_name}, scale, color);\n')
            output_file.write(f"\t#endif // {key}\n\n")
        output_file.write("\treturn nullptr;\n}")

    logging(f"The SVG files from the subfolders of {base_folder} were successfully saved in a single icon_templates.h file")

# if __name__ == '__main__':
main()