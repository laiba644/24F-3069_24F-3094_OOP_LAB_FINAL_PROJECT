 ##24F-3094_24F-3069_OOP-Lab-Final-Project

## Description
 The project is about Stronghold project which is a console-based multiplayer strategy simulation game to implement a highly dynamic medieval kingdom using advanced Object- Oriented Programming concepts in C++.

## Project Division 

Laiba Kashif f243069
BankingSystem.cpp
EconomicManagement.cpp
EventHandling.cpp

Noor Ul Ain f243094
MilitarySystem.cpp
PopulationDynamics.cpp
ResourceEcosystem.cpp

Compiled by Both 
Main.cpp
LeadershipMechanics.cpp
Stronghold.h


## Key Features
Manage the population: Track the number of citizens and manage their needs.
Military system: Recruit soldiers and manage troop morale.
Economic system: Collect taxes, grant loans, and handle the kingdom’s finances.
Banking system: Inspect the kingdom’s treasury, grant loans, and collect debt.
Random events: Handle various random events like food shortages, plagues, and natural disasters.
Save and load game: Save your kingdom’s progress and load it when needed.


## Explanation of code 

## Classes:

Person Class: A base class for creating different types of people (used by other classes).

Citizens Class: Manages the kingdom’s population, including demographics (farmers, traders, elites), food reserves, and approval ratings. It also handles population growth or loss.

Military Class: Controls the kingdom’s army, troop recruitment, morale, and the number of available rations.

Finance Class: Manages the kingdom’s treasury, including tax collection, loan handling, and disbursements.

CentralBank Class: Focuses on the kingdom's bank, auditing financial records, granting loans, and collecting debt.

Materials Class: Tracks resources like grain, lumber, marble, and steel. It allows for the collection or usage of materials.

RandomEvents Class: Simulates various random events such as crop failures, plagues, and natural disasters that may impact the kingdom.

Ruler Class: Represents the ruler of the kingdom (either a monarch or dictator), with the ability to enact policies.

## Inheritance and Pointers:

Inheritance: The Monarch and Dictator classes inherit from the Ruler class. This allows them to share common properties and methods (such as enactPolicy()), while also implementing their own specific behavior.

For example, Monarch implements a peaceful policy, while Dictator implements an oppressive policy.

Pointers: The game uses a pointer to the base class Ruler*, which can point to objects of derived classes (Monarch or Dictator). This is an example of polymorphism, where the program can call the appropriate method  based on the actual type of the object

## Game Flow:
The game runs in a loop where the user selects actions from a menu, such as viewing kingdom status, recruiting soldiers, or managing resources.
Random events trigger at intervals, which the user must address.
The game allows saving and loading to track the kingdom’s progress.

## Saving and Loading:
The game uses file operations to save and load the kingdom’s data, allowing users to continue their game at any time.

## Usage

## View Kingdom Status
KINGDOM MANAGEMENT SYSTEM
1. View Status
2. Process Population Changes
3. Conduct Military Recruitment
4. Manage Royal Finances
5. Oversee Resources
6. Simulate Kingdom Events
7. Save Kingdom Progress
8. Load Previous Session
9. Abdicate Throne (Exit)

Your command:
Your command: 1

=== Kingdom Demographics ===
Total Citizens: 100
Field Workers: 60
Marketplace Vendors: 25
Aristocracy: 15
Public Approval: 70%

=== Military Overview ===
Active Troops: 25
Unit Morale: 65%
Remaining Rations: 120

=== Kingdom Finances ===
Treasury: 1200 gold coins
Tax Rate: 6% per citizen
Inflation: 100% (x1.0)

=== Current Stockpile ===
Grain: 500
Lumber: 300
Marble: 200
Steel: 100

=== Royal Bank Ledger ===
Total Loans: 0 gold
Scams Found: 0

## Recruit Soldiers
Your command: 3

=== Military Recruitment Drive ===
How many citizens to enlist? 10

Insufficient supplies for 10 recruits!
Current food reserves are not enough to recruit that many soldiers.
Combat spirit reduced to 50%.

## Manage Finances

Your command: 4

=== Tax Season ===
Collected taxes from 100 citizens
Revenue: 600 gold coins
Treasury now holds: 1800 gold coins

=== Royal Audit ===
Treasury in good standing with 1800 gold.

## Simulate Random Events
Your command: 6

=== Kingdom Events ===
Select a crisis to simulate:
1. Crop Failure
2. Plague
3. Border Skirmish
4. Noble Conspiracy
5. Natural Disaster

Your choice: 1

Drought ruins harvests! Food stores plummet.
120 grain consumed, 12 citizens lost to famine.

 ## Save and Load the Game
You can save your progress by choosing option 7 and load it later by selecting option 8. This allows you to track your kingdom’s progress across sessions.
