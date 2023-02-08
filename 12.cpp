#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

struct Point {
    int row;
    int column;

    bool operator ==(const Point other) const {
        return this->row == other.row && this->column == other.column;
    }
    
    bool operator <(const Point other) const {
        return sqrt(row*row + column*column) < sqrt(other.row*other.row + other.column*other.column);
    }
};

static int lowestStepCount = INT_MAX;
static map<Point, int> memoedResults = {};

int getLowestStepsToFinish(Point current, Point finish, vector<vector<char>> grid, int steps = 0, vector<Point> beenTo = {}) {
    if (lowestStepCount <= steps) {
        cout <<"Path went over max of " << lowestStepCount << ".\n";
        return INT_MAX;
    }

    if (memoedResults.find(current) != memoedResults.end()) return memoedResults[current] + steps;

    vector<int> stepResults = {INT_MAX};

    for (int i = 0; i < 4; i++) {
        Point next = {};
        
        switch (i) {
            case 0: next = {current.row + 1, current.column}; break;
            case 1: next = {current.row - 1, current.column}; break;
            case 2: next = {current.row, current.column + 1}; break;
            case 3: next = {current.row, current.column - 1}; break;
        }

        // Make sure coordinate is not out of bounds
        if (next.row < 0 || next.row >= grid.size() || next.column < 0 || next.column >= grid[0].size()) continue;

        // Make sure we haven't already dealt with this tile
        if (find(beenTo.begin(), beenTo.end(), next) != beenTo.end()) continue;

        // Make sure step is not too high
        if (grid[next.row][next.column] > grid[current.row][current.column] + 1) continue;

        // If we get to the end, return total steps and set new lowest
        if (next == finish) {
            lowestStepCount = steps + 1;
            cout <<"Got to end in " << steps + 1 << " steps.\n";
            return steps + 1;
        }

        beenTo.push_back(current);
        stepResults.push_back(getLowestStepsToFinish(next, finish, grid, steps + 1, beenTo));
    }

    int minSteps = *min_element(stepResults.begin(), stepResults.end());

    if (minSteps == INT_MAX) return INT_MAX;
    memoedResults[current] = minSteps - steps;
    return minSteps;
}

int main() {
    ifstream input("12in.txt");

    char ch;
    int row = 0;
    int column = 0;

    vector<vector<char>> grid = {{}};
    Point start = {0, 0};
    Point finish = {0, 0};

    while (input.get(ch)) {
        if (ch == '\n') {
            grid.push_back({});
            column = 0;
            row++;
            continue;
        }
        else if (ch == 'S') {
            start = {row, column};
            grid[row].push_back('a');
        }
        else if (ch == 'E') {
            finish = {row, column};
            grid[row].push_back('z');
        }
        else {
            grid[row].push_back(ch);
        }

        column++;
    }

    cout << "Part 1: " << getLowestStepsToFinish(start, finish, grid) << endl;
}