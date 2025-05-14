#include "Stronghold.h"

RandomEvents::RandomEvents() {
}

void RandomEvents::triggerEvent(Citizens& people, Military& forces, Finance& treasury, Materials& supplies) {
    cout << "\n=== Kingdom Events ===\n";
    cout << "Select a crisis to simulate:\n";
    cout << "1. Crop Failure\n";
    cout << "2. Plague\n";
    cout << "3. Border Skirmish\n";
    cout << "4. Noble Conspiracy\n";
    cout << "5. Natural Disaster\n";

    int eventChoice;
    cin >> eventChoice;

    switch (eventChoice) {
    case 1:
        foodShortage(supplies, people);
        break;
    case 2:
        plagueOutbreak(people);
        break;
    case 3:
        borderConflict(forces, treasury);
        break;
    case 4:
        corruptionScandal(treasury);
        break;
    case 5:
        naturalDisaster(supplies);
        break;
    default:
        cout << "No event triggered.\n";
    }
}

void RandomEvents::foodShortage(Materials& supplies, Citizens& people) {
    cout << "\nDrought ruins harvests! Food stores plummet.\n";
    supplies.consumeResource("grain", 120);
    people.reducePopulation(12);
}

void RandomEvents::plagueOutbreak(Citizens& people) {
    cout << "\nPestilence sweeps through towns!\n";
    people.reducePopulation(18);
}

void RandomEvents::borderConflict(Military& forces, Finance& treasury) {
    cout << "\nRaiders attack our borders!\n";
    forces.demoralize(25);
    treasury.makePayment(250);
}

void RandomEvents::corruptionScandal(Finance& treasury) {
    cout << "\nOfficials embezzle funds!\n";
    treasury.makePayment(350);
}

void RandomEvents::naturalDisaster(Materials& supplies) {
    cout << "\nEarthquake damages infrastructure!\n";
    supplies.consumeResource("marble", 60);
}