#include "Stronghold.h"

Military::Military() {
    troopCount = 25;
    combatSpirit = 65;
    rations = 120;
}

void Military::enlistSoldiers(Citizens& kingdomPeople) {
    cout << "\n=== Military Recruitment Drive ===\n";

    int newRecruits;
    cout << "How many citizens to enlist? ";
    cin >> newRecruits;

    if (newRecruits <= 0 || newRecruits > kingdomPeople.getPopulation()) {
        cout << "Invalid recruitment number.\n";
        return;
    }

    int foodNeeded = newRecruits * 3;
    if (rations < foodNeeded) {
        cout << "Insufficient supplies for " << newRecruits << " recruits!\n";
        combatSpirit -= 15;
        return;
    }

    kingdomPeople.reducePopulation(newRecruits);
    troopCount += newRecruits;
    rations -= foodNeeded;
    combatSpirit += 8;

    combatSpirit = (combatSpirit > 100) ? 100 : combatSpirit;
    combatSpirit = (combatSpirit < 0) ? 0 : combatSpirit;

    cout << newRecruits << " new troops joined the ranks.\n";
    cout << "Supplies consumed: " << foodNeeded << " rations\n";
    cout << "Current troop spirit: " << combatSpirit << "%\n";
}

void Military::displayStrength() const {
    cout << "\n=== Military Overview ===\n";
    cout << "Active Troops: " << troopCount << endl;
    cout << "Unit Morale: " << combatSpirit << "%\n";
    cout << "Remaining Rations: " << rations << endl;
}

void Military::saveGame() const {
    ofstream militaryFile("forces.dat");
    if (!militaryFile) {
        cout << "Failed to save military records!\n";
        return;
    }

    militaryFile << troopCount << endl
        << combatSpirit << endl
        << rations;
    militaryFile.close();
    cout << "Military records archived.\n";
}

void Military::loadGame() {
    ifstream militaryFile("forces.dat");
    if (!militaryFile) {
        cout << "No military records found!\n";
        return;
    }

    militaryFile >> troopCount >> combatSpirit >> rations;
    militaryFile.close();
    cout << "Military records restored.\n";
}

void Military::demoralize(int loss) {
    combatSpirit -= loss;
    if (combatSpirit < 0) combatSpirit = 0;
    if (combatSpirit > 100) combatSpirit = 100;
}

int Military::getTroopCount() const {
    return troopCount;
}