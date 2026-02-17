/*
==================================================
🍪 LeetCode Snackable – Ingredient Match
Problem: Valid Anagram
Method: Frequency Array
Difficulty: Easy
Category: String / Counting
==================================================

🧠 Problem:
Check whether two strings are anagrams.

Two strings are anagrams if:
- They have same length
- Same characters
- Same frequency of characters

--------------------------------------------------
🍽 Kitchen Analogy:

Imagine two bowls of ingredients.
If both bowls contain:
- Same ingredients
- Same quantity

Then both recipes are identical.

Instead of sorting,
we COUNT ingredients.

--------------------------------------------------
🧠 Important Concept: c - 'a'

Characters are stored as ASCII numbers.

'a' = 97
'b' = 98
'c' = 99
...
'z' = 122

If:
    c = 'c'

Then:
    c - 'a'
  = 99 - 97
  = 2

So:
    freq[2]++

This maps:
a → index 0
b → index 1
c → index 2
...
z → index 25

We normalize letters to fit inside
an array of size 26.

--------------------------------------------------
⏱ Time Complexity: O(n)
⏱ Space Complexity: O(1)
==================================================
*/

#include <iostream>
using namespace std;

bool isAnagram(string s, string t)
{
    if(s.length() != t.length())
        return false;

    int freq[26] = {0};

    // Count characters of s
    for(char c : s)
    {
        freq[c - 'a']++;
    }

    // Subtract characters of t
    for(char c : t)
    {
        freq[c - 'a']--;
    }

    // Check if all counts are zero
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;

    if(isAnagram(s, t))
        cout << "True";
    else
        cout << "False";

    return 0;
}

/*Another Method using sort()
#include <iostream>
#include <algorithm>
using namespace std;

bool isAnagram(string s,string t)
{
    if(s.length()!=t.length())
        return false;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return s==t;
}*/

