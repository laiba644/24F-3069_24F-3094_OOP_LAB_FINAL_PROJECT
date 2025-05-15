#include <iostream>
#include "Stronghold.h"

using namespace std;

int main() {
    Kingdom kingdom1("Eldoria");
    Kingdom kingdom2("Valthor");
    Communication comm;
    Diplomacy dip;
    Trade trade;
    Conflict conflict;
    Map map;
    RandomEvents events;

    bool isEldoriaTurn = true;
    bool running = true;

    // Initialize kingdom positions
    cout << "Setting initial kingdom positions...\n";
    map.setPosition(kingdom1, 0, 4); // Eldoria at (0,4)
    map.setPosition(kingdom2, 7, 4); // Valthor at (7,4)
    cout << "Initial positions set. Select 'View Map' to confirm.\n";

    while (running) {
        Kingdom& currentKingdom = isEldoriaTurn ? kingdom1 : kingdom2;
        Kingdom& otherKingdom = isEldoriaTurn ? kingdom2 : kingdom1;
        string currentName = currentKingdom.getName();

        cout << "\n=== " << currentName << "'s Turn ===\n";
        cout << "1. View Kingdom Status\n";
        cout << "2. Send Message\n";
        cout << "3. Manage Diplomacy\n";
        cout << "4. Conduct Trade\n";
        cout << "5. Initiate Conflict\n";
        cout << "6. View Map\n";
        cout << "7. Simulate Events\n";
        cout << "8. Move Kingdom\n";
        cout << "9. Save Game\n";
        cout << "10. Load Game\n";
        cout << "11. End Turn\n";
        cout << "12. Exit Game\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 12) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        switch (choice) {
        case 1:
            currentKingdom.displayStatus();
            otherKingdom.displayStatus();
            break;
        case 2: {
            string msg, to;
            cout << "To (" << otherKingdom.getName() << "): "; cin >> to;
            cin.ignore();
            cout << "Message: "; getline(cin, msg);
            if (to == otherKingdom.getName())
                comm.sendMessage(currentKingdom, otherKingdom, msg);
            else
                cout << "Invalid recipient.\n";
            break;
        }
        case 3: {
            int dipChoice;
            cout << "1. Form Alliance\n2. Form Treaty\n3. Declare War\n4. Break Alliance\n";
            cin >> dipChoice;
            if (dipChoice == 1)
                dip.formAlliance(currentKingdom, otherKingdom);
            else if (dipChoice == 2)
                dip.formTreaty(currentKingdom, otherKingdom);
            else if (dipChoice == 3)
                dip.declareWar(currentKingdom, otherKingdom);
            else if (dipChoice == 4)
                dip.breakAlliance(currentKingdom, otherKingdom);
            else
                cout << "Invalid choice.\n";
            break;
        }
        case 4: {
            string res;
            int qty, cost;
            bool smuggle;
            cout << "Resource (grain/lumber/marble/steel): "; cin >> res;
            cout << "Quantity: "; cin >> qty;
            cout << "Cost: "; cin >> cost;
            cout << "Smuggle (0/1): "; cin >> smuggle;
            trade.initiateTrade(currentKingdom, otherKingdom, res, qty, cost, smuggle);
            break;
        }
        case 5:
            conflict.initiateAttack(currentKingdom, otherKingdom);
            break;
        case 6:
            map.displayMap();
            break;
        case 7:
            events.triggerEvent(currentKingdom.getCitizens(), currentKingdom.getMilitary(),
                currentKingdom.getFinance(), currentKingdom.getMaterials());
            break;
        case 8: {
            int newRow, newCol;
            cout << "Enter new row (0-8): "; cin >> newRow;
            cout << "Enter new column (0-8): "; cin >> newCol;
            map.moveKingdom(currentKingdom, newRow, newCol);
            break;
        }
        case 9:
            kingdom1.saveGame();
            kingdom2.saveGame();
            cout << "Game saved for both kingdoms.\n";
            break;
        case 10:
            kingdom1.loadGame();
            kingdom2.loadGame();
            cout << "Game loaded for both kingdoms.\n";
            break;
        case 11:
            isEldoriaTurn = !isEldoriaTurn;
            cout << currentName << " ends turn. Now it's " << (isEldoriaTurn ? "Eldoria" : "Valthor") << "'s turn.\n";
            break;
        case 12:
            running = false;
            break;
        }
    }

    cout << "\nGame Ended. Kingdoms stand eternal.\n";
    return 0;
}