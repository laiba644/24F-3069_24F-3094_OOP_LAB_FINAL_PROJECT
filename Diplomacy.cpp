#include "Stronghold.h"

Diplomacy::Diplomacy() : kingdom1(""), kingdom2(""), status("Neutral") {}

void Diplomacy::formAlliance(const Kingdom& k1, const Kingdom& k2) {
    kingdom1 = k1.getName();
    kingdom2 = k2.getName();
    status = "Alliance";
    cout << kingdom1 << " and " << kingdom2 << " form an alliance.\n";
    saveDiplomacy();
}

void Diplomacy::formTreaty(const Kingdom& k1, const Kingdom& k2) {
    kingdom1 = k1.getName();
    kingdom2 = k2.getName();
    status = "Treaty";
    cout << kingdom1 << " and " << kingdom2 << " sign a treaty.\n";
    saveDiplomacy();
}

void Diplomacy::declareWar(const Kingdom& k1, const Kingdom& k2) {
    kingdom1 = k1.getName();
    kingdom2 = k2.getName();
    status = "War";
    cout << kingdom1 << " declares war on " << kingdom2 << "!\n";
    saveDiplomacy();
}

void Diplomacy::breakAlliance(const Kingdom& k1, const Kingdom& k2) {
    kingdom1 = k1.getName();
    kingdom2 = k2.getName();
    if (status == "Alliance") {
        status = "Neutral";
        cout << kingdom1 << " breaks alliance with " << kingdom2 << "!\n";
        saveDiplomacy();
    }
    else {
        cout << "No alliance to break.\n";
    }
}

string Diplomacy::getStatus(const Kingdom& k1, const Kingdom& k2) const {
    if (kingdom1 == k1.getName() && kingdom2 == k2.getName()) {
        return status;
    }
    return "Neutral";
}

void Diplomacy::saveDiplomacy() const {
    ofstream outFile("diplomacy.dat", ios::app);
    if (!outFile) {
        cout << "Error saving diplomacy status.\n";
        return;
    }
    outFile << kingdom1 << "|" << kingdom2 << "|" << status << "\n";
    outFile.close();
}