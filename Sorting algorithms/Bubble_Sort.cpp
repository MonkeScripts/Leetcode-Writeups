//Bubble sort
//checks the array by 2 indexes at a time, swap them to the correct order (ascending/descending)
//At the end of iteration, we know that the last element in the array is sorted since the largest number would have been swapped multiple times to reach to the end
//we repeat this for n times to make sure everything is sorted

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Last i elements are already in place
        //for the second loop out limit is n-i-1 since the last elements are getting sorted and we do not need to iterate through them
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
