#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream input;
    input.open("./3in.txt");

    string line;
    int sum = 0;

    while (input >> line) {
        string part1 = "";

        int len = line.length();
        for (int i = 0; i < len; i++) {
            if (i < len / 2) {
                part1.push_back(line[i]);
            }
            else {
                if (find(part1.begin(), part1.end(), line[i]) != part1.end()) {
                    int ascii = line[i] - 64;
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
    }

    cout << sum << endl;

    return 0;
}