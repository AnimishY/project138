//insertion sort

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
}

void inputArray(int inArray[], int n) {
        for (int i = 0; i < n; i++) {
                    cout << "Enter the elements: ";
                        cin >> inArray[i];
                        }
}

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}

int main() 
{ 
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    int *arr  = new int[len];

    inputArray(arr, len);
    insertionSort(arr, len); 
    printArray(arr, len); 

    return 0; 
}
