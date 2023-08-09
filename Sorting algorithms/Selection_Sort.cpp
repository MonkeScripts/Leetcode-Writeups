//selection sort: 2 pointers. 1 to point at the current index and the other to iterate through the rest of the list
//function to swap the values: we are changing the value in memory by dereferencing the pointers and assigning them to a new value
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
    //loop through the array. This is the pointer that denotes the position in the array to swap woth
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted portion of array
        //minimum index = i because anything before that is sorted
        min_idx = i; 
        //iterate through rest of array to find minimum element
        for (j = i+1; j < n; j++)
        {
          if (arr[j] < arr[min_idx]) 
              min_idx = j;
        }
        // Swap the found minimum element with the first element 
        if (min_idx!=i)
            swap(&arr[min_idx], &arr[i]);
    }
} 
