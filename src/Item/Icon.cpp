#include <algorithm>
#include <vector>
#include "Icon.h"
#include "../Display.h"
#include "icon_bitmaps.h"

// websites: 
//   - icon database: https://www.svgrepo.com/collections/monocolor/
//   - convert png to bitmap: https://diyusthad.com/image2cpp



Icon::Icon(const uint8_t** bitmap, const double scale, const Color& color):
	Item(scale),
	bitmap(bitmap),
	color(color)
	{}

Icon::Icon(const uint8_t** bitmap, const uint16_t w, const uint16_t h, const double scale, const Color& color):
	Item(scale),
	bitmap(bitmap),
	color(color)
	{ setResolution(w, h); }

Icon* Icon::create(const std::string str, const double scale, const Color& color) {
    // if (str == "arrow_right") return new Icon(60, 60, arrow_right, color);
	// if (str == "settings") return new Icon(60, 60, arrow_right, color);
    // return nullptr;
	return createIcon(str, scale, color);
}

void Icon::draw(uint16_t x, uint16_t y, Display* disp, const Color& color) {
	uint16_t tmpX = x - icon_resolutions[resolution]/2;
	uint16_t tmpY = y - icon_resolutions[resolution+1]/2;
	LOGGER_PATTERN("Zeichne Icon in größe _ (i=_), _ an Stelle (_/_)", icon_resolutions[resolution], resolution, icon_resolutions[resolution+1], tmpX, tmpY)
    disp->drawBitmap(tmpX, tmpY, icon_resolutions[resolution], icon_resolutions[resolution+1], bitmap[resolution/2], color);
};

void Icon::draw(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

void Icon::drawOn(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color);
}

void Icon::drawOff(uint16_t x, uint16_t y, Display* disp) {
    draw(x, y, disp, color.getSecondaryColor());
}

void Icon::setResolution(const uint16_t width, const uint16_t height, const bool override) {
	for (int i = 0; i < icon_resolutions.size(); i += 2) {
        uint16_t icon_width = icon_resolutions[i] * scale;
        uint16_t icon_height = icon_resolutions[i + 1] * scale;

        if (icon_width <= width && icon_height <= height) {
            if (i + 2 >= icon_resolutions.size() || icon_resolutions[i + 2] > width || icon_resolutions[i + 3] > height) {
                resolution = i;
				return;
            }
        }
    }
}

uint16_t Icon::getWith() {return icon_resolutions[resolution];}
uint16_t Icon::getHeight() {return icon_resolutions[resolution+1];}