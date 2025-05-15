#include "Stronghold.h"

Communication::Communication() : sender(""), receiver(""), message("") {}

void Communication::sendMessage(const Kingdom& from, const Kingdom& to, const string& msg) {
    sender = from.getName();
    receiver = to.getName();
    message = msg;
    cout << "Message from " << sender << " to " << receiver << ": " << message << "\n";
    saveMessages();
}

void Communication::displayMessages() const {
    cout << "\n=== Message Log ===\n";
    if (message.empty()) {
        cout << "No messages.\n";
        return;
    }
    cout << "From " << sender << " to " << receiver << ": " << message << "\n";
}

void Communication::saveMessages() const {
    ofstream outFile("messages.txt", ios::app);
    if (!outFile) {
        cout << "Error saving message.\n";
        return;
    }
    outFile << sender << "|" << receiver << "|" << message << "\n";
    outFile.close();
}