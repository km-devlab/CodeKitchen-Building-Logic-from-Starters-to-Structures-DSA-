/*
=========================================================
🍿 LEETCODE SNACKABLES
Problem: Check If Sentence Is Pangram
Difficulty: Easy
Concepts Used:
- Frequency tracking
- Character indexing (c - 'a')
- Early exit optimization

---------------------------------------------------------
🧠 Problem Understanding:
A pangram is a sentence that contains every letter
of the English alphabet at least once.

There are 26 lowercase letters:
a to z

If all 26 letters appear → return true
Otherwise → return false

---------------------------------------------------------
💡 Core Idea:
1. If sentence length < 26 → impossible → return false.
2. Create a boolean array of size 26.
   Each index represents a letter:
   index 0 → 'a'
   index 1 → 'b'
   ...
   index 25 → 'z'
3. Traverse each character.
4. Mark it as seen.
5. Count unique letters.
6. If unique == 26 → return true early.

---------------------------------------------------------
🔑 Important Logic:
int index = c - 'a';

Why?
Characters are stored as ASCII values.

Example:
'a' - 'a' = 0
'b' - 'a' = 1
'z' - 'a' = 25

So this converts character → array index.

---------------------------------------------------------
⚡ Optimization:
As soon as unique becomes 26,
we return true immediately.
No need to scan remaining characters.

=========================================================
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        // If length < 26 → cannot be a pangram
        if(sentence.length() < 26)
            return false;

        // Boolean array to track seen letters
        vector<bool> seen(26, false);

        int unique = 0;

        // Traverse each character
        for(char c : sentence)
        {
            int index = c - 'a';   // Map letter to 0–25

            // If letter not seen before
            if(!seen[index])
            {
                seen[index] = true;
                unique++;

                // If all 26 letters found
                if(unique == 26)
                    return true;
            }
        }

        return false;
    }
};
