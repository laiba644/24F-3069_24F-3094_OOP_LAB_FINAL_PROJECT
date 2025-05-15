#include "Stronghold.h"
CentralBank::CentralBank() {
    totalLoans = 0;
    scamsFound = 0;
}

void CentralBank::inspectBooks(Finance& economy) {
    cout << "\n=== Royal Audit ===\n";

    int currentGoldReserves = economy.getGold();

    if (currentGoldReserves < 0) {
        cout << "EMBEZZLEMENT DISCOVERED! Treasury in deficit.\n";
        scamsFound++;
    }
    else if (currentGoldReserves < 150) {
        cout << "Warning: Treasury dangerously low at " << currentGoldReserves << " gold.\n";
    }
    else {
        cout << "Treasury in good standing with " << currentGoldReserves << " gold.\n";
    }
}

void CentralBank::grantLoan(Finance& economy, int sum) {
    cout << "\nProcessing loan for " << sum << " gold...\n";

    if (sum <= 0) {
        cout << "Loan rejected - invalid amount.\n";
        return;
    }

    economy.takeLoan(sum);
    totalLoans += sum;
    cout << sum << " gold loan approved. Total debt: " << totalLoans << "\n";
}

void CentralBank::collectDebt(Finance& economy, int payment) {
    cout << "\nAttempting debt payment of " << payment << " gold\n";

    if (payment <= 0 || payment > totalLoans) {
        cout << "Invalid payment amount.\n";
        return;
    }

    if (payment > economy.getGold()) {
        cout << "Payment failed - insufficient funds.\n";
        return;
    }

    economy.makePayment(payment);
    totalLoans -= payment;
    cout << payment << " gold applied to debt. Remaining: " << totalLoans << "\n";
}

void CentralBank::displayBankStatus() const {
    cout << "\n=== Royal Bank Ledger ===\n";
    cout << "Total Loans: " << totalLoans << " gold\n";
    cout << "Scams Found: " << scamsFound << "\n";
}

void CentralBank::saveGame() const {
    ofstream bankRecords("bank_ledger.txt");
    if (!bankRecords) {
        cout << "Failed to save bank records!\n";
        return;
    }

    bankRecords << totalLoans << endl << scamsFound;
    bankRecords.close();
    cout << "Bank records secured.\n";
}

void CentralBank::loadGame() {
    ifstream bankRecords("bank_ledger.txt");
    if (!bankRecords) {
        cout << "No bank records found!\n";
        return;
    }

    bankRecords >> totalLoans >> scamsFound;
    bankRecords.close();
    cout << "Bank records restored.\n";
}