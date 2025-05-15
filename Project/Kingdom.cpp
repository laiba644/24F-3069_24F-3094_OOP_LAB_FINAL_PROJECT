#include "Stronghold.h"

Kingdom::Kingdom(string name) : kingdomName(name), ruler(new Monarch()) {}

Kingdom::~Kingdom() { 
    delete ruler;
}

string Kingdom::getName() const { 
    return kingdomName;
}

Citizens& Kingdom::getCitizens() { 
    return citizens;
}

Military& Kingdom::getMilitary() {
    return military;
}

Finance& Kingdom::getFinance() {
    return finance; 
}

Materials& Kingdom::getMaterials() {
    return materials; 
}

const Military& Kingdom::getMilitaryConst() const {
    return military;
}

const Finance& Kingdom::getFinanceConst() const {
    return finance;
}

const Materials& Kingdom::getMaterialsConst() const { 
    return materials; 
}

CentralBank& Kingdom::getBank() { 
    return bank;
}

void Kingdom::displayStatus() const {
    cout << "\n=== " << kingdomName << " Status ===\n";
    citizens.displayDemographics();
    military.displayStrength();
    finance.displayFinances();
    materials.displayStocks();
    bank.displayBankStatus();
}

void Kingdom::saveGame() const {
    citizens.saveGame();
    military.saveGame();
    finance.saveGame();
    materials.saveGame();
    bank.saveGame();
}

void Kingdom::loadGame() {
    citizens.loadGame();
    military.loadGame();
    finance.loadGame();
    materials.loadGame();
    bank.loadGame();
}