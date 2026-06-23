/*
===========================================================
                TEXT EDITOR WITH UNDO IN C++
===========================================================

PROJECT DESCRIPTION
-------------------
This project is a simple console-based Text Editor built
using C++. It allows the user to perform basic text editing
operations such as:

1. Add text
2. Delete last characters
3. View current text
4. Undo last action
5. Clear all text
6. Exit

The main highlight of this project is the UNDO feature,
which is implemented using the STL stack container.

Whenever the text is modified, the previous version of the
text is stored in a stack. If the user selects Undo, the
latest saved state is restored.

===========================================================
OBJECTIVES
===========================================================

1. To create a simple text editor in C++
2. To demonstrate the use of STL stack
3. To implement undo functionality
4. To practice strings, classes, and menu-driven programs

===========================================================
OOP CONCEPTS USED
===========================================================

1. CLASS AND OBJECT
   - TextEditor is a class
   - editor is an object of the class

2. ENCAPSULATION
   - Current text and undo history are stored inside the class

3. ABSTRACTION
   - All editor operations are provided through member functions

===========================================================
STL USED
===========================================================

1. stack<string>
   - Used to store previous versions of the text
   - Helps implement Undo using LIFO (Last In First Out)

===========================================================
FEATURES
===========================================================

1. Add Text
2. Delete Last N Characters
3. View Current Text
4. Undo Last Action
5. Clear All Text
6. Exit

===========================================================
HOW UNDO WORKS
===========================================================

Before every change to the text:
- the current text is pushed into the stack

When Undo is selected:
- the top element from the stack is restored
- this returns the editor to its previous state

===========================================================
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class TextEditor {
private:
    string currentText;
    stack<string> undoHistory;

public:
    // Constructor
    TextEditor() {
        currentText = "";
    }

    // Save current state before making any change
    void saveState() {
        undoHistory.push(currentText);
    }

    // Add text at the end
    void addText() {
        string newText;

        cout << "\nEnter text to add: ";
        cin.ignore();
        getline(cin, newText);

        saveState();
        currentText += newText;

        cout << "Text added successfully.\n";
    }

    // Delete last n characters
    void deleteText() {
        if (currentText.empty()) {
            cout << "\nText is already empty.\n";
            return;
        }

        int n;
        cout << "\nEnter number of characters to delete: ";
        cin >> n;

        if (n <= 0) {
            cout << "Please enter a valid positive number.\n";
            return;
        }

        if (n > currentText.length()) {
            n = currentText.length();
        }

        saveState();
        currentText.erase(currentText.length() - n, n);

        cout << n << " character(s) deleted successfully.\n";
    }

    // Show current text
    void viewText() const {
        cout << "\n========== CURRENT TEXT ==========\n";
        if (currentText.empty()) {
            cout << "[Empty]\n";
        } else {
            cout << currentText << endl;
        }
    }

    // Undo last action
    void undo() {
        if (undoHistory.empty()) {
            cout << "\nNo action to undo.\n";
            return;
        }

        currentText = undoHistory.top();
        undoHistory.pop();

        cout << "Undo successful.\n";
    }

    // Clear all text
    void clearText() {
        if (currentText.empty()) {
            cout << "\nText is already empty.\n";
            return;
        }

        saveState();
        currentText.clear();

        cout << "All text cleared successfully.\n";
    }
};

int main() {
    TextEditor editor;
    int choice;

    do {
        cout << "\n\n=====================================\n";
        cout << "         TEXT EDITOR WITH UNDO\n";
        cout << "=====================================\n";
        cout << "1. Add Text\n";
        cout << "2. Delete Last N Characters\n";
        cout << "3. View Current Text\n";
        cout << "4. Undo Last Action\n";
        cout << "5. Clear All Text\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                editor.addText();
                break;

            case 2:
                editor.deleteText();
                break;

            case 3:
                editor.viewText();
                break;

            case 4:
                editor.undo();
                break;

            case 5:
                editor.clearText();
                break;

            case 6:
                cout << "\nExiting Text Editor...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
