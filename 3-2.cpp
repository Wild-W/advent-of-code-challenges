#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream input;
    input.open("./3in.txt");

    int sum = 0;
    string a, b, c;

    while (input >> a >> b >> c) {
        for (char ch : a) {
            if (find(b.begin(), b.end(), ch) != b.end() && find(c.begin(), c.end(), ch) != c.end()) {
                int ascii = ch - 64;
                if (ascii > 0 && ascii < 27) {
                    ascii += 26;
                }
                else if (ascii > 32 && ascii < 59) {
                    ascii -= 32;
                }
                sum += ascii;
                break;
            }
        }
    }

    cout << sum << endl;

    return 0;
}