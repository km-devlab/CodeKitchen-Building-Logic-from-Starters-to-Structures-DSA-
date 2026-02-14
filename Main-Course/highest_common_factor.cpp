/*
🍽️ Dish Name: GCD (Greatest Common Divisor)

🧠 Problem Statement:
Find the greatest common divisor of two numbers.

📌 Concepts Used:
- Loops
- Modulus operator
- Euclidean Algorithm

🍳 Approach (Chef’s Recipe):
1. Repeatedly replace (a, b) with (b, a % b).
2. Continue until b becomes 0.
3. The remaining value of a is the GCD.

🧩 Example:
Input: 12 18
Output: 6

⏱ Time Complexity:
O(log n)  (Euclidean Method)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Main Course 🍝 → Number Theory
*/

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cin >> num1 >> num2;

    int hcf = 1;

    for(int i = 1; i <= num1 && i <= num2; i++)
    {
        if(num1 % i == 0 && num2 % i == 0)
        {
            hcf = i;   // store the common factor
        }
    }

    cout << "HCF = " << hcf;

    return 0;
}

