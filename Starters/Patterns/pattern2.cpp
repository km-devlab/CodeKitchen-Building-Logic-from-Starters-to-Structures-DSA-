/*

🍽️ Dish Name: Right-Angled Star Triangle

🧠 Problem Statement:
Given a number n, print a right-angled triangle pattern using stars (*).

📌 Concepts Used:
- Nested loops
- Pattern printing
- Loop counters

🍳 Approach (Chef’s Recipe):
1. Outer loop controls the number of rows.
2. Inner loop prints stars equal to the current row number.
3. Move to the next line after each row.

🧩 Pattern Visualization:
For n = 4

*
**
***
****

⏱ Time Complexity:
O(n²)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Appetizers / Starters 🥗 → Pattern Printing
*/

#include <iostream>
using namespace std;

void printpattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
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
    printpattern2(n);
    return 0;
}

