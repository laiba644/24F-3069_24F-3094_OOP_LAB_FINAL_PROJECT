#include "Stronghold.h"

Trade::Trade() : seller(""), buyer(""), resource(""), quantity(0), price(0), isSmuggling(false) {}

void Trade::initiateTrade(Kingdom& from, Kingdom& to, const string& res, int qty, int cost, bool smuggle) {
    seller = from.getName();
    buyer = to.getName();
    resource = res;
    quantity = qty;
    price = cost;
    isSmuggling = smuggle;

    try {
        if (qty <= 0 || cost < 0) {
            throw std::invalid_argument("Invalid trade parameters.");
        }
        if (from.getMaterials().getResource(res) < qty) {
            throw std::invalid_argument("Seller lacks sufficient resources.");
        }
        if (from.getFinance().getGold() < cost) {
            throw std::invalid_argument("Seller lacks sufficient gold.");
        }
        from.getMaterials().consumeResource(res, qty);
        to.getMaterials().addResource(res, qty);
        from.getFinance().makePayment(cost);
        to.getFinance().collectTaxes({}); // Simplified, adjust as needed
        seller = from.getName();
        buyer = to.getName();
        resource = res;
        quantity = qty;
        price = cost;
        isSmuggling = smuggle;
        cout << "Trade completed: " << qty << " " << res << " from " << seller << " to " << buyer << " for " << cost << " gold." << endl;
    }
    catch (const std::invalid_argument& e) {
        cout << "Trade failed: " << e.what() << endl;
    }
}

void Trade::saveTrade() const {
    ofstream outFile("trades.dat", ios::app);
    if (!outFile) {
        cout << "Error saving trade record.\n";
        return;
    }
    outFile << seller << "|" << buyer << "|" << resource << "|" << quantity << "|" << price << "|" << isSmuggling << "\n";
    outFile.close();
}