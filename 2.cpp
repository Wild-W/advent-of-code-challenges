#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input;
    input.open("./2in.txt");

    int points = 0;
    #pragma region part1
    // char opponent, response;

    // while (input >> opponent >> response) {
    //     int ascii = response - 23 - opponent;
    //     if (ascii == 0) {
    //         points += 3;
    //     }
    //     else if (ascii == 1 || ascii == -2) {
    //         points += 6;
    //     }
    //     points += response - 87;
    // }
    #pragma endregion

    char rps, winCode;

    while (input >> rps >> winCode) {
        if (winCode == 'Y') {
            points += 3 + rps - 64;
        }
        else if (winCode == 'Z') {
            points += 6;
            if (rps == 'C') {
                points += 1;
            }
            else if (rps == 'A') {
                points += 2;
            }
            else {
                points += 3;
            }
        }
        else {
            if (rps == 'C') {
                points += 2;
            }
            else if (rps == 'A') {
                points += 3;
            }
            else {
                points += 1;
            }
        }
    }
    cout << points << endl;

    return 0;
}
