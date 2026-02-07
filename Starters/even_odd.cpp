/*
🍽️ CodeKitchen

Dish Name      : Even or Odd
Course         : 🥗 Appetizers / Starters — Seasoning Logic & Control Flow
Difficulty     : Beginner

Description:
This program checks whether a given integer is even or odd using
the ternary (conditional) operator.

It introduces a concise way to make decisions in C++.

Concepts Used:
- Input and Output (cin / cout)
- Modulus operator (%)
- Ternary operator (?:)

How to Approach:
1. Read an integer input
2. Use the modulus operator to check divisibility by 2
3. Print the result using a ternary condition
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    n % 2 == 0 ? cout << "Even" : cout << "Odd";

    return 0;
}

