/*
🍽️ CodeKitchen

Dish Name      : Largest of Two Numbers
Course         : 🥗 Appetizers / Starters — Comparing Ingredients (Values)
Difficulty     : Beginner

Description:
This program compares two integers and determines which one is larger
or if both values are equal.

The problem is solved using multiple approaches to demonstrate
different decision-making techniques in C++.

Concepts Used:
- Input and Output
- Conditional statements
- Relational operators
- Ternary operator
- Standard library function

How to Approach:
- Compare values using if–else
- Use ternary operator for compact logic
- Use built-in functions for readability
*/
✅ Approach 1: Using if–else (Classic & Clear)

#include<iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if(x > y)
        cout << "x is the largest";
    else if(x < y)
        cout << "y is the largest";
    else
        cout << "Both are equal";

    return 0;
}

//or

✅ Approach 2: Using Ternary Operator (Compact Logic)

#include<iostream>
using namespace std;

int main()
{
    int x, y, largest;
    cin >> x >> y;

    if(x == y)
        cout << "Both are equal";
    else
    {
        largest = (x > y) ? x : y;
        cout << largest << " is the largest";
    }

    return 0;
}


//or

✅ Approach 3: Using Built-in max() Function

#include<iostream>
#include<algorithm>  // for max()
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if(x == y)
        cout << "Both are equal";
    else
        cout << max(x, y) << " is the largest";

    return 0;
}


