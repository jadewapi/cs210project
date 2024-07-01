#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

//jade pineda
//snhu
//do not copy

using namespace std;

// Class definition for GroceryTracker
class GroceryTracker {
public:
    // Constructor to initialize and read data file
    GroceryTracker(const string& inputFileName, const string& backupFileName);
    // Function to display the menu
    void displayMenu();
    // Function to handle user input and perform corresponding actions
    void handleUserChoice();
private:
    map<string, int> items; // Map to store item frequencies
    string backupFileName; // Backup file name

    // Function to read data from the input file and populate the map
    void readDataFile(const string& filename);
    // Function to create a backup file with item frequencies
    void createBackupFile();
    // Function to find and print the frequency of a specific item
    void findItemFrequency();
    // Function to print the list of all items and their frequencies
    void printItemList();
    // Function to print the histogram of all items
    void printHistogram();
};

// Constructor implementation
GroceryTracker::GroceryTracker(const string& inputFileName, const string& backupFileName) : backupFileName(backupFileName) {
    readDataFile(inputFileName);
    createBackupFile();
}

// Function to read data from a file and populate the map
void GroceryTracker::readDataFile(const string& filename) {
    ifstream infile(filename);
    string item;

    while (infile >> item) {
        items[item]++;
    }

    infile.close();
}

// Function to create a backup file with item frequencies
void GroceryTracker::createBackupFile() {
    ofstream outfile(backupFileName);

    for (const auto& item : items) {
        outfile << item.first << " " << item.second << endl;
    }

    outfile.close();
}

// Function to display the menu
void GroceryTracker::displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Find the frequency of a specific item" << endl;
    cout << "2. Print the frequency of all items" << endl;
    cout << "3. Print the histogram of all items" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to handle user input and perform corresponding actions
void GroceryTracker::handleUserChoice() {
    int choice = 0;
    while (choice != 4) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                findItemFrequency();
                break;
            case 2:
                printItemList();
                break;
            case 3:
                printHistogram();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please choose again." << endl;
        }
    }
}

// Function to find and print the frequency of a specific item
void GroceryTracker::findItemFrequency() {
    string item;
    cout << "Enter the item you want to find: ";
    cin >> item;

    auto it = items.find(item);
    if (it != items.end()) {
        cout << item << " appears " << it->second << " times." << endl;
    } else {
        cout << item << " does not appear in the list." << endl;
    }
}

// Function to print the list of all items and their frequencies
void GroceryTracker::printItemList() {
    for (const auto& item : items) {
        cout << item.first << " " << item.second << endl;
    }
}

// Function to print the histogram of all items
void GroceryTracker::printHistogram() {
    for (const auto& item : items) {
        cout << item.first << " ";
        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Main function to create a GroceryTracker object and handle user choices
int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    tracker.handleUserChoice();
    return 0;
}
