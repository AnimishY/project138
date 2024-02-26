#include <iostream>
using namespace std;

void inputArray(int inArray[], int n) {
	    for (int i = 0; i < n; i++) {
		            cout << "Enter the elements: ";
			            cin >> inArray[i];
				        }
}

int main() {
	int length;
	cin >> length;
	int inArray[length];	
	inputArray(inArray, length);
	int ele;
	cout << "Element to search: ";
	cin >> ele;

	for (int i = 0; i < length; i++) {
		if (inArray[i] == ele) {
			cout << "Found element " << ele << " at index " << i;
		}
	}
}

