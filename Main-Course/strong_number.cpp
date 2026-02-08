/*
🍽️ CodeKitchen

Dish Name      : Strong Number
Course         : 🍝 Main Course — Digit Analysis & Factorial Logic
Difficulty     : Beginner → Intermediate

Description:
This program checks whether a given number is a Strong Number.

A number is called a Strong Number if the sum of the factorials
of its digits is equal to the number itself.

Concepts Used:
- Functions
- Loops (for, while)
- Factorial computation
- Digit extraction
- Conditional statements

How to Approach:
1. Create a function to compute factorial of a digit
2. Extract each digit of the number
3. Calculate factorial of each digit
4. Sum the factorials and compare with the original number
*/

#include<iostream>
using namespace std;

int facto(int n)
{
    int fact = 1;
    for(int i = n; i >= 1; i--)
    {
        fact *= i;
    }
    return fact;
}

int main()
{
    int num, sum = 0;
    cin >> num;

    int temp = num;
    while(temp > 0)
    {
        int digit = temp % 10;
        sum += facto(digit);
        temp /= 10;
    }

    if(sum == num)
        cout << num << " is a Strong Number";
    else
        cout << num << " is not a Strong Number";

    return 0;
}

