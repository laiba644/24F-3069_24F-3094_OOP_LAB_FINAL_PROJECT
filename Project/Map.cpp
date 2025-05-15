#include "Stronghold.h"
#include <cmath>
#include <stdexcept>

Map::Map() : positionCount(0) {
    for (int i = 0; i < 2; i++) {
        positions[i].name = "";
        positions[i].row = -1;
        positions[i].col = -1;
        positions[i].controlStartRow = -1;
        positions[i].controlEndRow = -1;
    }
}

void Map::setPosition(const Kingdom& kingdom, int row, int col) {
    try {
        if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
            throw std::invalid_argument("Invalid position (" + std::to_string(row) + ", " + std::to_string(col) + ") for " + kingdom.getName() + ". Must be within 0 to " + std::to_string(GRID_SIZE - 1) + ".");
        }
        if (positionCount >= 2) {
            throw std::runtime_error("Cannot add more than 2 kingdoms to the map.");
        }
        for (int i = 0; i < positionCount; i++) {
            if (positions[i].row == row && positions[i].col == col) {
                throw std::invalid_argument("Position (" + std::to_string(row) + ", " + std::to_string(col) + ") is already occupied by " + positions[i].name + ".");
            }
        }
        positions[positionCount].name = kingdom.getName();
        positions[positionCount].row = row;
        positions[positionCount].col = col;
        // Set control zone (e.g., 3 rows centered around kingdom)
        positions[positionCount].controlStartRow = std::max(0, row - 1);
        positions[positionCount].controlEndRow = std::min(GRID_SIZE - 1, row + 1);
        positionCount++;
        cout << kingdom.getName() << " positioned at (" << row << ", " << col << ").\n";
    }
    catch (const std::exception& e) {
        cout << "Error setting position: " << e.what() << endl;
    }
}

void Map::moveKingdom(const Kingdom& kingdom, int newRow, int newCol) {
    try {
        if (newRow < 0 || newRow >= GRID_SIZE || newCol < 0 || newCol >= GRID_SIZE) {
            throw std::invalid_argument("Invalid new position (" + std::to_string(newRow) + ", " + std::to_string(newCol) + ") for " + kingdom.getName() + ". Must be within 0 to " + std::to_string(GRID_SIZE - 1) + ".");
        }
        int index = -1;
        for (int i = 0; i < positionCount; i++) {
            if (positions[i].name == kingdom.getName()) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            throw std::runtime_error("Kingdom " + kingdom.getName() + " not found on the map.");
        }
        for (int i = 0; i < positionCount; i++) {
            if (i != index && positions[i].row == newRow && positions[i].col == newCol) {
                throw std::invalid_argument("Position (" + std::to_string(newRow) + ", " + std::to_string(newCol) + ") is already occupied by " + positions[i].name + ".");
            }
        }
        positions[index].row = newRow;
        positions[index].col = newCol;
        positions[index].controlStartRow = std::max(0, newRow - 1);
        positions[index].controlEndRow = std::min(GRID_SIZE - 1, newRow + 1);
        cout << kingdom.getName() << " moved to (" << newRow << ", " << newCol << ").\n";
    }
    catch (const std::exception& e) {
        cout << "Error moving kingdom: " << e.what() << endl;
    }
}


void Map::displayMap() const {
    cout << "\n=== Game Map (9x9) ===\n";
    cout << "   ";
    for (int col = 0; col < GRID_SIZE; col++) {
        cout << col << " ";
    }
    cout << "\n";
    for (int row = 0; row < GRID_SIZE; row++) {
        cout << row << " |";
        for (int col = 0; col < GRID_SIZE; col++) {
            bool isKingdom = false;
            for (int i = 0; i < positionCount; i++) {
                if (positions[i].row == row && positions[i].col == col) {
                    cout << (positions[i].name == "Eldoria" ? "E" : "V") << "|";
                    isKingdom = true;
                    break;
                }
            }
            if (!isKingdom) {
                bool inControlZone = false;
                for (int i = 0; i < positionCount; i++) {
                    if (row >= positions[i].controlStartRow && row <= positions[i].controlEndRow && col == positions[i].col) {
                        cout << (positions[i].name == "Eldoria" ? "e" : "v") << "|";
                        inControlZone = true;
                        break;
                    }
                }
                if (!inControlZone) {
                    cout << ".|";
                }
            }
        }
        cout << "\n";
    }
    cout << "E = Eldoria, V = Valthor, e/v = control zone\n";
}