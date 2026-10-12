#include <iostream>
#include <algorithm>
using namespace std;

//when sorting usually just use std::sort

//binary search only works if array is already sorted
int binarySearch(const int *arr, int n, int target){
    int lo = 0; int hi = n-1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] < target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return -1;
}

void printArr(const int *arr, int n){
    for (int i = 0; i < n; ++i){
        cout << arr[i];
        if(i < n-1){
            cout << " ";
        }
    }
    cout << endl;
}

void selectionSort(int *arr, int n){
    for(int i=0; i < n-1; ++i){
        int minIdx = i;
        for(int j = i +1; j<n; ++j){
            if(arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);

    }
}

void insertionSort(int *arr, int n){
    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int j = i - 1;

        while((j >= 0) && (arr[j] > key)){
            arr[j + i] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


int main(){
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int b[] = {64, 34, 25, 12, 22, 11, 90};
    int c[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    selectionSort(a, n);
    cout << "selection sort: ";
    printArr(a,n);

    insertionSort(b, n);
    cout << "insertion sort: ";
    printArr(b, n);

    std::sort(c, c + n);
    cout << "std:sort: ";
    printArr(c,n);

    return 0;
}


// putting time before the execution will give run time:
// time./practice