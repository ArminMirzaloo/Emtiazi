#include <iostream>
using namespace std;

int calculateParity(const string &code) {
    int parity = 0;
    for (char bit : code) {
        parity ^= (bit - '0'); 
    }
    return parity;
}

int main() {
    string code;
    cout << "Enter the binary code: ";
    cin >> code;

    int parity = calculateParity(code);
    cout << "Parity bit is: " << parity << endl;

    return 0;
}
