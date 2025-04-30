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
};

// Random Events
class RandomEvents {
public:
    RandomEvents();
    void triggerEvent(Citizens& people, Military& forces,
        Finance& money, Materials& goods);
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

#endif // STRONGHOLD_H