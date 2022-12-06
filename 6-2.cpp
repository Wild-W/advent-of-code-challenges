#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int main() {
    ifstream input("./6in.txt");
    string text;
    input >> text;

    for (int i = 13; i < text.length(); i++) {
        set<char> uniques;
        for (int j = 0; j < 14; j++) {
            uniques.insert(text[i-j]);
        }

        if (uniques.size() == 14) {
            cout << i + 1 << endl;
            break;
        }
    }
}