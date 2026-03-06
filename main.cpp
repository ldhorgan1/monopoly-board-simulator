#include <iostream>
#include <vector>
#include "Board.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int rollDice2to12() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
    srand((unsigned)time(nullptr));
    Board b;

    vector<Space> spaces = {
        {"GO", "", "GO"},
        {"Boston Cream Pie", "Red", "Property"},
        {"Community Cest", "", "Chest"},
        {"The T", "Red", "Property"},
        {"Property Tax", "", "Tax"}
    };
    cout << "Added: " << b.addMany(spaces) << "\n";
    cout << "\nRemoving 'The T'...\n";
    cout << (b.removeByName("The T") ? "Removed!" : "Not Found!") << "\n";
    cout << "Size now: " << b.getSize() << "\n";
    b.printFromCurrent(10);
    cout << "Current board size: " << b.getSize() << "\n";
    cout << "\nFinding Red properties:\n";
    vector<string> reds = b.findByColor("Red");

    for (const auto& name : reds) {
        cout << name << "\n";
    }
    int before = b.getSize();
    for (int i = before; i < 45; i++) {
        Space s;
        s.name = "Space " + to_string(i);
        s.color = "";
        s.type = "Test";

        bool ok = b.addSpace(s);
        if (!ok) {
            cout << "Rejected insertion at size " << b.getSize()
            << " (expected at 40)\n";
            break;
        }
    }

    cout << "Final board size: " << b.getSize() << " (should be 40)\n";

    cout << "\nTraversal check (print 50 spaces):\n";
    b.printFromCurrent(50);


    cout << "\n== Playable Simulation (10 turns) ===\n";
    for (int turn =1; turn <= 10; turn++) {
        int roll = rollDice2to12();
        b.move(roll);

        Space landed = b.getCurrentSpace();
        cout << "Turn " << turn
        << " rolled " << roll
        << " landed on " << landed.name
        << " | GO passes: " << b.getGoPasses()
        << "\n";
    }
    return 0;

}