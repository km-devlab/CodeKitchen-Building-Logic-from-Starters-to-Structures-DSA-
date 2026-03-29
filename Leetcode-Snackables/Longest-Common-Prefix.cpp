/*
=========================================================
🍿 LEETCODE SNACKABLES
Problem: Longest Common Prefix
Difficulty: Easy
Concepts Used:
- Sorting
- String comparison
- Greedy prefix matching

---------------------------------------------------------
🧠 Problem Understanding:
Given a list of strings, find the longest common prefix
(shared starting characters) among all strings.

If no common prefix → return empty string "".

Example:
["flower", "flow", "flight"] → "fl"

---------------------------------------------------------
💡 Core Idea (IMPORTANT TRICK):

Instead of comparing ALL strings,
we:

1. Sort the array of strings.
2. Compare ONLY:
   → First string (smallest)
   → Last string (largest)

Why does this work?

After sorting:
- Strings with most difference come at extremes.
- Common prefix of ALL strings must also be
  common between first and last string.

---------------------------------------------------------
🧠 Example After Sorting:

Input:
["flower", "flow", "flight"]

Sorted:
["flight", "flow", "flower"]

Compare:
first = "flight"
last  = "flower"

Common prefix → "fl"

---------------------------------------------------------
🔑 Logic Steps:

1. Sort the array
2. Take:
   first_str = strs[0]
   last_str  = strs[n-1]
3. Compare characters one by one
4. Stop when mismatch occurs
5. Build result string

=========================================================
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string lcp = "";

        // Step 1: Sort the strings
        sort(strs.begin(), strs.end());

        // Step 2: Take first and last string
        string first_str = strs[0];
        string last_str  = strs[strs.size() - 1];

        // Step 3: Compare characters
        for(int i = 0; i < first_str.length(); i++)
        {
            if(first_str[i] == last_str[i])
            {
                lcp += first_str[i];
            }
            else
            {
                break;
            }
        }

        return lcp;
    }
};
