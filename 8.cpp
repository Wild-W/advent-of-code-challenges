#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeStat {
    bool visible;
    int score;
};

TreeStat getTreeStat(vector<vector<int>> grid, int y, int x) {
    bool downVis = true;
    int downCount = 0;
    for (int i = y + 1; i < grid.size(); i++) {
        downCount++;
        if (grid[i][x] >= grid[y][x]) {
            downVis = false;
            break;
        }
    }

    bool upVis = true;
    int upCount = 0;
    for (int i = y - 1; i >= 0; i--) {
        upCount++;
        if (grid[i][x] >= grid[y][x]) {
            upVis = false;
            break;
        }
    }

    bool rightVis = true;
    int rightCount = 0;
    for (int i = x + 1; i < grid.size(); i++) {
        rightCount++;
        if (grid[y][i] >= grid[y][x]) {
            rightVis = false;
            break;
        }
    }

    bool leftVis = true;
    int leftCount = 0;
    for (int i = x - 1; i >= 0; i--) {
        leftCount++;
        if (grid[y][i] >= grid[y][x]) {
            leftVis = false;
            break;
        }
    }

    return TreeStat {
        downVis || upVis || rightVis || leftVis,
        downCount * upCount * rightCount * leftCount
    };
}

int main() {
    ifstream input("./8in.txt");

    string line;
    vector<vector<int>> grid;
    int y = 0;

    // Set up grids
    while (getline(input, line)) {
        grid.push_back({});
        for (char c : line) {
            grid[y].push_back(c - '0');
        }
        y++;
    }

    // Determine visible trees and scenic score
    int count = 0;
    int maxScore = 0;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < y; j++) {
            TreeStat treeStat = getTreeStat(grid, i, j);
            if (treeStat.visible) {
                count++;
            }
            if (treeStat.score > maxScore) {
                maxScore = treeStat.score;
            }
        }
    }

    // Answers
    cout << "Part 1: " << count << '\n'
         << "Part 2: " << maxScore << endl;

    return 0;
}