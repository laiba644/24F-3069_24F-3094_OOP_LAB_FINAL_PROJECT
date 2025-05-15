#include "Stronghold.h"

Conflict::Conflict() {}

void Conflict::initiateAttack(Kingdom& attacker, Kingdom& defender) {
    cout << attacker.getName() << " attacks " << defender.getName() << "!\n";

    Diplomacy dip;
    if (dip.getStatus(attacker, defender) == "Alliance") {
        cout << "Betrayal! Attacking an ally causes heavy morale penalty.\n";
        attacker.getMilitary().demoralize(20);
    }

    int attackerStrength = attacker.getMilitary().getTroopCount();
    int defenderStrength = defender.getMilitary().getTroopCount();

    if (attackerStrength > defenderStrength) {
        cout << attacker.getName() << " wins the battle!\n";
        defender.getMilitary().demoralize(30);
        defender.getCitizens().reducePopulation(defenderStrength / 2);
        attacker.getFinance().takeLoan(200); // Loot
    }
    else {
        cout << defender.getName() << " repels the attack!\n";
        attacker.getMilitary().demoralize(30);
        attacker.getCitizens().reducePopulation(attackerStrength / 2);
    }

    saveConflict();
}

void Conflict::saveConflict() const {
    ofstream outFile("conflicts.dat", ios::app);
    if (!outFile) {
        cout << "Error saving conflict record.\n";
        return;
    }
    outFile << "Battle occurred.\n";
    outFile.close();
}