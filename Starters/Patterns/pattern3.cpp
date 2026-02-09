/*
🍽️ Dish Name: Number Triangle Pattern

🧠 Problem Statement:
Given a number n, print a right-angled triangle where each row
contains numbers from 1 up to the row number.

📌 Concepts Used:
- Nested loops
- Pattern printing
- Loop variables

🍳 Approach (Chef’s Recipe):
1. Use an outer loop to control rows.
2. Use an inner loop to print numbers from 1 to current row.
3. Move to the next line after completing each row.

🧩 Pattern Visualization:
For n = 4

1
12
123
1234

⏱ Time Complexity:
O(n²)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Appetizers / Starters 🥗 → Pattern Printing
*/

#include <iostream>
using namespace std;

void printpattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printpattern3(n);
    return 0;
}

