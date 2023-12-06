#ifndef FILE_PPM_H
#define FILE_PPM_H

// (1) Checks if the file is in the PPM format, RGB 255.
bool IsPPM_RGB(char *imageName);

// (2) Procedure that returns the dimensions height and width of the image.
void ReadPPM_Dimensions(char *imageName, unsigned int &height, unsigned int &width);

// (3) Function that verifies if the dimensions of the image are identical.
bool IsSameSize(char *imageName, unsigned int height, unsigned int width);

// (4) Function to create a dynamic two-dimensional array.
unsigned int **Create2DArray(unsigned int height, unsigned int width);

// (5) Function to combine RGB components into a single integer.
unsigned int RGB(unsigned int red, unsigned int green, unsigned int blue);

// (6) Function that reads RGB values from the PPM file.
void ReadImagePPM(char *imageName, unsigned int **wTab, unsigned int height, unsigned int width);

void DisplayColor(unsigned int color);

// (7) Function to display the image from the wTab array.
void DisplayImage(unsigned int **wTab, unsigned int height, unsigned int width);

// (8) Function to free the 2D array memory.
unsigned int **Free2DArray(unsigned int **wTab, unsigned int height, unsigned int width);

#endif // FILE_PPM_H
