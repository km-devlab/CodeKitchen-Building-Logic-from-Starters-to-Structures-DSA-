/*
=========================================================
🍿 LEETCODE SNACKABLES
Problem: Convert Number to Words (0–9999)
Difficulty: Easy–Medium
Concepts Used:
- Division & Modulo
- String building
- Greedy decomposition

---------------------------------------------------------
🧠 Problem Understanding:
Given a number (as string), convert it into words.

Example:
1234 → "one thousand two hundred thirty four"

---------------------------------------------------------
💡 Core Idea:

Break the number into parts:
1. Thousands
2. Hundreds
3. Tens & Ones

We process each part separately and build the result.

---------------------------------------------------------
📦 Predefined Word Arrays:

ones[]   → 1 to 9
teens[]  → 10 to 19
tens[]   → 20,30,...90

---------------------------------------------------------
🔢 Step-by-Step Breakdown:

1. Convert string → integer using stoi()
2. Handle special case: n == 0 → "zero"

3. Extract thousands:
   thous = n / 1000

4. Extract hundreds:
   hundred = (n % 1000) / 100

5. Extract tens & ones:
   n % 100

---------------------------------------------------------
⚡ Important Logic:

Case 1: 10–19
→ Directly use teens array

Case 2: >= 20
→ Use tens + ones separately

---------------------------------------------------------
🧠 String Building Trick:

if(result != "") result += " ";

This ensures:
- No extra spaces at start
- Proper spacing between words

=========================================================
*/

#include <bits/stdc++.h>
using namespace std;

void convertNumIntoWord(string str) {
    
    int n = stoi(str);

    string ones[]  = {"","one","two","three","four","five","six","seven","eight","nine"};
    string teens[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen",
                      "sixteen","seventeen","eighteen","nineteen"};
    string tens[]  = {"","","twenty","thirty","forty","fifty",
                      "sixty","seventy","eighty","ninety"};

    string result = "";

    // Special case
    if(n == 0)
    {
        cout << "zero";
        return;
    }

    // Thousands
    int thous = n / 1000;
    if(thous > 0)
    {
        result += ones[thous] + " thousand";
    }

    n %= 1000;

    // Hundreds
    int hundred = n / 100;
    if(hundred > 0)
    {
        if(result != "") result += " ";
        result += ones[hundred] + " hundred";
    }

    n %= 100;

    // Tens and Ones
    if(n >= 10 && n < 20)
    {
        if(result != "") result += " ";
        result += teens[n - 10];
    }
    else
    {
        int tens_digit = n / 10;
        int ones_digit = n % 10;

        if(tens_digit > 0)
        {
            if(result != "") result += " ";
            result += tens[tens_digit];
        }

        if(ones_digit > 0)
        {
            if(result != "") result += " ";
            result += ones[ones_digit];
        }
    }

    cout << result;
}
