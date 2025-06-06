// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "EventSystem.h"

int main() {
    // Hardcoded admin credentials
    Admin admin = { "admin", "admin123" };

    // Create an instance of EventSystem
    EventSystem eventSystem;

    // Load events from file at the start
    eventSystem.loadEventsFromFile("events.txt");

    // Main loop for the system
    int choice;
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Admin Login" << endl;
        cout << "2. User Login" << endl;
        cout << "3. User Sign-Up" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter Admin Username: ";
            cin >> username;
            cout << "Enter Admin Password: ";
            cin >> password;

            if (eventSystem.adminLogin(admin, username, password)) {
                cout << "Admin login successful!" << endl;
                int adminChoice;
                while (true) {
                    cout << "Admin Options:" << endl;
                    cout << "1. Add Event" << endl;
                    cout << "2. Delete Event" << endl;
                    cout << "3. Update Event" << endl;
                    cout << "4. List Events" << endl;
                    cout << "5. Return to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        Event newEvent;
                        cout << "Enter Event Name: ";
                        cin >> newEvent.name;
                        cout << "Enter Event Type: ";
                        cin >> newEvent.type;
                        cout << "Enter Event Location: ";
                        cin >> newEvent.location;
                        cout << "Enter Event Date: ";
                        cin >> newEvent.date;
                        cout << "Enter Available Tickets: ";
                        cin >> newEvent.availableTickets;
                        cout << "Enter Ticket Price: ";
                        cin >> newEvent.price;
                        eventSystem.addEvent(newEvent);
                        eventSystem.saveEventsToFile("events.txt"); // Save changes to file
                    }
                    else if (adminChoice == 2) {
                        string name;
                        cout << "Enter Event Name to delete: ";
                        cin >> name;
                        eventSystem.deleteEvent(name);
                        eventSystem.saveEventsToFile("events.txt"); // Save changes to file
                    }
                    else if (adminChoice == 3) {
                        Event updatedEvent;
                        cout << "Enter Event Name to update: ";
                        cin >> updatedEvent.name;
                        cout << "Enter Event Type: ";
                        cin >> updatedEvent.type;
                        cout << "Enter Event Location: ";
                        cin >> updatedEvent.location;
                        cout << "Enter Event Date: ";
                        cin >> updatedEvent.date;
                        cout << "Enter Available Tickets: ";
                        cin >> updatedEvent.availableTickets;
                        cout << "Enter Ticket Price: ";
                        cin >> updatedEvent.price;
                        eventSystem.updateEvent(updatedEvent);
                        eventSystem.saveEventsToFile("events.txt"); // Save changes to file
                    }
                    else if (adminChoice == 4) {
                        eventSystem.browseEvents();
                    }
                    else if (adminChoice == 5) {
                        break;
                    }
                    else {
                        cout << "Invalid choice! Please try again." << endl;
                    }
                }
            }
            else {
                cout << "Invalid admin credentials. Please try again." << endl;
            }
        }
        else if (choice == 2) {
            string username, password;
            cout << "Enter User Username: ";
            cin >> username;
            cout << "Enter User Password: ";
            cin >> password;

            if (eventSystem.userLogin(username, password)) {
                cout << "User login successful!" << endl;
                int userChoice;
                while (true) {
                    cout << "User Options:" << endl;
                    cout << "1. Browse Events" << endl;
                    cout << "2. Search Events" << endl;
                    cout << "3. Book Tickets" << endl;
                    cout << "4. Return to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> userChoice;

                    if (userChoice == 1) {
                        eventSystem.browseEvents();
                    }
                    else if (userChoice == 2) {
                        string criteria;
                        cout << "Enter search criteria (name, type, location, date): ";
                        cin >> criteria;
                        eventSystem.searchEvents(criteria);
                    }
                    else if (userChoice == 3) {
                        string eventName;
                        int numTickets;
                        cout << "Enter Event Name to book tickets: ";
                        cin >> eventName;
                        cout << "Enter number of tickets: ";
                        cin >> numTickets;
                        eventSystem.bookTicket(eventName, numTickets);
                        eventSystem.saveEventsToFile("events.txt"); // Save changes to file
                    }
                    else if (userChoice == 4) {
                        break;
                    }
                    else {
                        cout << "Invalid choice! Please try again." << endl;
                    }
                }
            }
            else {
                cout << "Invalid user credentials. Please try again." << endl;
            }
        }
        else if (choice == 3) {
            string username, password;
            cout << "Enter a new Username: ";
            cin >> username;
            cout << "Enter a new Password: ";
            cin >> password;

            if (eventSystem.userSignUp(username, password)) {
                cout << "User signed up successfully!" << endl;
            }
            else {
                cout << "Username already taken. Please try again." << endl;
            }
        }
        else if (choice == 4) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
