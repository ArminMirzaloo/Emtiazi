#include <iostream>
using namespace std;

void checkAndCorrectHammingCode(string &code) {
    int errorPosition = 0;
    int n = code.size();
    
    
    for (int i = 0; (1 << i) <= n; ++i) {
        int parity = 0;
        for (int j = 1; j <= n; ++j) {
            if (j & (1 << i)) {
                parity ^= (code[j - 1] - '0');
            }
        }
        if (parity != 0) errorPosition += (1 << i);
    }

    
    if (errorPosition == 0) {
        cout << "No error detected in the code." << endl;
    } else {
        cout << "Error detected at position: " << errorPosition << endl;
        code[errorPosition - 1] = (code[errorPosition - 1] == '0') ? '1' : '0';
        cout << "Corrected code: " << code << endl;
    }
}

int main() {
    string code;
    cout << "Enter a 16-bit binary code: ";
    cin >> code;

    if (code.size() != 16) {
        cout << "Error: Code must be 16 bits long." << endl;
        return 1;
    }

    checkAndCorrectHammingCode(code);

    return 0;
}
