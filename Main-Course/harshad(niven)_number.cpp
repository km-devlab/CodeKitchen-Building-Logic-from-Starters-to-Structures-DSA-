/*
🍽️ CodeKitchen

Dish Name      : Harshad (Niven) Number
Course         : 🍝 Main Course — Digit Manipulation & Number Properties
Difficulty     : Beginner → Intermediate

Description:
This program checks whether a given number is a Harshad (Niven) Number.

A number is called a Harshad Number if it is divisible by the sum
of its digits.

Concepts Used:
- Loops (while)
- Modulus and division operators
- Digit extraction
- Conditional statements

How to Approach:
1. Read an integer input
2. Extract digits using modulus operator
3. Calculate the sum of digits
4. Check divisibility of the original number by the digit sum
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    int temp = n;

    while(temp > 0)
    {
        sum += temp % 10;
        temp /= 10;
    }

    if(n % sum == 0)
        cout << "It is a Harshad Number";
    else
        cout << "Not a Harshad Number";

    return 0;
}

