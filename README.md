# Grocery Tracker

## Project Overview

The Grocery Tracker application is designed to read a list of grocery items from an input file and track the frequency of each item. It helps users manage and analyze grocery data by allowing them to:
- Find the frequency of specific items.
- Print the list of all items with their frequencies.
- Visualize the data in the form of a histogram.

This program helps users keep track of their grocery purchases and analyze their buying habits.

## Features

1. **Find the frequency of a specific item**: Users can input an item and find out how many times it appears in the list.
2. **Print the frequency of all items**: Users can print a list of all items and their frequencies.
3. **Print the histogram of all items**: Users can visualize the frequency of items in a histogram format.
4. **Backup File Creation**: The program creates a backup file containing item frequencies for future reference.

## Implementation Details

### What Was Done Well

- Designed a user-friendly and intuitive menu-driven interface.
- Used a map to store item frequencies, ensuring efficient data retrieval.

### Potential Enhancements

- **Error Handling**: Adding robust error handling for file I/O and user input to make the code more resilient.
- **Optimization**: Improving file I/O operations for better performance.
- **Security**: Implementing input validation to prevent security issues like buffer overflows or injection attacks.

These enhancements would make the code more efficient, secure, and user-friendly.

### Challenges and Solutions

The most challenging part was implementing the histogram printing function. Ensuring that the histogram was visually appealing and correctly represented the item frequencies required careful attention to detail. This was overcome by incrementally testing and refining the function to ensure accuracy.

### Tools and Resources Added

- **Version Control**: Git for version control to manage changes and collaborate more effectively.
- **Debugging Tools**: GDB for identifying and fixing issues more efficiently.
- **Online Resources**: Coding communities like Stack Overflow and GitHub for advice and knowledge sharing.

### Transferable Skills

- **File I/O Operations**: Reading from and writing to files.
- **Data Structures**: Using maps for efficient data storage and retrieval.
- **User Interface Design**: Creating intuitive and user-friendly interfaces.

### Code Maintainability

- **Modular Design**: Encapsulating functionality within a class and breaking down tasks into smaller functions.
- **Comments and Documentation**: Including comments and clear documentation.
- **Consistent Formatting**: Adhering to consistent coding standards and formatting.

## Code Implementation

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

// Class definition for GroceryTracker
class GroceryTracker {
public:
    GroceryTracker(const string& inputFileName, const string& backupFileName);
    void displayMenu();
    void handleUserChoice();
private:
    map<string, int> items;
    string backupFileName;
    void readDataFile(const string& filename);
    void createBackupFile();
    void findItemFrequency();
    void printItemList();
    void printHistogram();
};

// Constructor implementation
GroceryTracker::GroceryTracker(const string& inputFileName, const string& backupFileName) : backupFileName(backupFileName) {
    readDataFile(inputFileName);
    createBackupFile();
}

void GroceryTracker::readDataFile(const string& filename) {
    ifstream infile(filename);
    string item;

    while (infile >> item) {
        items[item]++;
    }

    infile.close();
}

void GroceryTracker::createBackupFile() {
    ofstream outfile(backupFileName);

    for (const auto& item : items) {
        outfile << item.first << " " << item.second << endl;
    }

    outfile.close();
}

void GroceryTracker::displayMenu() {
    cout << "Menu Options:" << endl;
    cout << "1. Find the frequency of a specific item" << endl;
    cout << "2. Print the frequency of all items" << endl;
    cout << "3. Print the histogram of all items" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

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

void GroceryTracker::printItemList() {
    for (const auto& item : items) {
        cout << item.first << " " << item.second << endl;
    }
}

void GroceryTracker::printHistogram() {
    for (const auto& item : items) {
        cout << item.first << " ";
        for (int i = 0; i < item.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    tracker.handleUserChoice();
    return 0;
}
