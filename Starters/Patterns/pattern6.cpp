/*
🍽️ Dish Name: Inverted Number Triangle

🧠 Problem Statement:
Given a number n, print an inverted right-angled triangle
using numbers from 1 to the row length.

📌 Concepts Used:
- Nested loops
- Pattern printing
- Loop decrementing

🍳 Approach (Chef’s Recipe):
1. Use an outer loop starting from n and decrement it each time.
2. Inner loop prints numbers from 1 up to the current row count.
3. Move to the next line after completing each row.

🧩 Pattern Visualization:
For n = 4

1234
123
12
1

⏱ Time Complexity:
O(n²)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Appetizers / Starters 🥗 → Pattern Printing
*/

#include<iostream>
using namespace std;
void printpattern6(int n)
{
for(int i=n;i>=1;i--)
{
for(int j=1;j<=i;j++)
{
cout<<j;
}
cout<<endl;
}
}
int main()
{
int n;
cin>>n;
printpattern6(n);
return 0;
}
