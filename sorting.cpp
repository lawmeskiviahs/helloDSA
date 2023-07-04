#include <iostream>

// where we select the miimum number and swap it at the first index
void selectionSort(int arr[], int arrLen);

// where we push the greatest element to the last index by adjacent swapping
void bubbleSort(int arr[], int arrLen);

// where we put the element to the position it is supposed to be by adjacent swapping
void insertionSort(int arr[], int arrLen);

int main() {

    int arr[]={9,12,14,15,6,8,13,2};
    int arrLen = sizeof(arr)/sizeof(int);
    // selectionSort(arr, arrLen);
    // bubbleSort(arr, arrLen);
    insertionSort(arr, arrLen);

    return 0;
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
    
    for(int i=0;i<arrLen;i++)
        std::cout<<arr[i]<<" ";

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

    for(int i=0;i<arrLen;i++)
        std::cout<<arr[i]<<" ";

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

    for(int i=0;i<arrLen;i++)
        std::cout<<arr[i]<<" ";

    return;
}