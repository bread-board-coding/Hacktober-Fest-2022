
// To use this function the array have to be sorted previously
// We use templates to make the function generic
template <typename T>
int binarySearch(T array[], int length, T search)
{
    // Define the variables
    int first = 0;
    int last = length - 1;
    int middle;

    // while the first element is less than the last one
    while (first <= last)
    {
        // Assign the middle variable to the middle position in the array
        middle = (first + last) / 2;
        // if the middle element is the one we are looking for
        if (array[middle] == search)
        {
            // rerturn the element
            return middle;
        }

        // If the middle element is greater than the one we are looking for
        if (array[middle] > search)
        {
            // we move the last variable to one behind the middle
            // because we know that it isn't in the right side of the array
            last = middle - 1;
        }
        else
        {
            // else we move the first position of the array because we know that
            // the element we are looking for is in the right side of the array
            first = middle + 1;
        }
    }
    // If the element isn't in the array it will return -1
    return -1;
}
