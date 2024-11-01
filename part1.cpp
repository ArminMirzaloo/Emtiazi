#include <iostream>
#include <cmath>
using namespace std;

int calculateParity(const string &code, int position) {
    int parity = 0;
    for (int i = position - 1; i < code.size(); i += 2 * position) {
        for (int j = 0; j < position && i + j < code.size(); ++j) {
            parity ^= (code[i + j] - '0');
        }
    }
    return parity;
}

int findError(const string &code) {
    int errorPosition = 0;
    for (int i = 0; i < log2(code.size()) + 1; ++i) {
        if (calculateParity(code, 1 << i) != 0) {
            errorPosition += (1 << i);
        }
    }
    return errorPosition;
}

void checkHammingCode(const string &code) {
    int errorPosition = findError(code);
    if (errorPosition == 0) {
        cout << "No error detected in the code." << endl;
    } else {
        cout << "Error detected at position: " << errorPosition << endl;
        string correctedCode = code;
        correctedCode[errorPosition - 1] = (correctedCode[errorPosition - 1] == '0') ? '1' : '0';
        cout << "Corrected code: " << correctedCode << endl;
    }
}

int main() {
    string codes[] = {
        "0110011001001100",  // a
        "0001110111011100",  // b
        "0000000011110000"   // c
    };

    for (int i = 0; i < 3; ++i) {
        cout << "Checking code " << char('a' + i) << ": " << codes[i] << endl;
        checkHammingCode(codes[i]);
        cout << "----------------------" << endl;
    }

    return 0;
}
