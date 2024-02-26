#include <iostream>

using namespace std;

int findMax(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

void countingSort(int array[], int size, int place) {
    const int max = 10;
    int output[size];
    int count[max] = {0};

    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void radixSort(int array[], int size) {
    int max = findMax(array, size);

    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

int main() {
    int length;
    cout << "Enter the number of elements: ";
    cin >> length;

    int arr[length];
    cout << "Enter the elements: ";
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}