/*
🍽️ CodeKitchen

Dish Name      : Largest of Three Numbers
Course         : 🥗 Appetizers / Starters — Comparing Multiple Ingredients
Difficulty     : Beginner

Description:
This program finds the largest number among three integers entered
by the user.

The problem is solved using multiple approaches to demonstrate
different comparison techniques in C++.

Concepts Used:
- Input and Output
- Conditional statements
- Relational operators
- Ternary operator
- Standard library functions

How to Approach:
- Compare values using chained if–else conditions
- Reduce comparisons using nested ternary operators
- Use built-in functions for cleaner and readable code
*/
✅ Approach 1: Using if–else (Explicit Comparison)

#include<iostream>
using namespace std;

int main()
{
    int first, second, third;
    cin >> first >> second >> third;

    if((first >= second) && (first >= third))
        cout << first << " is the largest";
    else if((second >= first) && (second >= third))
        cout << second << " is the largest";
    else
        cout << third << " is the largest";

    return 0;
}


//or

✅ Approach 2: Using Ternary Operator (Step-by-step Reduction)

#include<iostream>
using namespace std;

int main()
{
    int first, second, third;
    cin >> first >> second >> third;

    int temp = (first > second) ? first : second;
    int result = (temp > third) ? temp : third;

    cout << result << " is the largest";

    return 0;
}

//or

✅ Approach 3: Using max() Function

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int first, second, third;
    cin >> first >> second >> third;

    cout << max(first, max(second, third)) << " is the largest";

    return 0;
}

