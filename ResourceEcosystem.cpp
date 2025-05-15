#include "Stronghold.h"

Materials::Materials() {
    grain = 500;
    lumber = 300;
    marble = 200;
    steel = 100;
}

void Materials::updateResources() {
    cout << "\n=== Materials Management ===" << endl;
    cout << "1. Acquire Resources" << endl;
    cout << "2. Use Resources" << endl;

    int selection;
    cin >> selection;

    switch (selection) {
    case 1: harvestMaterials(); break;
    case 2: useMaterials(); break;
    default: cout << "Invalid selection." << endl;
    }
}

void Materials::harvestMaterials() {
    int grainAdd, lumberAdd, marbleAdd, steelAdd;

    cout << "\nEnter quantities to gather:" << endl;
    cout << "Grain: "; cin >> grainAdd;
    cout << "Lumber: "; cin >> lumberAdd;
    cout << "Marble: "; cin >> marbleAdd;
    cout << "Steel: "; cin >> steelAdd;

    if (grainAdd < 0 || lumberAdd < 0 || marbleAdd < 0 || steelAdd < 0) {
        cout << "Cannot gather negative amounts." << endl;
        return;
    }

    grain += grainAdd;
    lumber += lumberAdd;
    marble += marbleAdd;
    steel += steelAdd;

    cout << "Resources successfully added." << endl;
}

void Materials::useMaterials() {
    int grainUse, lumberUse, marbleUse, steelUse;
    cout << "\nEnter quantities to consume:" << endl;
    cout << "Grain: "; cin >> grainUse;
    cout << "Lumber: "; cin >> lumberUse;
    cout << "Marble: "; cin >> marbleUse;
    cout << "Steel: "; cin >> steelUse;
    try {
        if (grainUse < 0 || lumberUse < 0 || marbleUse < 0 || steelUse < 0) {
            throw std::invalid_argument("Cannot use negative amounts.");
        }
        if (grain < grainUse || lumber < lumberUse || marble < marbleUse || steel < steelUse) {
            throw std::invalid_argument("Not enough resources available.");
        }
        grain -= grainUse;
        lumber -= lumberUse;
        marble -= marbleUse;
        steel -= steelUse;
        cout << "Resources deducted successfully." << endl;
    }
    catch (const std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void Materials::displayStocks() const {
    cout << "\n=== Current Stockpile ===" << endl;
    cout << "Grain: " << grain << endl;
    cout << "Lumber: " << lumber << endl;
    cout << "Marble: " << marble << endl;
    cout << "Steel: " << steel << endl;
}

void Materials::saveGame() const {
    ofstream outFile("materials.dat");
    if (!outFile) {
        cout << "Error saving resource data." << endl;
        return;
    }

    outFile << grain << endl << lumber << endl << marble << endl << steel;
    outFile.close();
    cout << "Resource data saved." << endl;
}

void Materials::loadGame() {
    ifstream inFile("materials.dat");
    if (!inFile) {
        cout << "Error loading resource data." << endl;
        return;
    }

    inFile >> grain >> lumber >> marble >> steel;
    inFile.close();
    cout << "Resource data loaded." << endl;
}

void Materials::consumeResource(string type, int amount) {
    if (type == "grain" && grain >= amount) {
        grain -= amount;
    }
    else if (type == "lumber" && lumber >= amount) {
        lumber -= amount;
    }
    else if (type == "marble" && marble >= amount) {
        marble -= amount;
    }
    else if (type == "steel" && steel >= amount) {
        steel -= amount;
    }
    else {
        cout << "Insufficient " << type << " available." << endl;
    }
}

int Materials::getResource(string type) const {
    if (type == "grain") return grain;
    if (type == "lumber") return lumber;
    if (type == "marble") return marble;
    if (type == "steel") return steel;
    return 0;
}

void Materials::addResource(string type, int amount) {
    if (type == "grain") grain += amount;
    else if (type == "lumber") lumber += amount;
    else if (type == "marble") marble += amount;
    else if (type == "steel") steel += amount;
}