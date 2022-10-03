#include <iostream>

// We use templates to make it generic and allow the programmer
// to use whatever type he/she wants
template <typename T>
void printArray(T array[], int length)
{
    // Print the start of the array
    std::cout << "\n[";
    // Loop through every element in the array
    for (int i = 0; i < length; i++)
    {
        // Print the value of the element
        std::cout << array[i];
        // If the element isn't the last one in the array
        if (i != length - 1)
        {
            // Add a comma
            std::cout << ", ";
        }
    }
    // Print the end of the array
    std::cout << "]\n";
}