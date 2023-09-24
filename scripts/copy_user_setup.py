import os
import shutil

def copy_user_setup():
    setup_folder = 'TFT_User_Setup'

    current_dir = os.getcwd()                           # Pfad zum TouchMenu Ordner
    setup_dir = os.path.join(current_dir, setup_folder) # Pfad zu den Setup Dateien

    #print(os.listdir(setup_dir)[0].split('_', 2)[2].split('.')[0])

    for file_name in os.listdir(setup_dir):
        if file_name.startswith('TFT_Setup_'):
            env_name = file_name.split('_', 2)[2].split('.')[0]
            target_dir = os.path.join(current_dir, '.pio', 'libdeps', env_name, 'TFT_eSPI')

            if os.path.isdir(target_dir):
                source_path = os.path.join(setup_dir, file_name)
                target_path = os.path.join(target_dir, 'User_Setup.h')

                shutil.copyfile(source_path, target_path)
                print(f'[copy_user_setup] Copied {file_name} to {target_path}')
            else:
                print(f'[copy_user_setup] Target directory not found for {file_name}: {target_dir}')

copy_user_setup()
