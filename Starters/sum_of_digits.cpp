/*
🍽️ Dish Name: Sum of Digits

🧠 Problem Statement:
Given a number n, calculate the sum of its digits.

📌 Concepts Used:
- While loop
- Modulus operator (%)
- Integer division

🍳 Approach (Chef’s Recipe):
1. Store original number in a temporary variable.
2. Extract last digit using % 10.
3. Add digit to sum.
4. Remove last digit using / 10.
5. Repeat until number becomes 0.

🧩 Example:
Input: 1234
Output: 10

⏱ Time Complexity:
O(d)  (d = number of digits)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Starters 🥗 → Number Basics
*/

#include<iostream>
using namespace std;
int main()
{
int n;int sum=0;
cin>>n;
while(n>0)
{
sum+=n%10;
n/=10;
}
cout<<"Sum is "<<sum;
return 0;
}
