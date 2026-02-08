/*
🍽️ CodeKitchen

Dish Name      : Perfect Number
Course         : 🍝 Main Course — Divisor Analysis & Number Classification
Difficulty     : Beginner → Intermediate

Description:
This program checks whether a given number is a Perfect Number.

A number is called perfect if the sum of its proper divisors
(excluding the number itself) is equal to the number.

Concepts Used:
- Loops
- Conditional statements
- Proper divisors
- Arithmetic operations

How to Approach:
1. Read an integer input
2. Find all proper divisors of the number
3. Calculate their sum
4. Compare the sum with the original number
*/

#include<iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int sum = 0;
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0)
            sum += i;
    }

    if(sum == num)
        cout << num << " is a Perfect Number";
    else
        cout << num << " is not a Perfect Number";

    return 0;
}

