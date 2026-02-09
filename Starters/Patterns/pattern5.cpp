/*
🍽️ Dish Name: Inverted Right-Angled Star Triangle

🧠 Problem Statement:
Given a number n, print an inverted right-angled triangle using stars (*).

📌 Concepts Used:
- Nested loops
- Pattern printing
- Loop decrementing

🍳 Approach (Chef’s Recipe):
1. Start the outer loop from n and decrease it each time.
2. Inner loop prints stars equal to the current row count.
3. Move to the next line after each row.

🧩 Pattern Visualization:
For n = 4

****
***
**
*

⏱ Time Complexity:
O(n²)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Appetizers / Starters 🥗 → Pattern Printing
*/

#include <iostream>
using namespace std;

void printpattern5(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printpattern5(n);
    return 0;
}

