/*
🍽️ CodeKitchen

Dish Name      : Positive, Negative or Zero
Course         : 🥗 Appetizers / Starters — Seasoning Logic & Control Flow
Difficulty     : Beginner

Description:
This program takes an integer as input and determines whether the number
is positive, negative, or zero.

Concepts Used:
- Input and Output
- Conditional statements
*/

#include<iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;

    if(x > 0)
        cout << "Positive\n";
    else if(x < 0)
        cout << "Negative\n";
    else
        cout << "Zero\n";

    return 0;
}
