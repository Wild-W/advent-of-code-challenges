#include <iostream>
#include <fstream>
#include <string>
#define PIXELS 40
using namespace std;

void draw(string* screen, int x, int cycle) {
    if (x == cycle || x - 1 == cycle || x + 1 == cycle) {
        (*screen)[cycle] = '#';
    }
}

int main() {
    ifstream input("./10in.txt");

    int x = 1;
    int cycle = 0;

    for (int i = 0; i < 6; i++) {
        // Screen to draw to, instantiate with spaces for empty pixels
        string screen(PIXELS, ' ');

        while (cycle < 40) {
            string instruction;
            input >> instruction;
            
            // Takes 2 cycles to complete
            if (instruction == "addx") {
                int num;
                input >> num;

                draw(&screen, x, cycle);
                cycle++;

                draw(&screen, x, cycle);
                cycle++;
                x += num;
            }
            // Instruction is `noop` (no op), one cycle to complete
            else {
                draw(&screen, x, cycle);
                cycle++;
            }
        }
        
        cycle -= 40;
        cout << screen << '\n';
    }

    return 0;
}