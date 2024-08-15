//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
      // Function to sort an array using the quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        if (low < high) 
        {
            int pIndex = partition(arr, low, high);
            quickSort(arr, low, pIndex - 1);
            quickSort(arr, pIndex + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low + 1;  // Start i from low+1
        int j = high;     // Start j from high
        
        while (i <= j)
        {
            // Increment i while arr[i] is less than or equal to pivot
            while (i <= high && arr[i] <= pivot)
            {
                i++;
            }
            
            // Decrement j while arr[j] is greater than pivot
            while (j >= low && arr[j] > pivot)
            {
                j--;
            }
            
            // If i is still less than j, swap the elements
            if (i < j)
            {
                swap(arr[i], arr[j]);
            }
        }
        
        // Swap the pivot element with the element at index j
        swap(arr[low], arr[j]);
        
        // Return the partition index
        return j;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends