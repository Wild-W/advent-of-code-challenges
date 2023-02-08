#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void check(const int cycle, const int x, int* sum) {
    if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220) {
        cout << x * cycle << '\n';
        *sum += x * cycle;
    }
}

int main() {
    ifstream input("./10in.txt");

    string instruction;
    int cycle = 0;
    int x = 1;
    int sum = 0;

    while ((input >> instruction) && cycle <= 220) {
        if (instruction == "addx") {
            int num;
            input >> num;

            cycle++;
            check(cycle, x, &sum);

            cycle++;
            check(cycle, x, &sum);
            x += num;
        }
        else {
            cycle++;
            check(cycle, x, &sum);
        }
    }

    cout << sum << endl;
}
