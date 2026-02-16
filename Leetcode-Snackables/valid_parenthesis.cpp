/*
==================================================
🍪 LeetCode Snackable #2
Problem: Valid Parentheses
Difficulty: Easy
Category: Stack / String

🧠 Problem Summary:
Given a string containing only:
( ) { } [ ]

Check if:
- Every opening bracket has a closing bracket
- Order is correct
- No extra brackets remain

--------------------------------------------------
🍽️ Approach (Stack Method):

1️⃣ Create an empty stack.
2️⃣ Traverse each character:
    - If opening bracket → push into stack
    - If closing bracket:
        • If stack empty → invalid
        • If top doesn't match → invalid
        • Else → pop
3️⃣ At the end:
    - If stack empty → valid
    - Else → invalid

--------------------------------------------------
⏱ Time Complexity: O(n)
⏱ Space Complexity: O(n)

==================================================
*/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char c : s) {
            // If opening bracket, push
            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack empty → invalid
                if(st.empty()) return false;
                
                // If mismatch → invalid
                if((c == ')' && st.top() != '(') ||
                   (c == '}' && st.top() != '{') ||
                   (c == ']' && st.top() != '[')) {
                    return false;
                }
                
                // Matching case → pop
                st.pop();
            }
        }
        
        // Valid only if stack empty
        return st.empty();
    }
};

/*
🥨 Why Stack?

Because brackets follow LIFO (Last In First Out).
The last opened bracket must close first.
Stack perfectly models this behavior.
*/

