//Quicksort
//Choose a pivot, move everything lower to the left and everything higher to the right -> current pivot is in the right position
//Recursively call left and right of the pivot -> quicksort left and right portions recursively


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
//partition algorithm (establishing pivot and moving the rest)
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // we set the pivot to the end of the array
    int i = (low- 1); // Index of smaller element and indicates the right position of pivot found so far
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    //at the end, all indexes that are larger would be swapped to a postion after i(increments whenever it encounters a number samller than pivot), we insert the pivot into i+1 by doing one last swap
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now at right place */
        int pi = partition(arr, low, high);
        //now we just run a quicksort to the left and right of the pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
