#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

class Monkey {
  private:
    vector<int> items;
    char op;
    string val;
    int testDivisor;
    int trueMonkeyId;
    int falseMonkeyId;
    int inspections;
    
    void inspectItems() {
        for (int i = 0; i < this->items.size(); i++) {
            int num = this->val != "old"
                ? stoi(this->val)
                : items[i];

            if (this->op == '+') {
                this->items[i] += num;
            }
            else if (this->op == '*') {
                this->items[i] *= num;
            }

            inspections++;
        }
    }

    void testItems(vector<Monkey*> monkeys) {
        for (int item : this->items) {
            // Check if divisible
            int recipientMonkeyId = item % this->testDivisor == 0
                ? this->trueMonkeyId
                : this->falseMonkeyId;
            
            monkeys[recipientMonkeyId]->addItem(item);
        }

        this->items.clear();
    }

  public:
    Monkey(vector<int> items, char op, string val, int testDivisor, int trueMonkeyId, int falseMonkeyId) {
        this->items = items;
        this->op = op;
        this->val = val;
        this->testDivisor = testDivisor;
        this->trueMonkeyId = trueMonkeyId;
        this->falseMonkeyId = falseMonkeyId;
        this->inspections = 0;
    }

    void goMonkeyMode(vector<Monkey*> monkeys) {
        this->inspectItems();
        this->testItems(monkeys);
    }

    void addItem(int item) {
        this->items.push_back(item);
    }

    int getTotalInspections() {
        return this->inspections;
    }
};

namespace MonkeyManager {
    int calculateMonkeyBusiness(vector<Monkey*> monkeys) {
        vector<int> inspectionCounts;
        for (const auto& monkey : monkeys) {
            inspectionCounts.push_back(monkey->getTotalInspections());
        }
        
        sort(inspectionCounts.begin(), inspectionCounts.end(), greater<int>());

        return inspectionCounts[0] * inspectionCounts[1];
    }

    void play(int rounds, vector<Monkey*> monkeys) {
        for (int i = 0; i < rounds; i++) {
            for (const auto& monkey : monkeys) {
                monkey->goMonkeyMode(monkeys);
            }
        }
    }
}

// Use regex to parse input
const string regExpr = "Monkey \\d+:\n\
  Starting items: ([\\d|,| ]+)\n\
  Operation: new = old (.) (\\w+)\n\
  Test: divisible by (\\d+)\n\
    If true: throw to monkey (\\d+)\n\
    If false: throw to monkey (\\d+)";

int main() {
    ifstream input("11in.txt");
    string in(istreambuf_iterator<char>(input), {});

    regex r(regExpr);
    smatch match;

    vector<Monkey*> monkeys;

    while (regex_search(in, match, r)) {
        vector<int> items;

        regex digR("\\d+");
        smatch digMatch;
        string numsList = match[1];

        while (regex_search(numsList, digMatch, digR)) {
            items.push_back(stoi(digMatch[0]));
        }

        monkeys.push_back(new Monkey(items, match[2].str()[0], match[3], stoi(match[4]), stoi(match[5]), stoi(match[6])));

        in = match.suffix().str();

        cout << match[0];
    }

    MonkeyManager::play(20, monkeys);

    cout << "Part 1: " << MonkeyManager::calculateMonkeyBusiness(monkeys) << '\n';

    return 0;
}