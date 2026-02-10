/*
🍽️ Dish Name: Full Pyramid Star Pattern

🧠 Problem Statement:
Given a number n, print a centered pyramid pattern using stars (*).

📌 Concepts Used:
- Nested loops
- Pattern printing
- Space and symbol management

🍳 Approach (Chef’s Recipe):
1. Outer loop controls the number of rows.
2. First inner loop prints leading spaces to center the pyramid.
3. Second inner loop prints stars in the formula (2*i - 1).
4. Move to the next line after each row.

🧩 Pattern Visualization:
For n = 4

   *
  ***
 *****
*******

⏱ Time Complexity:
O(n²)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Main Course 🍝 → Pattern Printing
*/
#include <iostream>
using namespace std;

void printpattern7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // Print spaces
        for (int space = 1; space <= n - i; space++)
        {
            cout << " ";
        }

        // Print stars
        for (int symbol = 1; symbol <= 2 * i - 1; symbol++)
        {
            cout << "*";
        }

        cout << endl; // Move to next line
    }
}

int main()
{
    int n;
    cin >> n;
    printpattern7(n);
    return 0;
}
