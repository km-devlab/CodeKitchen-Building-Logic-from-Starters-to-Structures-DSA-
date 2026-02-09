/*
🍽️ Dish Name: Finding All Factors of a Number

🧠 Problem Statement:
Given a number n, print all its positive factors.

📌 Concepts Used:
- Loops
- Modulus operator
- Mathematical optimization using √n

🍳 Approach (Chef’s Recipe):
1. Loop from 1 to √n.
2. If i divides n, then both i and (n / i) are factors.
3. Print both values.
4. If both factors are equal, print it only once.

⚡ Optimization Insight:
- Factors occur in pairs
- Checking beyond √n is unnecessary

👩‍🍳 Category in Repo:
Starters → Loops & Numbers
*/

#include <iostream>

using namespace std;

int main()
{
    int n;
    // Prompt user for input
    cout << "Enter a number to find its factors: "; 
    cin >> n;

    cout << "Factors of " << n << " are: ";
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl; // Add a newline for cleaner output

    return 0;
}

//or optimized

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
                cout << i << " ";
            else
                cout << i << " " << n / i << " ";
        }
    }

    return 0;
}


