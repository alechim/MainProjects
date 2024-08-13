# Alec Him
# Python Project - Desktop Cleaner
# Description: A python automation program that cleans up the desktop downloads folder and organizes files based on file types

# Libraries
import os
import shutil
from dotenv import load_dotenv

# Dictionary to store file types and extensions
file_types = {
    'Images': ['.jpg', '.jpeg', '.png', '.gif', '.bmp'],
    'Documents': ['.pdf', '.doc', '.docx', '.xlsx', '.txt', '.pptx'],
    'Audio': ['.mp3', '.wav', '.aac'],
    'Video': ['.mp4', '.mkv', '.avi', '.mov'],
    'Archives': ['.zip', '.rar', '.7z'],
    'Programs': ['.exe', '.msi', '.dmg']
}

# Grab path from .env
load_dotenv()
PATH: str = os.getenv('DOWNLOADS_PATH')

# Functions
def create_folders(base_path, file_types):
    """Reads through the file_types dictionary and creates folders in the base_path if they don't exist"""
    for folder in file_types.keys():
        folder_path = os.path.join(base_path, folder)
        if not os.path.exists(folder_path):
            os.mkdir(folder_path)

def move_files(base_path, file_types):
    """Reads through the file_types dictionary and moves files to their respective folders"""
    for file_name in os.listdir(base_path):
        file_path = os.path.join(base_path, file_name)
        if os.path.isfile(file_path):
            file_extension = os.path.splitext(file_name)[1].lower()
            moved = False
            for folder, extensions in file_types.items():
                if file_extension in extensions:
                    shutil.move(file_path, os.path.join(base_path, folder, file_name))
                    moved = True
                    break
            if not moved:
                # If the file does not match any extension, move to 'Others'
                other_folder = os.path.join(base_path, 'Others')
                if not os.path.exists(other_folder):
                    os.mkdir(other_folder)
                shutil.move(file_path, os.path.join(other_folder, file_name))

# Main
def main():
    # Change the path variable to your own downloads folder path
    path = PATH
    downloads_folder = os.path.expanduser(path)
    print(f"Downloads folder path: {downloads_folder}")
    create_folders(downloads_folder, file_types)
    move_files(downloads_folder, file_types)

if __name__ == "__main__":
    main()