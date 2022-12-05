#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <deque>
using namespace std;

int main() {
    ifstream input;
    input.open("./5in.txt");

    string line;
    vector<deque<char>> crates = {};
    bool firstLine = true;

    // Set up crates
    while (getline(input, line)) {
        if (line.rfind(" 1", 0) == 0) {
            getline(input, line);
            break;
        }
        for (int i = 1; i < line.length() - 1; i += 4) {
            int index = (i - 1) / 4;
            if (firstLine) {
                crates.push_back({});
            }

            if (line[i] != ' ') {
                crates[index].push_back(line[i]);
            }
        }
        firstLine = false;
    }

    regex moveR("move (\\d+) from (\\d) to (\\d)");

    // Follow instructions
    while (getline(input, line)) {
        smatch match;
        regex_search(line, match, moveR);

        int column = stoi(match[2]) - 1;

        for (int i = 0; i < stoi(match[1]); i++) {
            crates[stoi(match[3]) - 1].push_front(crates[column].front());
            crates[column].pop_front();
        }
    }

    // Get answer
    for (int i = 0; i < crates.size(); i++) {
        char top = crates[i].front();
        if (top) {
            cout << top;
        }
    }
    cout << endl;

    return 0;
}