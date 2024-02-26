
#include <iostream> 
using namespace std; 

int binarySearch(int arr[], int low, int high, int x) 
{ 
    if (high >= low) { 
        int mid = low + (high - low) / 2; 
        if (arr[mid] == x) 
            return mid; 

        if (arr[mid] > x) 
            return binarySearch(arr, low, mid - 1, x); 

        return binarySearch(arr, mid + 1, high, x); 
    } 
    return -1; 
} 

void inputArray(int inArray[], int n) {
        for (int i = 0; i < n; i++) {
                    cout << "Enter the elements: ";
                        cin >> inArray[i];
                        }
}

int main(void) 
{ 
    int len;
    cout << "Enter the length of the array: ";
    cin >> len;
    int *arr  = new int[len];

    inputArray(arr, len);
    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    int result = binarySearch(arr, 0, len - 1, x); 
    (result == -1) 
        ? cout << "Element is not present in array"
        : cout << "Element is present at index " << result; 

    return 0; 
}
