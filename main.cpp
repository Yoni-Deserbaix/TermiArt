#include "ppm_file.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Return
    bool isFileVerified(false);
    bool areDimensionsVerified(false);
    unsigned int resultRGB(0);
    unsigned int **logoArray(nullptr);

    // Parameters

    // Image file path
    char *fileName = "C:\\YOUR FILE PPM"; // Select your file ppm

    // Variables to store image dimensions
    unsigned int height(0);
    unsigned int width(0);

    // Expected dimensions of the image
    unsigned int expectedHeight(0);
    unsigned int expectedWidth(0);


    unsigned int red(0);
    unsigned int green = (0);
    unsigned int blue = (0);

    // Function/procedure calls

    // Verify image format
    isFileVerified = IsPPM_RGB(fileName);

    if (isFileVerified == true)
    {
        cout << "The file is in PPM format, RGB 255. (" << isFileVerified << ")." << endl;

        // Read image dimensions
        ReadPPM_Dimensions(fileName, height, width);

        // Check if the dimensions match the expected ones
        areDimensionsVerified = IsSameSize(fileName, expectedHeight, expectedWidth);

        if (areDimensionsVerified == true)
        {
            // Create the array
            logoArray = Create2DArray(height, width);

            // Call the RGB function
            resultRGB = RGB(red, green, blue);

            // Read the image
            ReadImagePPM(fileName, logoArray, height, width);

            // Display the image
            DisplayImage(logoArray, height, width);

            // Free the array
            Free2DArray(logoArray, height, width);
        }
    }

    return 0;
}
