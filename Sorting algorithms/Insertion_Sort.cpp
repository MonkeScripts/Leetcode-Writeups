//Insertion Sort
//We have an index that checks if its array value is higher/lower than the previous index, if it does not meet the sequence, it swaps with the previous index until it is in the right sequence 
//sorting in ascending order:
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        //current value in the array
        key = arr[i];
        //previous value
        j = i - 1;
        // Move elements of arr[0..i-1], 
        // that are greater than key, to one
        // position ahead of their
        // current position
        //while the prev is higher than the current value
        while (j >= 0 && arr[j] > key)
        {
            //current = prev
            arr[j + 1] = arr[j];
            //j decrements to check the prev prev index 
            j = j - 1;
        }
        //swaps the prev index to with the key
        arr[j + 1] = key;
    }
}
