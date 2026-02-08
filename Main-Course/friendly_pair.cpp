/*
🍽️ CodeKitchen

Dish Name      : Friendly Pair Numbers
Course         : 🍝 Main Course — Number Theory & Function Decomposition
Difficulty     : Beginner → Intermediate

Description:
This program checks whether two given numbers form a Friendly Pair.

Two numbers are called a Friendly Pair if the ratio of the sum of
their proper divisors to the number itself is equal.

Concepts Used:
- Functions
- Loops
- Conditional statements
- Proper divisors
- Modular arithmetic

How to Approach:
1. Create a function to calculate the sum of proper divisors
2. Compute divisor sums for both numbers
3. Compare their divisor ratios
4. Display the result
*/

#include<iostream>
using namespace std;

int divisorsSum(int n)
{
    int sum = 0;
    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int x, y;
    cin >> x >> y;

    int sum1 = divisorsSum(x);
    int sum2 = divisorsSum(y);

    if((float)sum1 / x == (float)sum2 / y)
        cout << x << " and " << y << " are a friendly pair";
    else
        cout << "Not a friendly pair";

    return 0;
}

