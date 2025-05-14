#include "Stronghold.h"

Finance::Finance() {
    goldReserves = 1200;
    taxPercent = 6;
    priceRise = 100;
}

void Finance::collectTaxes(const Citizens& populace) {
    cout << "\n=== Tax Season ===\n";

    int citizenCount = populace.getPopulation();
    int baseTax = (citizenCount * taxPercent) / 100;
    int actualTax = (baseTax * priceRise) / 100;

    goldReserves += actualTax;

    cout << "Collected taxes from " << citizenCount << " subjects\n";
    cout << "Revenue: " << actualTax << " gold coins\n";
    cout << "Treasury now holds: " << goldReserves << " gold\n";

    priceRise += 4;
    if (priceRise > 250) priceRise = 250;
}

void Finance::makePayment(int cost) {
    cout << "\n=== Treasury Disbursement ===\n";

    if (cost <= 0) {
        cout << "Payment rejected - invalid amount.\n";
        return;
    }

    if (cost > goldReserves) {
        cout << "Payment failed - only " << goldReserves << " gold available.\n";
        return;
    }

    goldReserves -= cost;
    cout << "Paid " << cost << " gold. Remaining: " << goldReserves << endl;
}

void Finance::displayFinances() const {
    cout << "\n=== Kingdom Finances ===" << endl;
    cout << "Treasury: " << goldReserves << " gold coins" << endl;
    cout << "Tax Rate: " << taxPercent << "% per citizen" << endl;
    cout << "Inflation: " << priceRise << "% (x" << priceRise / 100.0 << ")" << endl;
}

void Finance::saveGame() const {
    ofstream financeFile("finances.dat");
    if (!financeFile) {
        cout << "Failed to save financial records!\n";
        return;
    }

    financeFile << goldReserves << endl
        << taxPercent << endl
        << priceRise;
    financeFile.close();
    cout << "Financial records archived.\n";
}

void Finance::loadGame() {
    ifstream financeFile("finances.dat");
    if (!financeFile) {
        cout << "No financial records found!\n";
        return;
    }

    financeFile >> goldReserves >> taxPercent >> priceRise;
    financeFile.close();
    cout << "Financial records restored.\n";
}

int Finance::getGold() const {
    return goldReserves;
}

void Finance::takeLoan(int sum) {
    goldReserves += sum;
    cout << "Loan of " << sum << " gold added to treasury.\n";
}