# TermiArt Project 🎨

The TermiArt project was developed as part of my computer science education at a higher school. Its goal is to implement file streams and the various functions they offer. This program allows reading and displaying images in .ppm format within a terminal.

## Features

This program offers the following capabilities :

- Read and display .ppm images: The program is designed to read images with the .ppm extension and display them in a terminal.
- True color display: An additional feature has been added to display real colors in the terminal using ANSI escape sequences.

## Screenshots 📸

### Original Image :

![Original Image](https://github.com/YD-SavvyDev/TermiArt/blob/main/Screenshots/Heart-ppm.png)

### Terminal Result :

![Terminal Image](https://github.com/YD-SavvyDev/TermiArt/blob/main/Screenshots/terminal.png)

## Technologies Used
The project was developed using the following technologies:
- C++   <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" height="15" alt="cplusplus logo"  />

- QTCreator   <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/qt/qt-original.svg" height="15" alt="qt logo"  />


## Project Structure 📁

The project structure is organized as follows:

- `TermiArt.pro`: Project configuration file for Qt Creator.
- `main.cpp`: Main file used for display.
- `ppm_file.h`: Header file containing declarations of functions for handling .ppm files.
- `ppm_file.cpp`: Source file containing implementations of functions for handling .ppm files.

## Usage 🛠️

1. Clone the repository to your local machine   <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/git/git-original.svg" height="15" alt="git logo"  /> :
    ```bash
    git clone https://github.com/YD-SavvyDev/TermiArt.git
    ```
2. Ensure you have installed a plugin or feature in your IDE that allows reading QStrings from the Qt framework.
3. Add your .ppm format image to the project folder. 
</br>
4. Open the main.cpp file and modify the sNomFichier variable with the path to your .ppm image:

```cpp
char * sNomFichier  = "C:\\YOUR FILE .PPM" ; // Select your .ppm file
```

5. Define your colors according to your image.

```cpp
#define • COLOR (0x000000) // YOUR HEXA CODE COLOR
#define ...
#define ...
```
7. Modify this function

```cpp
void DisplayColor(unsigned int color)
{
    if (color == RED)
    {
        cout << "\033[31m.\033[0m "; // RED
    } 
    else if (color == ...)
    {
        cout << "\............. "; // YOUR COLOR CODE
    } 
    else
    {
        cout << " ";
    }
}
```
8. Run the program ! 
## Skills Gained 🌟
Developing this project provided an opportunity to enhance proficiency in :

- Software development 
- Memory management, dynamic allocation
- Basic input and output streams : files
- Data structure and management : Binary file formats

## Author 👨‍💻
This project was created by me. Feel free to reach out for any inquiries or collaboration opportunities.
