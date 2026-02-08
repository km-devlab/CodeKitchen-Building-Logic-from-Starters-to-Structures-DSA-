/*
🍽️ CodeKitchen

Dish Name      : Perfect Square Checker
Course         : 🍝 Main Course — Mathematical Reasoning & Helper Functions
Difficulty     : Beginner → Intermediate

Description:
This program checks whether a given number is a perfect square.

A number is a perfect square if it can be expressed as the square
of an integer.

Concepts Used:
- Functions
- Conditional statements
- Square root calculation
- Boolean logic

How to Approach:
1. Compute the square root of the number
2. Convert it to an integer
3. Check whether squaring it gives the original number
*/
#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long x)
{
    if(x >= 0)
    {
        long sq = sqrt(x);
        return (sq * sq == x);
    }
    return false;
}

int main()
{
    int num;
    cin >> num;

    if(isPerfectSquare(num))
        cout << "True";
    else
        cout << "False";

    return 0;
}

