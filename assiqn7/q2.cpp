#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n){
    int i, minIdx, maxIdx;

    for(i = 0; i < n/2; i++){
        minIdx = i;
        maxIdx = i;

        for(int j = i; j < n - i; j++){
            if (arr[j] < arr[minIdx])
                minIdx = j;
            if (arr[j] > arr[maxIdx])
                maxIdx = j;
        }

        swap(arr[i], arr[minIdx]);

        if (maxIdx == i)
            maxIdx = minIdx;

        swap(arr[n - i - 1], arr[maxIdx]);
    }
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {64, 25, 12, 22, 11, 90, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    printArray(arr, n);
    improvedSelectionSort(arr, n);
    cout << "Sorted array:   ";
    printArray(arr, n);
    return 0;
}
