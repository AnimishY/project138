// print factors of a number

#include <iostream>
using namespace std;

void printFactors(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factors of " << n << " are: ";
    printFactors(n);
    return 0;
}
