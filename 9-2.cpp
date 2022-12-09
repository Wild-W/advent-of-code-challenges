#include <fstream>
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Knot {
  private:
    Knot* next;
    int x;
    int y;
    set<pair<int, int>> positions;

    void cont() {
        if (this->next) {
            this->next->follow(this->x, this->y);
        }
        else {
            this->positions.insert({this->x, this->y});
        }
    }

  public:
    static map<char, pair<int, int>> directions;

    Knot(int amount) {
        this->x = 0;
        this->y = 0;

        if (amount > 0) {
            this->next = new Knot(amount - 1);
        }
        else {
            this->next = nullptr;
            this->positions = {{0, 0}};
        }
    }

    void move(char direction, int amount) {
        for (int i = 0; i < amount; i++) {
            this->x += directions[direction].first;
            this->y += directions[direction].second;

            if (this->next) {
                this->next->follow(this->x, this->y);
            }
        }
    }

    void follow(const int x, int y) {
        if (abs(x - this->x) <= 1 && abs(y - this->y) <= 1) {
            return;
        }

        if (x > this->x) {
            this->x++;
        }
        else if (x < this->x) {
            this->x--;
        }

        if (y > this->y) {
            this->y++;
        }
        else if (y < this->y) {
            this->y--;
        }

        this->cont();
    }

    int getUniqueTailPositions() {
        if (this->next) {
            return this->next->getUniqueTailPositions();
        }
        return this->positions.size();
    }
};

map<char, pair<int, int>> Knot::directions = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}}
};

int main() {
    ifstream input("./9in.txt");

    char direction;
    int amount;

    // Generate a rope with 1 head knot + 9 tailing knots
    Knot* head = new Knot(9);

    while (input >> direction >> amount) {
        head->move(direction, amount);
    }

    // Print the amount of total positions the tail of the rope has been
    cout << "Part 2: " << head->getUniqueTailPositions() << endl;

    return 0;
}