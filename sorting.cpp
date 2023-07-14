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

// where we select a pivot and put it in it's correct order
void quickSort(int arr[], int start, int end);

int swapperQS(int arr[], int start, int end);

void swap(int arr[], int i, int j);

int main() {

    int arr[]={69, 69, 5, 5, 2, 1};
    int arrLen = sizeof(arr)/sizeof(int);
    // selectionSort(arr, arrLen);
    // bubbleSort(arr, arrLen);
    // insertionSort(arr, arrLen);
    mergeSort(arr, 0, arrLen-1);
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
        for ( int j = 0; j<arrLen-i; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                }
        }
    }

    return;
}

void insertionSort(int arr[], int arrLen) {
    for(int i = 0; i<arrLen;i++){
        for(int j = i; j>0; j--) {
            if(arr[j]<arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
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
    if( start > end ) {
        return;
    }
    int pivot = swapperQS(arr, start, end);
    quickSort(arr, start, pivot);
    quickSort(arr, pivot+1, end);
}

int swapperQS(int arr[], int start, int end) {
    // int pivot = arr[end];
    // int k = start-1;
    // for(int i = start; i < end; i++) {
    //     if( arr[i] < pivot ) {
    //         ++k;
    //         // swap(arr, k, i);
    //     }
    // }
    // ++k;
    // swap(arr, k, end);
    return 0;
}

void swap (int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}
