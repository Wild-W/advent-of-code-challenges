#include <iostream>
#include <fstream>
#include <regex>
#include <string>
using namespace std;

int main() {
    ifstream input;
    input.open("./4in.txt");

    string line;
    regex r("(\\d+)-(\\d+),(\\d+)-(\\d+)");
    int count = 0;

    while (input >> line) {
        smatch match;
        regex_search(line, match, r);

        if ((stoi(match[1]) <= stoi(match[3]) && stoi(match[2]) >= stoi(match[4]))
            || 
            (stoi(match[3]) <= stoi(match[1]) && stoi(match[4]) >= stoi(match[2]))) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}