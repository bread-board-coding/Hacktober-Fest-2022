#include <iostream>

// We define the bubbleSort function
// We have to pass as parameters the array we want to sort and the lenth of it
void bubbleSort(int array[], int arrayLength)
{
    // We create an auxiliar variable
    int aux;

    // We loop through every element in the array
    for (int i = 1; i < arrayLength; i++)
    {
        for (int j = 1; j <= arrayLength - i; j++)
        {
            // If the element in the position behind is greater than the element we are analyzing
            if (array[j - 1] > array[j])
            {
                // It flips the position between these two
                aux = array[j - 1];
                array[j - 1] = array[j];
                array[j] = aux;
            }
        }
    }
}