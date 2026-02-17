/*
==================================================
🍪 LeetCode Snackable
Problem: Valid Palindrome
Difficulty: Easy
Category: Two Pointers / String
==================================================

🧠 Idea:
- Convert to lowercase
- Use two pointers (start & end)
- Skip non-alphanumeric characters
- Compare both sides

🍽 Kitchen Analogy:
Checking symmetry of a burger 🍔
Left bun must match right bun.
Ignore sesame seeds (special characters).
==================================================
*/

#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while(i < j)
    {
        // Skip non-alphanumeric characters
        if(!isalnum(s[i])) {
            i++;
            continue;
        }

        if(!isalnum(s[j])) {
            j--;
            continue;
        }

        // Compare lowercase characters
        if(tolower(s[i]) != tolower(s[j]))
            return false;

        i++;
        j--;
    }

    return true;
}

int main()
{
    string s;
    getline(cin, s);

    if(isPalindrome(s))
        cout << "True";
    else
        cout << "False";

    return 0;
}

