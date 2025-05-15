#include "Stronghold.h"

Map::Map() : positionCount(0) {
    // Initialize positions array
    positions[0].name = "";
    positions[1].name = "";
}

void Map::setPosition(const Kingdom& kingdom, int row, int col) {
    // Validate coordinates
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        cout << "Invalid position (" << row << ", " << col << ") for " << kingdom.getName() << ". Must be within 0 to " << GRID_SIZE - 1 << ".\n";
        return;
    }

    // Update existing kingdom position
    for (int i = 0; i < positionCount; i++) {
        if (positions[i].name == kingdom.getName()) {
            positions[i].row = row;
            positions[i].col = col;
            cout << kingdom.getName() << " position updated to (" << row << ", " << col << ").\n";
            saveMap();
            return;
        }
    }

    // Add new kingdom
    if (positionCount < 2) {
        positions[positionCount].name = kingdom.getName();
        positions[positionCount].row = row;
        positions[positionCount].col = col;
        // Set control zones
        if (kingdom.getName() == "Eldoria") {
            positions[positionCount].controlStartRow = 0;
            positions[positionCount].controlEndRow = 4;
        }
        else if (kingdom.getName() == "Valthor") {
            positions[positionCount].controlStartRow = 5;
            positions[positionCount].controlEndRow = 8;
        }
        positionCount++;
        cout << kingdom.getName() << " position set to (" << row << ", " << col << ") with control rows "
            << positions[positionCount - 1].controlStartRow << "-" << positions[positionCount - 1].controlEndRow << ".\n";
        saveMap();
    }
    else {
        cout << "Cannot add " << kingdom.getName() << ": Map already has two kingdoms.\n";
    }
}

void Map::moveKingdom(const Kingdom& kingdom, int newRow, int newCol) {
    // Validate coordinates
    if (newRow < 0 || newRow >= GRID_SIZE || newCol < 0 || newCol >= GRID_SIZE) {
        cout << "Invalid move to (" << newRow << ", " << newCol << ") for " << kingdom.getName() << ". Must be within 0 to " << GRID_SIZE - 1 << ".\n";
        return;
    }

    // Find and update kingdom position
    for (int i = 0; i < positionCount; i++) {
        if (positions[i].name == kingdom.getName()) {
            positions[i].row = newRow;
            positions[i].col = newCol;
            cout << kingdom.getName() << " moved to (" << newRow << ", " << newCol << ").\n";
            saveMap();
            return;
        }
    }
    cout << kingdom.getName() << " not found on map.\n";
}

int Map::getDistance(const Kingdom& k1, const Kingdom& k2) const {
    int row1 = -1, col1 = -1, row2 = -1, col2 = -1;
    for (int i = 0; i < positionCount; i++) {
        if (positions[i].name == k1.getName()) {
            row1 = positions[i].row;
            col1 = positions[i].col;
        }
        if (positions[i].name == k2.getName()) {
            row2 = positions[i].row;
            col2 = positions[i].col;
        }
    }
    if (row1 == -1 || row2 == -1) {
        cout << "Distance error: One or both kingdoms not found.\n";
        return -1;
    }
    return abs(row1 - row2) + abs(col1 - col2); // Manhattan distance
}

void Map::displayMap() const {
    cout << "\n=== Kingdom Map ===\n";
    if (positionCount == 0) {
        cout << "No kingdoms are positioned on the map.\n";
        return;
    }

    // Display kingdom positions and control zones
    for (int i = 0; i < positionCount; i++) {
        if (!positions[i].name.empty()) {
            string territory = (positions[i].name == "Eldoria") ? "Northern Territory" : "Southern Territory";
            cout << positions[i].name << " at (" << positions[i].row << ", " << positions[i].col
                << ") controls rows " << positions[i].controlStartRow << "-" << positions[i].controlEndRow
                << " (" << territory << ")\n";
        }
    }

    // Display distance
    if (positionCount == 2) {
        cout << "Distance between " << positions[0].name << " and " << positions[1].name << ": "
            << getDistance(Kingdom(positions[0].name), Kingdom(positions[1].name)) << "\n";
    }

    // Display grid layout
    cout << "Grid Layout (9x9):\n";
    char grid[GRID_SIZE][GRID_SIZE];
    // Initialize grid with dots
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
    // Place kingdoms
    for (int i = 0; i < positionCount; i++) {
        if (!positions[i].name.empty()) {
            grid[positions[i].row][positions[i].col] = (positions[i].name == "Eldoria") ? 'E' : 'V';
        }
    }
    // Print grid
    for (int i = 0; i < GRID_SIZE; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < GRID_SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << (i <= 4 ? " (Northern Territory)" : " (Southern Territory)") << "\n";
    }
    cout << "Legend: E = Eldoria, V = Valthor, . = Empty\n";
}

void Map::saveMap() const {
    ofstream outFile("map.dat");
    if (!outFile) {
        cout << "Error saving map data.\n";
        return;
    }
    for (int i = 0; i < positionCount; i++) {
        if (!positions[i].name.empty()) {
            outFile << positions[i].name << "|" << positions[i].row << "|" << positions[i].col << "|"
                << positions[i].controlStartRow << "|" << positions[i].controlEndRow << "\n";
        }
    }
    outFile.close();
}