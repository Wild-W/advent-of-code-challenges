#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;

int main() {
    ifstream input("./6in.txt");
    string text;
    input >> text;

    for (int i = 3; i < text.length(); i++) {
        set<char> chars = { text[i], text[i-1], text[i-2], text[i-3] };
        if (chars.size() == 4) {
            cout << i + 1 << endl;
            break;
        }
    }
}