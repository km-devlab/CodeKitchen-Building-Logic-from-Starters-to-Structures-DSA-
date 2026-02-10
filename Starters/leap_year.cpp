/*
🍽️ Dish Name: Leap Year Checker

🧠 Problem Statement:
Given a year, determine whether it is a leap year or not.

📌 Concepts Used:
- Conditional statements
- Modulus operator
- Nested if-else logic

🍳 Approach (Chef’s Recipe):
1. Check if the year is divisible by 4.
2. If divisible by 100, it must also be divisible by 400.
3. If these conditions are satisfied, it is a leap year.
4. Otherwise, it is not a leap year.

🧩 Leap Year Rules:
- Divisible by 4 → Leap year
- Divisible by 100 → Not a leap year
- Divisible by 400 → Leap year

/*🥗 Example:
Input: 2000  
Output: Leap year

Input: 1900  
Output: Not a leap year

⏱ Time Complexity:
O(1)

📦 Space Complexity:
O(1)

👩‍🍳 Category in Repo:
Appetizers / Starters 🥗 → Conditional Logic
*/

//beginner-friendly
#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        cout << "Leap year";
    else
        cout << "Not a leap year";

    return 0;
}


//or

//using Nested-if
#include <iostream>
using namespace std;

int main()
{
    int year;

    cout << "Enter a year: "; 
    cin >> year;

    // Check if it's a leap year
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                cout << "leap year" << endl;
            }
            else
            {
                cout << "not a leap year" << endl;
            }
        }
        else
        {
            cout << "leap year" << endl;
        }
    }
    else
    {
        cout << "not a leap year" << endl;
    }

    return 0; 
}

