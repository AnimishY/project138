//bubble sort

#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]); 
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
    bubbleSort(arr, len); 
    printArray(arr, len); 

    return 0; 
}
