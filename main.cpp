#include <iostream>
#include <vector>
#include "Board.h"
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
        Space("GO", "None", 0, 0),

        Space("Boston Cream Pie", "Brown", 60, 2),
        Space("Community Chest", "None", 0, 0),
        Space("North End", "Brown", 60, 4),

        Space("Income Tax", "None", 0, 0),
        Space("MBTA Red Line", "Railroad", 200, 25),

        Space("Fenway Park", "Light Blue", 100, 6),
        Space("Chance", "None", 0, 0),
        Space("Newbury Street", "Light Blue", 100, 6),
        Space("Beacon Hill", "Light Blue", 120, 8),

        Space("Jail / Just Visiting", "None", 0, 0),

        Space("South End", "Pink", 140, 10),
        Space("Electric Company", "Utility", 150, 10),
        Space("Back Bay", "Pink", 140, 10),
        Space("Seaport District", "Pink", 160, 12),

        Space("MBTA Green Line", "Railroad", 200, 25),

        Space("Boston Public Garden", "Orange", 180, 14),
        Space("Community Chest", "None", 0, 0),
        Space("Harvard Square", "Orange", 180, 14),
        Space("Quincy Market", "Orange", 200, 16),

        Space("Free Parking", "None", 0, 0),

        Space("MIT", "Red", 220, 18),
        Space("Chance", "None", 0, 0),
        Space("TD Garden", "Red", 220, 18),
        Space("Boston Harbor", "Red", 240, 20),

        Space("MBTA Blue Line", "Railroad", 200, 25),

        Space("Prudential Center", "Yellow", 260, 22),
        Space("Faneuil Hall", "Yellow", 260, 22),
        Space("Water Works", "Utility", 150, 10),
        Space("Copley Square", "Yellow", 280, 24),

        Space("Go To Jail", "None", 0, 0),

        Space("Logan Airport", "Green", 300, 26),
        Space("Boston Common", "Green", 300, 26),
        Space("Community Chest", "None", 0, 0),
        Space("Massachusetts State House", "Green", 320, 28),

        Space("MBTA Orange Line", "Railroad", 200, 25),

        Space("Chance", "None", 0, 0),
        Space("Gillette Stadium", "Dark Blue", 350, 35),
        Space("The Freedom Trail", "Tax", 0, 0),
        Space("Boston City Hall", "Dark Blue", 400, 50)
    };


    b.addMany(spaces);


    cout << "\n== Playable Simulation (10 turns) ===\n";

    for (int turn = 1; turn <= 10; turn++) {
        int roll = rollDice2to12();

        cout << "\nTurn " << turn << " | Rolled: " << roll << "\n";

        b.move(roll);

        cout << "Board view from player (next 5 spaces):\n";
        b.printFromCurrent(5);
        cout << "Times passed GO so far: " << b.getGoPasses() << "\n";
    }

    return 0;
}