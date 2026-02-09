/*
🍽️ Dish Name: Prime Factorization (Main Course)

🧠 Problem Statement:
Given a number n, print all its prime factors.

📌 Concept Used:
- Number Theory
- Prime Factorization
- Loops and Conditional Statements

🍳 Approach (Chef’s Recipe):
1. Repeatedly divide the number by 2 to remove all even factors.
2. Check only odd numbers starting from 3 up to √n.
3. For every divisor found, print it and reduce n.
4. If a number greater than 1 remains, it is also a prime factor.

⚡ Optimization Tricks:
- Loop only till √n
- Skip even numbers after handling 2
- Reduce n continuously to avoid extra checks
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Handle factor 2
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }

    // Handle odd factors
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
    }

    // If remaining number is prime
    if (n > 1)
        cout << n;

    return 0;
}


