#include <fstream>
#include <iostream>
#include <cstring>

#define RED (0x00FF0000) // RED
#define BLUE (0x000000FF) // BLUE
#define GREEN (0x0000FF00) // Green

#define WHITE (0x00FFFFFF) // WHITE
#define DARK_RED (0x007D0404) // Dark Red

using namespace std;

// Checks if the file is in the PPM format, RGB 255.
bool IsPPM_RGB(char *imageName)
{
    bool isPPM(false);
    bool checkP3(false);
    bool checkNumber(false);
    char buffer[71];

    fstream myFile(imageName, ios::in);

    if (!myFile)
    {
        cout << "Error opening file \" " << imageName << " \"" << endl << endl;
        exit(-1);
    }
    else
    {
        cout << "The file \" " << imageName << " \" has been successfully opened" << endl << endl;
    }

    myFile.getline(buffer, 71, '\n');
    if ((buffer[0] == 'P') && (buffer[1] == '3'))
    {
        checkP3 = true;
    }

    for (int i(0); i < 3; ++i) {
        myFile.getline(buffer, 71, '\n');
    }

    if ((buffer[0] == '2') && (buffer[1] == '5') && (buffer[2] == '5'))
    {
        checkNumber = true;
    }

    if ((checkP3 == true) && (checkNumber == true))
    {
        isPPM = true;
    }

    myFile.close();

    return isPPM;
}

// Procedure that returns the dimensions height and width of the image.
void ReadPPM_Dimensions(char *imageName, unsigned int &height, unsigned int &width)
{
    char buffer[71];

    fstream myFile(imageName, ios::in);

    if (!myFile)
    {
        cout << "Error opening file " << imageName << endl;
        exit(-1);
    }

    myFile.getline(buffer, 71, '\n');
    myFile.getline(buffer, 71, '\n');

    myFile >> height >> width;

    cout << "The image has dimensions: " << height << " x " << width << " pixels." << endl;

    myFile.close();
}

// Function that verifies if the dimensions of the image are identical.
bool IsSameSize(char *imageName, unsigned int height, unsigned int width)
{
    bool isSameSize(false);
    unsigned int expectedHeight(0);
    unsigned int expectedWidth(0);

    if (height == expectedHeight && width == expectedWidth)
    {
        isSameSize = true;
        cout << "The image dimensions are identical. (" << isSameSize << ")" << endl;
    }
    else
    {
        isSameSize = false;
        cout << "The image dimensions are not identical. (" << isSameSize << ")" << endl;
    }

    return isSameSize;
}

// Function to create a dynamic two-dimensional array.
unsigned int **Create2DArray(unsigned int height, unsigned int width)
{
    unsigned int **array(nullptr);
    array = new unsigned int *[height];

    for (unsigned int i(0); i < height; ++i)
    {
        array[i] = new unsigned int[width];
    }

    return array;
}

// Function to combine RGB components into a single integer.
unsigned int RGB(unsigned int red, unsigned int green, unsigned int blue)
{
    unsigned int rgb(0);

    if (red <= 255 && green <= 255 && blue <= 255)
    {
        rgb = rgb | (red << 16);
        rgb = rgb | (green << 8);
        rgb = rgb | (blue);
    }
    return rgb;
}

// Function that reads RGB values from the PPM file.
void ReadImagePPM(char *imageName, unsigned int **wTab, unsigned int height, unsigned int width)
{
    char buffer[71];
    unsigned int red(0);
    unsigned int green(0);
    unsigned int blue(0);
    unsigned int rgb(0);
    ifstream myFile(imageName, ios::in);

    for (int i(0); i <= 3; ++i)
    {
        myFile.getline(buffer, 71, '\n');
    }

    for (unsigned int i = 0; i < height; ++i)
    {
        for (unsigned int j = 0; j < width; ++j)
        {
            myFile >> red >> green >> blue;
            rgb = RGB(red, green, blue);
            wTab[i][j] = rgb;
        }
    }
    myFile.close();
}

// Function to display ANSI colors
void DisplayColor(unsigned int color)
{
    if (color == RED)
    {
        cout << "\033[31m.\033[0m "; // RED
    } else if (color == DARK_RED)
    {
        cout << "\033[31;2m.\033[0m "; // Dark Red
    } else if (color == WHITE)
    {
        cout << "\033[37m.\033[0m "; // WHITE
    } else
    {
        cout << " ";
    }
}

// Function to display the image from the wTab array.
void DisplayImage(unsigned int **wTab, unsigned int height, unsigned int width)
{
    for (unsigned int i = 0; i < height; ++i)
    {
        for (unsigned int j = 0; j < width; ++j)
        {
            DisplayColor(wTab[i][j]);
        }
        cout << endl;
    }
}

// Function to free the 2D array memory.
unsigned int **Free2DArray(unsigned int **wTab, unsigned int height, unsigned int width)
{
    if (wTab != nullptr)
    {
        for (unsigned int i(0); i < height; ++i)
        {
            for (unsigned int j(0); j < width; ++j)
            {
                wTab[i][j] = 0;
            }
        }

        for (unsigned int i(0); i < height; ++i)
        {
            if (wTab[i] != nullptr)
            {
                delete[] wTab[i];
                wTab = nullptr;
            }
        }
        delete[] wTab;
        wTab = nullptr;
    }

    return wTab;
}
