/*
=========================================================
🍿 LEETCODE SNACKABLES
Problem: Add Binary
Difficulty: Easy
Concepts Used:
- String traversal (right to left)
- Carry handling
- Character to integer conversion ('0' logic)

---------------------------------------------------------
🧠 Problem Understanding:
We are given two binary strings (only 0s and 1s).
We need to return their sum as a binary string.

Important:
We CANNOT use stoi() because it converts to decimal.
We must manually simulate binary addition.

---------------------------------------------------------
💡 Core Idea:
Binary addition works just like normal addition:

0 + 0 = 0
0 + 1 = 1
1 + 1 = 0 (carry 1)
1 + 1 + 1 = 1 (carry 1)

So we:
1. Start from the last digit (rightmost).
2. Add both digits + carry.
3. Store sum % 2.
4. Update carry = sum / 2.
5. Continue until everything is processed.

---------------------------------------------------------
🔑 Important Trick:
a[i] - '0'

Why?
Characters are stored as ASCII values.
'1' - '0' = 1
'0' - '0' = 0

This converts char → integer.

=========================================================
*/

#include <iostream>
using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    // Loop until both strings are finished AND carry is 0
    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        // Add digit from string a if available
        if(i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }

        // Add digit from string b if available
        if(j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }

        // Current binary digit
        result = char((sum % 2) + '0') + result;

        // Update carry
        carry = sum / 2;
    }

    return result;
}
