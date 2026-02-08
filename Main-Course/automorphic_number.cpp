/*
🍽️ CodeKitchen

Dish Name      : Automorphic Number
Course         : 🍝 Main Course — Digit Comparison & Number Properties
Difficulty     : Beginner → Intermediate

Description:
This program checks whether a given number is an Automorphic Number.

A number is called automorphic if its square ends with the same
digits as the number itself.

Concepts Used:
- Loops (while)
- Modulus and division operators
- Boolean flags
- Digit-by-digit comparison

How to Approach:
1. Square the given number
2. Compare the last digits of the number and its square
3. Continue digit comparison until all digits are checked
4. Decide based on matching digits
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool isAutomorphic = true;
    int square = n * n;
    int temp = n;

    while(temp > 0)
    {
        if(temp % 10 != square % 10)
        {
            isAutomorphic = false;
            break;
        }
        temp /= 10;
        square /= 10;
    }

    if(isAutomorphic)
        cout << "It is an Automorphic number";
    else
        cout << "Not an Automorphic number";

    return 0;
}

