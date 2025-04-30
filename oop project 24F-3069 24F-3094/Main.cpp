#include <iostream>
#include "Stronghold.h"

using namespace std;

int main() {
    Citizens kingdomPopulation;
    Military royalForces;
    Finance kingdomTreasury;
    Materials kingdomResources;
    Ruler* sovereign = new Monarch();
    RandomEvents kingdomEvents;
    CentralBank royalBank;

    int menuSelection;
    bool continueGame = true;

    while (continueGame) {
        cout << "\n KINGDOM MANAGEMENT SYSTEM " << endl;
        cout << "1. View Status" << endl;
        cout << "2. Process Population Changes" << endl;
        cout << "3. Conduct Military Recruitment" << endl;
        cout << "4. Manage Royal Finances" << endl;
        cout << "5. Oversee Resources" << endl;
        cout << "6. Simulate Kingdom Events" << endl;
        cout << "7. Save Kingdom Progress" << endl;
        cout << "8. Load Previous Session" << endl;
        cout << "9. Abdicate Throne (Exit)" << endl;
        cout << endl;
        cout << "Your command: ";
        cin >> menuSelection;

        if (cin.fail() || menuSelection < 1 || menuSelection > 9) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid command! Please choose 1-9." << endl;
            continue;
        }

        switch (menuSelection) {
        case 1:
            kingdomPopulation.displayDemographics();
            royalForces.displayStrength();
            kingdomTreasury.displayFinances();
            kingdomResources.displayStocks();
            royalBank.displayBankStatus();
            break;

        case 2:
            kingdomPopulation.updatePopulation();
            break;

        case 3:
            royalForces.enlistSoldiers(kingdomPopulation);
            break;

        case 4:
            kingdomTreasury.collectTaxes(kingdomPopulation);
            royalBank.inspectBooks(kingdomTreasury);
            break;

        case 5:
            kingdomResources.updateResources();
            break;

        case 6:
            kingdomEvents.triggerEvent(kingdomPopulation, royalForces,
                kingdomTreasury, kingdomResources);
            break;

        case 7:
            kingdomPopulation.saveGame();
            royalForces.saveGame();
            kingdomTreasury.saveGame();
            kingdomResources.saveGame();
            royalBank.saveGame();
            break;

        case 8:
            kingdomPopulation.loadGame();
            royalForces.loadGame();
            kingdomTreasury.loadGame();
            kingdomResources.loadGame();
            royalBank.loadGame();
            break;

        case 9:
            continueGame = false;
            break;
        }
    }

    delete sovereign;
    cout << "\nExit Game. You have left your kingdom in our hands. May it prosper!\n";
    return 0;
}