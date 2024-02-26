#include <iostream>
using namespace std;

void bucketSort(int arr[], int n, int max_val) {
    int* bucket = new int[max_val + 1] {0};

    for (int i = 0; i < n; i++) {
        bucket[arr[i]]++;
    }

    for (int i = 0, j = 0; i <= max_val; i++) {
        while (bucket[i] > 0) {
            arr[j++] = i;
            bucket[i]--;
        }
    }

    delete[] bucket;
}

void input(int arr[], int n) {
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display(int arr[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int max(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    input(arr, n);
    int max_val = max(arr, n);

    bucketSort(arr, n, max_val);

    cout << "Sorted array: ";
    display(arr, n);
    return 0;
}