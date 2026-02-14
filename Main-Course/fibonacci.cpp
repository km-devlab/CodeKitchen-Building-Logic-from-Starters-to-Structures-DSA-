/*
🍽️ Dish Name: Fibonacci Series

🧠 Problem Statement:
Print the first n terms of the Fibonacci sequence.

📌 Fibonacci Rule:
Each number is the sum of the previous two numbers.

📌 Concepts Used:
- Loops
- Variable swapping
- Sequence generation

🍳 Approach (Chef’s Recipe):
1. Initialize first two numbers as 0 and 1.
2. Print them.
3. Generate next number as sum of previous two.
4. Update variables.
5. Repeat until n terms are printed.

🧩 Example:
Input: 7
Output: 0 1 1 2 3 5 8

⏱ Time Complexity:
O(n)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Main Course 🍝 → Sequences
*/

#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int a = 0, b = 1, next;
    /*If user enters:1
    Your original code would still print 0 1, which is wrong.
    Now it's safe for:
    1 term
    2 terms
    N terms*/

    if (num >= 1) cout << a << " ";
    if (num >= 2) cout << b << " ";

    for (int i = 3; i <= num; i++)
    {
        next = a + b;
        cout << next << " ";
        a = b;
        b = next;
    }

    return 0;
}

