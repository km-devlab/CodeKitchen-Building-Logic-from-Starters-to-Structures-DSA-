/*
==================================================
🍪 LeetCode Snackable
Dish Name: Duplicate Detector
Problem: Contains Duplicate
Difficulty: Easy
Category: Hashing / Set
==================================================

🧠 Problem Summary:
Given an integer array nums,
return true if any value appears at least twice.
Return false if all elements are unique.

--------------------------------------------------
🍽 Kitchen Analogy:

Imagine ingredients arriving one by one.

Before placing an ingredient in your bowl:
👉 Check if it's already there.

If yes → duplicate ingredient found 🍅🍅
Stop cooking and return true.

If not → add it to the bowl and continue.

--------------------------------------------------
🧠 Core Idea:

We use an unordered_set because:
- A set stores only UNIQUE elements.
- Checking existence is fast (O(1) average).

--------------------------------------------------
⏱ Time Complexity: O(n)
⏱ Space Complexity: O(n)

==================================================
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    unordered_set<int> s(nums.begin(), nums.end());

    return s.size() != nums.size();
}

// or

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> nums)
{
    unordered_set<int> s;

    for(int num : nums)
    {
        if(s.find(num) != s.end())
            return true;

        s.insert(num);
    }

    return false;
}

