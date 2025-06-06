#ifndef EVENTSYSTEM_H
#define EVENTSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const int MAX_EVENTS = 100;

class Event {
public:
    string name;
    string type;
    string location;
    string date;
    int availableTickets;
    double price;

    Event() : availableTickets(0), price(0.0) {}
};

class User {
public:
    string username;
    string password;
};

class Admin {
public:
    string username;
    string password;
};

class EventSystem {
private:
    Event events[MAX_EVENTS];
    int numEvents;
    vector<User> users;

public:
    EventSystem();

    bool adminLogin(const Admin& admin, const string& username, const string& password);
    bool userLogin(const string& username, const string& password);
    bool userSignUp(const string& username, const string& password);
    void displayEventDetails(const Event& event);
    void browseEvents();
    void searchEvents(const string& criteria);
    void bookTicket(const string& eventName, int numTickets);
    void addEvent(const Event& newEvent);
    void deleteEvent(const string& name);
    void updateEvent(const Event& updatedEvent);
    void loadEventsFromFile(const string& filename);
    void saveEventsToFile(const string& filename);
    void loadUsersFromFile(const string& filename);
    void saveUsersToFile(const string& filename);
};

#endif // EVENTSYSTEM_H
