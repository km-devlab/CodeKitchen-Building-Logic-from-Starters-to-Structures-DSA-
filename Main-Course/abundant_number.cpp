/*
🍽️ CodeKitchen

Dish Name      : Abundant Number
Course         : 🍝 Main Course — Exploring Number Properties
Difficulty     : Beginner → Intermediate

Description:
This program checks whether a given number is an Abundant Number.

A number is called abundant if the sum of its proper divisors
(excluding the number itself) is greater than the number.

Concepts Used:
- Loops
- Conditional statements
- Proper divisors
- Arithmetic operations

How to Approach:
1. Read an integer input
2. Find the sum of all proper divisors
3. Compare the sum with the original number
4. Display the result
*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }

    if(sum > n)
        cout << n << " is an Abundant number.";
    else
        cout << n << " is not an Abundant number.";

    return 0;
}

