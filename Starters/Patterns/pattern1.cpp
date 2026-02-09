/*🍽️ Dish Name: Square Star Pattern

🧠 Problem Statement:
Given a number n, print an n × n square pattern using asterisks (*).

📌 Concepts Used:
- Nested loops
- Functions
- Pattern printing basics

🍳 Approach (Chef’s Recipe):
1. Use an outer loop to control rows.
2. Use an inner loop to print n stars in each row.
3. Move to the next line after each row.

🧩 Pattern Visualization:
For n = 3

***
***
***

⏱ Time Complexity:
O(n²)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Appetizers / Starters 🥗 → Pattern Printing
*/

#include<iostream>
using namespace std;
void printpattern1(int n)
{
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<"* ";
}
cout<<endl;
}
}
int main()
{
int n;
cin>>n;
printpattern1(n);
return 0;
}

