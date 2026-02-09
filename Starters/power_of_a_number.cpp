/*
🍽️ Dish Name: Power of a Number

🧠 Problem Statement:
Given a base and an exponent, compute base raised to the power exponent.

📌 Concepts Used:
- Loops
- Conditional statements
- Handling negative powers

🍳 Approach (Chef’s Recipe):
1. Initialize result as 1.
2. If exponent is positive, multiply base repeatedly.
3. If exponent is negative, divide base repeatedly.
4. Use double to support fractional results.

⚡ Important Note:
- Negative powers produce decimal values
- Integer result type will cause incorrect output

👩‍🍳 Category in Repo:
Starters → Loops & Math Basics
*/

#include <iostream>
using namespace std;

int main()
{
    int base, exp;
    cin >> base >> exp;

    double result = 1.0;

    if (exp >= 0)
    {
        while (exp > 0)
        {
            result *= base;
            exp--;
        }
    }
    else
    {
        while (exp < 0)
        {
            result /= base;
            exp++;
        }
    }

    cout << result;
    return 0;
}

