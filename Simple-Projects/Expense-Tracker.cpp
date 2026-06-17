
/*
=====================================
        EXPENSE TRACKER
=====================================

Features:
1. Add Expense
2. View Expenses
3. Calculate Total Expenses
4. Exit

Concepts Used:
- Classes and Objects
- Arrays
- Loops
- Functions
=====================================
*/

#include <iostream>
using namespace std;

class ExpenseTracker {
private:
    string expenseName[100];
    float amount[100];
    int count;

public:
    ExpenseTracker() {
        count = 0;
    }

    void addExpense() {
        cout << "\nEnter Expense Name: ";
        cin >> expenseName[count];

        cout << "Enter Amount: ";
        cin >> amount[count];

        count++;

        cout << "Expense Added Successfully!\n";
    }

    void viewExpenses() {
        if(count == 0) {
            cout << "\nNo Expenses Recorded!\n";
            return;
        }

        cout << "\n===== EXPENSE LIST =====\n";

        for(int i = 0; i < count; i++) {
            cout << i + 1 << ". "
                 << expenseName[i]
                 << " - Rs." << amount[i] << endl;
        }
    }

    void totalExpense() {
        float total = 0;

        for(int i = 0; i < count; i++) {
            total += amount[i];
        }

        cout << "\nTotal Expenses = Rs." << total << endl;
    }
};

int main() {

    ExpenseTracker tracker;
    int choice;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Calculate Total Expense\n";
        cout << "4. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                tracker.addExpense();
                break;

            case 2:
                tracker.viewExpenses();
                break;

            case 3:
                tracker.totalExpense();
                break;

            case 4:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}
