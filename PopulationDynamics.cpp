#include "Stronghold.h"

Citizens::Citizens() {
    totalPeople = 100;
    farmers = 60;
    traders = 25;
    elites = 15;
    approvalRating = 70.0;
    foodReserves = 300;
}

void Citizens::updatePopulation() {
    cout << "\n=== Annual Population Report ===\n";

    const int FOOD_PER_PERSON = 2;
    int neededFood = totalPeople * FOOD_PER_PERSON;

    cout << "Current residents: " << totalPeople << endl;
    cout << "Food demand: " << neededFood << endl;
    cout << "Food stores: " << foodReserves << endl;

    if (foodReserves >= neededFood) {
        cout << "Harvest was plentiful. Population increases.\n";
        foodReserves -= neededFood;
        totalPeople += 8 + rand() % 5;
        approvalRating += 4;
    }
    else {
        int missingFood = neededFood - foodReserves;
        cout << missingFood << " food units short! Famine strikes.\n";

        int casualties = missingFood / FOOD_PER_PERSON;
        totalPeople -= casualties;
        approvalRating -= 12;
        foodReserves = 0;

        cout << casualties << " perished from starvation.\n";
    }

    approvalRating = (approvalRating > 100) ? 100 : (approvalRating < 0) ? 0 : approvalRating;
    totalPeople = (totalPeople < 0) ? 0 : totalPeople;

    farmers = totalPeople * 0.6;
    traders = totalPeople * 0.25;
    elites = totalPeople * 0.15;

    if (approvalRating < 30) {
        cout << "DANGER: Civil unrest growing!\n";
        int riotDeaths = 3 + rand() % 8;
        totalPeople -= riotDeaths;
        cout << riotDeaths << " died in violent protests.\n";
    }
}

void Citizens::displayDemographics() const {
    cout << "\n=== Kingdom Demographics ===" << endl;
    cout << "Total Citizens: " << totalPeople << endl;
    cout << " Field Workers: " << farmers << endl;
    cout << " Marketplace Vendors: " << traders << endl;
    cout << " Aristocracy: " << elites << endl;
    cout << " Public Approval: " << approvalRating << "%" << endl;
}

void Citizens::saveGame() const {
    ofstream dataFile("citizens.dat");
    if (!dataFile) {
        cout << "Failed to save demographic records.\n";
        return;
    }

    dataFile << totalPeople << endl
        << farmers << endl
        << traders << endl
        << elites << endl
        << approvalRating;
    dataFile.close();
    cout << "Population records archived.\n";
}

void Citizens::loadGame() {
    ifstream dataFile("citizens.dat");
    if (!dataFile) {
        cout << "No saved demographic data found.\n";
        return;
    }

    dataFile >> totalPeople >> farmers >> traders >> elites >> approvalRating;
    dataFile.close();
    cout << "Population records restored.\n";
}

int Citizens::getPopulation() const {
    return totalPeople;
}

void Citizens::reducePopulation(int numLost) {
    totalPeople = (totalPeople - numLost > 0) ? totalPeople - numLost : 0;
    farmers = totalPeople * 0.6;
    traders = totalPeople * 0.25;
    elites = totalPeople * 0.15;
}