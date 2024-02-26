// create an array and rotate it by key k

#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int k) {
    k = k % n; // Adjust k to be within the range of array size

    int *temp = new int[k];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }
    for (int i = 0; i < k; i++) {
        arr[n - k + i] = temp[i];
    }

    delete[] temp; // Free the dynamically allocated memory
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
    int len, key;
    cout << "Enter the length of the array: ";
    cin >> len;
    int *arr = new int[len];

    inputArray(arr, len);
    cout << "Enter the key: ";
    cin >> key;
    rotateArray(arr, len, key);
    printArray(arr, len);

    return 0;
}
