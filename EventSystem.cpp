#include "EventSystem.h"
#include <fstream>
#include <iostream>

EventSystem::EventSystem() : numEvents(0) {
    loadUsersFromFile("users.txt");
    loadEventsFromFile("events.txt");
}

bool EventSystem::adminLogin(const Admin& admin, const string& username, const string& password) {
    return (admin.username == username && admin.password == password);
}

bool EventSystem::userLogin(const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

bool EventSystem::userSignUp(const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.username == username) {
            return false;
        }
    }
    User newUser = { username, password };
    users.push_back(newUser);
    saveUsersToFile("users.txt");
    return true;
}

void EventSystem::displayEventDetails(const Event& event) {
    cout << "Event Name: " << event.name << endl;
    cout << "Type: " << event.type << endl;
    cout << "Location: " << event.location << endl;
    cout << "Date: " << event.date << endl;
    cout << "Available Tickets: " << event.availableTickets << endl;
    cout << "Price: $" << event.price << endl;
}

void EventSystem::browseEvents() {
    cout << "Available Events:" << endl;
    for (int i = 0; i < numEvents; ++i) {
        displayEventDetails(events[i]);
        cout << endl;
    }
}

void EventSystem::searchEvents(const string& criteria) {
    cout << "Search Results:" << endl;
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].name.find(criteria) != string::npos ||
            events[i].type.find(criteria) != string::npos ||
            events[i].location.find(criteria) != string::npos ||
            events[i].date.find(criteria) != string::npos) {
            displayEventDetails(events[i]);
            cout << endl;
        }
    }
}

void EventSystem::bookTicket(const string& eventName, int numTickets) {
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].name == eventName) {
            if (events[i].availableTickets >= numTickets) {
                events[i].availableTickets -= numTickets;
                cout << "Tickets booked successfully!" << endl;
            }
            else {
                cout << "Not enough tickets available for booking." << endl;
            }
            return;
        }
    }
    cout << "Event not found!" << endl;
}

void EventSystem::addEvent(const Event& newEvent) {
    if (numEvents < MAX_EVENTS) {
        events[numEvents] = newEvent;
        numEvents++;
        cout << "Event added successfully!" << endl;
    }
    else {
        cout << "Event capacity reached. Cannot add more events." << endl;
    }
}

void EventSystem::deleteEvent(const string& name) {
    bool found = false;
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].name == name) {
            found = true;
            for (int j = i; j < numEvents - 1; ++j) {
                events[j] = events[j + 1];
            }
            numEvents--;
            cout << "Event deleted successfully!" << endl;
            break;
        }
    }
    if (!found) {
        cout << "Event not found!" << endl;
    }
}

void EventSystem::updateEvent(const Event& updatedEvent) {
    for (int i = 0; i < numEvents; ++i) {
        if (events[i].name == updatedEvent.name) {
            events[i] = updatedEvent;
            cout << "Event updated successfully!" << endl;
            return;
        }
    }
    cout << "Event not found!" << endl;
}

void EventSystem::loadEventsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        // Create the file if it does not exist
        ofstream createFile(filename);
        createFile.close();
        file.open(filename);
    }

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    numEvents = 0;
    while (file >> events[numEvents].name >> events[numEvents].type >> events[numEvents].location >> events[numEvents].date >> events[numEvents].availableTickets >> events[numEvents].price) {
        numEvents++;
    }
    file.close();
}

void EventSystem::saveEventsToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    for (int i = 0; i < numEvents; ++i) {
        file << events[i].name << " " << events[i].type << " " << events[i].location << " " << events[i].date << " " << events[i].availableTickets << " " << events[i].price << endl;
    }
    file.close();
}

void EventSystem::loadUsersFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        // Create the file if it does not exist
        ofstream createFile(filename);
        createFile.close();
        file.open(filename);
    }

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    users.clear();
    User user;
    while (file >> user.username >> user.password) {
        users.push_back(user);
    }
    file.close();
}

void EventSystem::saveUsersToFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    for (const auto& user : users) {
        file << user.username << " " << user.password << endl;
    }
    file.close();
}
