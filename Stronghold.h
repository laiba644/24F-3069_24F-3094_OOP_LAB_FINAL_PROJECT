#ifndef STRONGHOLD_H
#define STRONGHOLD_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Core Person Class
class Person {
protected:
    string fullName;
    int yearsOld;
public:
    Person();
    Person(string personName, int personAge);
    virtual void displayInfo() const;
};

// Social Structure Classes
class SocialClass {
protected:
    string className;
    int peopleCount;
public:
    SocialClass();
    SocialClass(string socialTier, int count);
    virtual void displayStatus() const;
};

// Population Management
class Citizens {
private:
    int totalPeople;
    int farmers;
    int traders;
    int elites;
    int foodReserves;
    float approvalRating;
public:
    Citizens();
    void updatePopulation();
    void displayDemographics() const;
    void saveGame() const;
    void loadGame();
    int getPopulation() const;
    void reducePopulation(int numLost);
};

// Military System
class Military {
private:
    int troopCount;
    int combatSpirit;
    int rations;
public:
    Military();
    void enlistSoldiers(Citizens& populace);
    void displayStrength() const;
    void saveGame() const;
    void loadGame();
    void demoralize(int loss);
    int getTroopCount() const;
};

// Economic System
class Finance {
private:
    int goldReserves;
    float taxPercent;
    float priceRise;
public:
    Finance();
    void collectTaxes(const Citizens& populace);
    void makePayment(int cost);
    void displayFinances() const;
    void saveGame() const;
    void loadGame();
    int getGold() const;
    void takeLoan(int sum);
};

// Banking System
class CentralBank {
private:
    int totalLoans;
    int scamsFound;
public:
    CentralBank();
    void inspectBooks(Finance& economy);
    void grantLoan(Finance& economy, int sum);
    void collectDebt(Finance& economy, int payment);
    void displayBankStatus() const;
    void saveGame() const;
    void loadGame();
};

// Resource System
class Materials {
private:
    int grain;
    int lumber;
    int marble;
    int steel;
public:
    Materials();
    void updateResources();
    void harvestMaterials();
    void useMaterials();
    void displayStocks() const;
    void saveGame() const;
    void loadGame();
    void consumeResource(string type, int quantity);
    int getResource(string type) const;
    void addResource(string type, int amount);
};

// Random Events
class RandomEvents {
public:
    RandomEvents();
    void triggerEvent(Citizens& people, Military& forces, Finance& money, Materials& goods);
    void foodShortage(Materials& supplies, Citizens& people);
    void plagueOutbreak(Citizens& people);
    void borderConflict(Military& forces, Finance& money);
    void corruptionScandal(Finance& money);
    void naturalDisaster(Materials& supplies);
};

// Leadership System
class Ruler {
protected:
    string rulerName;
public:
    Ruler(string name);
    virtual void enactPolicy(Finance& money, Military& forces);
    string getRulerName() const;
};

class Monarch : public Ruler {
public:
    Monarch();
    void peacefulPolicy(Finance& money, Military& forces);
};

class Dictator : public Ruler {
public:
    Dictator();
    void oppressivePolicy(Finance& money, Military& forces);
};

// Module 2 Classes
class Kingdom {
private:
    string kingdomName;
    Citizens citizens;
    Military military;
    Finance finance;
    Materials materials;
    CentralBank bank;
    Ruler* ruler;
public:
    Kingdom(string name);
    ~Kingdom();
    string getName() const;
    Citizens& getCitizens();
    Military& getMilitary();
    Finance& getFinance();
    Materials& getMaterials();
    const Military& getMilitaryConst() const;
    const Finance& getFinanceConst() const;
    const Materials& getMaterialsConst() const;
    CentralBank& getBank();
    void displayStatus() const;
    void saveGame() const;
    void loadGame();
};

class Communication {
private:
    string sender;
    string receiver;
    string message;
public:
    Communication();
    void sendMessage(const Kingdom& from, const Kingdom& to, const string& msg);
    void displayMessages() const;
    void saveMessages() const;
};

class Diplomacy {
private:
    string kingdom1;
    string kingdom2;
    string status; // Alliance, Treaty, Neutral, War
public:
    Diplomacy();
    void formAlliance(const Kingdom& k1, const Kingdom& k2);
    void formTreaty(const Kingdom& k1, const Kingdom& k2);
    void declareWar(const Kingdom& k1, const Kingdom& k2);
    void breakAlliance(const Kingdom& k1, const Kingdom& k2);
    string getStatus(const Kingdom& k1, const Kingdom& k2) const;
    void saveDiplomacy() const;
};

class Trade {
private:
    string seller;
    string buyer;
    string resource;
    int quantity;
    int price;
    bool isSmuggling;
public:
    Trade();
    void initiateTrade(Kingdom& from, Kingdom& to, const string& res, int qty, int cost, bool smuggle);
    void saveTrade() const;
};

class Conflict {
private:
    int attackerTroops;
    int defenderTroops;
public:
    Conflict();
    void initiateAttack(Kingdom& attacker, Kingdom& defender);
    void saveConflict() const;
};

class Map {
private:
    static const int GRID_SIZE = 9; // 9x9 grid
    struct KingdomPosition {
        string name;
        int row, col;
        int controlStartRow, controlEndRow; // Control zone boundaries
    };
    KingdomPosition positions[2]; // Store positions for two kingdoms
    int positionCount;
public:
    Map();
    void setPosition(const Kingdom& kingdom, int row, int col);
    void moveKingdom(const Kingdom& kingdom, int newRow, int newCol);
    int getDistance(const Kingdom& k1, const Kingdom& k2) const;
    void displayMap() const;
    void saveMap() const;
};

#endif // STRONGHOLD_H