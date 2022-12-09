#include <iostream>
#include <fstream>
#include <set>
#include <map>
using namespace std;

struct Point {
    int x;
    int y;
};

Point follow(const Point head, Point tail) {
    if (abs(head.x - tail.x) <= 1 && abs(head.y - tail.y) <= 1) {
        return tail;
    }

    if (head.x > tail.x) {
        tail.x++;
    }
    else if (head.x < tail.x) {
        tail.x--;
    }

    if (head.y > tail.y) {
        tail.y++;
    }
    else if (head.y < tail.y) {
        tail.y--;
    }

    return tail;
}

bool operator <(const Point& p1, const Point& p2) {
    if (p1.x != p2.x) {
        return p1.x < p2.x;
    }
    else {
        return p1.y < p2.y;
    }
}

int main() {
    ifstream input("./9in.txt");

    char direction;
    int amount;

    Point head = {0, 0};
    Point tail = {0, 0};

    set<Point> positions = {tail};
    map<char, pair<int, int>> directions = {
        {'U', {0, 1}},
        {'D', {0, -1}},
        {'L', {-1, 0}},
        {'R', {1, 0}}
    };

    while (input >> direction >> amount) {
        for (int i = 0; i < amount; i++) {
            head.x += directions[direction].first;
            head.y += directions[direction].second;
            tail = follow(head, tail);
            positions.insert(tail);
        }
    }

    cout << "Part 1: " << positions.size() << endl;

    return 0;
}