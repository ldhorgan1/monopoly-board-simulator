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

        {"GO", "None", "0", "0"},

        {"Boston Cream Pie", "Brown", "60", "2"},
        {"Community Chest", "None", "0", "0"},
        {"North End", "Brown", "60", "4"},

        {"Income Tax", "None", "0", "0"},
        {"MBTA Red Line", "Railroad", "200", "25"},

        {"Fenway Park", "Light Blue", "100", "6"},
        {"Chance", "None", "0", "0"},
        {"Newbury Street", "Light Blue", "100", "6"},
        {"Beacon Hill", "Light Blue", "120", "8"},

        {"Jail / Just Visiting", "None", "0", "0"},

        {"South End", "Pink", "140", "10"},
        {"Electric Company", "Utility", "150", "10"},
        {"Back Bay", "Pink", "140", "10"},
        {"Seaport District", "Pink", "160", "12"},

        {"MBTA Green Line", "Railroad", "200", "25"},

        {"Boston Public Garden", "Orange", "180", "14"},
        {"Community Chest", "None", "0", "0"},
        {"Harvard Square", "Orange", "180", "14"},
        {"Quincy Market", "Orange", "200", "16"},

        {"Free Parking", "None", "0", "0"},

        {"MIT", "Red", "220", "18"},
        {"Chance", "None", "0", "0"},
        {"TD Garden", "Red", "220", "18"},
        {"Boston Harbor", "Red", "240", "20"},

        {"MBTA Blue Line", "Railroad", "200", "25"},

        {"Prudential Center", "Yellow", "260", "22"},
        {"Faneuil Hall", "Yellow", "260", "22"},
        {"Water Works", "Utility", "150", "10"},
        {"Copley Square", "Yellow", "280", "24"},

        {"Go To Jail", "None", "0", "0"},

        {"Logan Airport", "Green", "300", "26"},
        {"Boston Common", "Green", "300", "26"},
        {"Community Chest", "None", "0", "0"},
        {"Massachusetts State House", "Green", "320", "28"},

        {"MBTA Orange Line", "Railroad", "200", "25"},

        {"Chance", "None", "0", "0"},
        {"Gillette Stadium", "Dark Blue", "350", "35"},
        {"The Freedom Trail", "Tax", "0", "0"},
        {"Boston City Hall", "Dark Blue", "400", "50"}
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
        s.name = "" ;
        s.color = "";
        s.value = "0";
        s.rent = "0";

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