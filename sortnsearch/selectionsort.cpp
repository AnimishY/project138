// selection sort

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void inputArray(int inArray[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the elements: ";
        cin >> inArray[i];
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    int *arr = new int[len];

    inputArray(arr, len);
    selectionSort(arr, len);
    printArray(arr, len);

    return 0;
}
