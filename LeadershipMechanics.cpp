#include "Stronghold.h"

Ruler::Ruler(string rulerTitle) {
    rulerName = rulerTitle;
}

string Ruler::getRulerName() const {
    return rulerName;
}

void Ruler::enactPolicy(Finance& treasury, Military& forces) {
    cout << rulerName << " maintains the status quo.\n";
}

Monarch::Monarch() : Ruler("Benevolent Monarch") {}

void Monarch::peacefulPolicy(Finance& treasury, Military& forces) {
    cout << "The Monarch invests in public welfare programs.\n";
    treasury.makePayment(120);
    forces.demoralize(8);
}

Dictator::Dictator() : Ruler("Iron-Fisted Dictator") {}

void Dictator::oppressivePolicy(Finance& treasury, Military& forces) {
    cout << "The Dictator tightens military control.\n";
    treasury.makePayment(40);
    forces.demoralize(-15);
}