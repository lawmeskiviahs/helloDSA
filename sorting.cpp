#include <iostream>

// where we select the miimum number and swap it at the first index
void selectionSort(int arr[], int arrLen);

// where we push the greatest element to the last index by adjacent swapping
void bubbleSort(int arr[], int arrLen);

// where we put the element to the position it is supposed to be by adjacent swapping
void insertionSort(int arr[], int arrLen);

// where we divide the array in two until it is cannot be further divided; then sorting them and merging
void mergeSort(int arr[], int start, int end);

// to merge the divided sub arrays (merge sort)
void mergerMS(int arr[], int start, int mid, int end);

// where we find the correct index of the pivot element and place all the smaller elements to its left
void quickSort(int arr[], int start, int end);

// to implement quick sort
int swapperQS(int arr[], int start, int end);

// to swap the ith and jth indices of array arr
void swap(int arr[], int i, int j);

int main() {

    int arr[]={8, 7, 6, 1, 0, 9, 2};
    int arrLen = sizeof(arr)/sizeof(int);
    // selectionSort(arr, arrLen);
    // bubbleSort(arr, arrLen);
    // insertionSort(arr, arrLen);
    // mergeSort(arr, 0, arrLen-1);
    // quickSort(arr, 0, arrLen-1);
    for(int i=0;i<arrLen;i++)
        std::cout<<arr[i]<<" ";

    // return 0;
}

void selectionSort(int arr[], int arrLen) {
    
    for (int i = 0; i<arrLen; i++) {
        int min = 9999999;
        int minIndex;
        for ( int j = i; j<arrLen; j++) {
            if(arr[j]<min) {
                min=arr[j];
                minIndex=j;
            }
        }
        int temp = arr[i];
        arr[i]= min;
        arr[minIndex] = temp;
    }
    
    return;
}

void bubbleSort(int arr[], int arrLen) {
    
    for (int i = 0; i<arrLen-1; i++) {
        for ( int j = 0; j<(arrLen-1)-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
                }
        }
    }

    return;
}

void insertionSort(int arr[], int arrLen) {
    for(int i = 0; i<arrLen;i++){
        for(int j = i; j>0; j--) {
            if(arr[j]<arr[j-1]) {
                swap(arr, j, j-1);
                }
        }
    }
    return;
}

void mergeSort(int arr[], int start, int end) {
    if(start>=end)
        {
            return;
        }
    int mid = start+(end-start)/2;

    // divide left through recursion
    mergeSort(arr, start, mid);

    // divide right through recursion
    mergeSort(arr, mid+1, end);

    // conquer (merge the divided sub arrays)
    mergerMS(arr, start, mid, end);
}

void mergerMS (int arr[], int start, int mid, int end) {

    // temporary array to store the sorted array
    int sortedArray[end-start+1];
    int sortedarrLen = sizeof(sortedArray)/sizeof(int);

    // iterator for left subarray
    int i1 = start;

    // iterator for right subarray
    int i2 = mid+1;

    // iterator for the sorted array
    int i =0;

    // select the smaller element of either subarrays to save in sorted array
    while(i1<=mid&&i2<=end){
         if( arr[i1]<arr[i2]) {
            sortedArray[i] = arr[i1];
            i1++;
            i++;
        } else {
            sortedArray[i] = arr[i2];
            i2++;
            i++;
        }
    }

    // save any remaining elements from left array
    while(i1<=mid) {
        sortedArray[i]=arr[i1];
        i1++;
        i++;
    }

    // save any remaining elements from the irght array
    while(i2<=end) {
        sortedArray[i]=arr[i2];
        i2++;
        i++;
    }

    // copy the sorted array into the original array
    for(int k=0,j=start;k<sortedarrLen;k++,j++)
        arr[j]=sortedArray[k];

    return;
}

void quickSort(int arr[], int start, int end) {
    if( start >= end ) {
        return;
    }

    // quick sort functionality
    int pivotIndex = swapperQS(arr, start, end);
    // quick sort the left side of pivot
    quickSort(arr, start, pivotIndex-1);
    // to quick sort the right side of the pivot
    quickSort(arr, pivotIndex+1, end);

}

int swapperQS(int arr[], int start, int end) {
    // select pivot element
    int pivot = arr[end];
    // counter for index of pivot
    int k = start-1;
    for(int i = start; i < end; i++) {
        if( arr[i] < pivot ) {
            // place elements smaller than the pivot element to kth index
            swap(arr, ++k, i);
        }
    }
    // place the pivot element at it's correct index
    swap(arr, ++k, end);
    return k;
}

void swap (int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
