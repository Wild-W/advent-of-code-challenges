#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <numeric>
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

        int lower1 = stoi(match[1]),
            upper1 = stoi(match[2]),
            lower2 = stoi(match[3]),
            upper2 = stoi(match[4]);

        vector<int> range1(upper1 - lower1 + 1);
        iota(range1.begin(), range1.end(), lower1);

        for (int i = lower2; i <= upper2; i++) {
            if (find(range1.begin(), range1.end(), i) != range1.end()) {
                count++;
                break;
            }
        }
    }

    cout << count << endl;

    return 0;
}