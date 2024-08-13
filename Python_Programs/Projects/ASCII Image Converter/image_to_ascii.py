# Alec Him
# Python Project - Image to ASCII

# Libraries
import os, sys
from PIL import Image

# Set
imageExtensions = {
    ".jpg",
    ".jpeg",
    ".png",
    ".gif",
    ".bmp"
}

# Functions
def find_images(directory, imgName):
    """Find images in the given directory."""
    for filename in os.listdir(directory):
        if os.path.splitext(filename)[0].lower() == imgName.lower():
            print("File found:", filename)
            imgPath = os.path.join(directory, filename)
            return imgPath
    return None

def open_image(imgPath):
    """Tries to open an image file and throws an error if it fails."""
    try:
        # Opens the image in grayscale
        img = Image.open(imgPath).convert('L')
        return img
    except Exception as e:
        print(f"Error opening image '{imgPath}': {str(e)}")
        return None

def convertASCII(img, scale):
    """Rescales the passed image and converts it to ASCII characters."""
    scale = int(scale)
    w, h = img.size
    image = img.resize((w // scale, h // scale), Image.NEAREST)

    w, h = image.size
    ascii_art = []
    for _ in range(h):
        ascii_art.append(["X"] * w)
    pic = image.load()

    for y in range(h):
        for x in range(w):
            avg = pic[x , y]
            if avg == 0:
                ascii_art[y][x] = "#"
            elif avg in range(1, 100):
                ascii_art[y][x] = "."
            elif avg in range(100, 200):
                ascii_art[y][x] = "@"
            elif avg in range(200, 300):
                ascii_art[y][x] = "&"
            elif avg in range(300, 400):
                ascii_art[y][x] = "*"
            elif avg in range(400, 500):
                ascii_art[y][x] = "-"
            elif avg in range(500, 600):
                ascii_art[y][x] = "+"
            elif avg in range(600, 700):
                ascii_art[y][x] = "="
            elif avg in range(700, 750):
                ascii_art[y][x] = ":"
            else:
                ascii_art[y][x] = " "

    return ascii_art


def main():
    # Change directory to your own image folder path
    script_dir = os.path.dirname(__file__)
    directory = os.path.join(script_dir, "img")
    # Change scale based on image size
    scale = 5

    # Prompt user for input and loops until a valid image is found or user exits
    while True:
        imgName = input("Enter the name of the image: ")
        imgPath = find_images(directory, imgName)
        if imgPath:
            img = open_image(imgPath)
            if img:
                # Image opened successfully, exit loop
                break
            else:
                print("Failed to open image. Please try again.")
        else:
            print("File not found. Please try again.")
        
        # Ask user if they want to exit
        response = input("Do you want to exit? (y/n): ")
        if response.lower() == "y":
            sys.exit()

    # Create a folder for converted images
    outFolder = os.path.join(script_dir, "ascii_img")
    if not os.path.exists(outFolder):
        os.mkdir(outFolder)

    # Convert image to ASCII
    print("Converting image to ASCII...")
    ascii_img = convertASCII(img, scale)
    print("Done!")

    # Save image
    outFile = os.path.join(outFolder, imgName + "_ascii.txt")
    with open(outFile, "w") as f:
        for row in ascii_img:
            f.write("".join(row) + "\n")
        print("Image saved to", outFile)
    
    f.close()

# Call Main
if __name__ == "__main__":
    main()