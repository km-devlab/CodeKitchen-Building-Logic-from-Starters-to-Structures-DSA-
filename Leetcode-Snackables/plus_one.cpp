/*
==================================================
🍪 LeetCode Snackable #3
Problem: Plus One
Difficulty: Easy
Category: Array / Simulation

🧠 Problem Summary:
You are given a number represented as an array of digits.
Example:
[1,2,3] → represents 123

Add 1 to the number and return the updated array.

--------------------------------------------------
🍽️ Key Idea (Think Like Manual Addition):

We start from the last digit (like normal addition).

Case 1:
If digit < 9 → simply increment and return.

Case 2:
If digit == 9 →
    - It becomes 0
    - Carry moves to the left

If ALL digits are 9:
    Example: [9,9,9]
    → becomes [1,0,0,0]

--------------------------------------------------
⏱ Time Complexity: O(n)
⏱ Space Complexity: O(1) (except edge case)

==================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        // Traverse from last digit
        for(int i = digits.size() - 1; i >= 0; i--) {
            
            // If digit is less than 9 → no carry needed
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            
            // If digit is 9 → becomes 0 and carry continues
            digits[i] = 0;
        }
        
        // If we are here → all digits were 9
        // Example: 999 → 1000
        vector<int> result(digits.size() + 1);
        result[0] = 1;
        
        return result;
    }
};

/*
🥨 Why This Works?

Because addition works from right to left.
We simulate how we do addition manually.

No need to convert to integer
(no overflow issues 🚫).
*/

