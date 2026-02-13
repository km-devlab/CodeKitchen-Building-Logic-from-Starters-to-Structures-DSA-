
/*
🍽️ Dish Name: Armstrong Number Checker

🧠 Problem Statement:
Check whether a number is an Armstrong number.

📌 Armstrong Rule:
A number is Armstrong if the sum of its digits
each raised to the power of total digits equals the number.

📌 Concepts Used:
- Functions
- Digit extraction
- Power function (pow)
- While loop

🍳 Approach (Chef’s Recipe):
1. Count total digits.
2. Extract each digit using % 10.
3. Raise digit to power of digit count.
4. Add to sum.
5. Compare sum with original number.

🧩 Example:
Input: 153
Output: Yes

⏱ Time Complexity:
O(d)  (d = number of digits)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Main Course 🍝 → Number Theory
*/
#include <iostream>
#include <cmath>
using namespace std;

int length(int n)
{
    int count = 0;
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

bool isArmstrong(int n)
{
    int temp = n;
    int sum = 0;
    int count = length(n);

    while (temp > 0)
    {
        int digit = temp % 10;
        sum += (int)pow(digit, count);//pow() returns double.
        temp /= 10;
    }

    return (sum == n);
}

int main()
{
    int n;
    cin >> n;

    if (isArmstrong(n))
        cout << "Yes, it is an Armstrong number";
    else
        cout << "Not an Armstrong number";

    return 0;
}

