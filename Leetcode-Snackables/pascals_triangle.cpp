/*
===========================================
🍪 LeetCode Snackable #1
Problem: Pascal's Triangle
Difficulty: Easy
Why it's a Snack?
→ Simple pattern building
→ Helps understand nested loops
→ Good practice for 2D vectors

-------------------------------------------
🧠 Idea in Simple Words:

1. Each row starts and ends with 1.
2. Middle numbers are:
   sum of two numbers from the previous row.
3. Keep building rows one by one.

Think of it like stacking numbers like a triangle
where each number depends on the two above it.

-------------------------------------------
Example:
Input: 4

Output:
1
1 1
1 2 1
1 3 3 1

-------------------------------------------
Time Complexity: O(n²)
Space Complexity: O(n²)
===========================================
*/
/*
===========================================
🍪 LeetCode Snackable #1
Problem: Pascal's Triangle
Difficulty: Easy
Category: Pattern Building

🧠 Idea:
- First and last element of every row is 1
- Middle elements = sum of two numbers above
===========================================
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> triangle;

        for(int i = 0; i < numRows; i++) {
            
            vector<int> row;

            for(int j = 0; j <= i; j++) {
                
                if(j == 0 || j == i) {
                    row.push_back(1);
                }
                else {
                    row.push_back(triangle[i-1][j] + triangle[i-1][j-1]);
                }
            }

            triangle.push_back(row);
        }

        return triangle;
    }
};

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    Solution obj;
    vector<vector<int>> result = obj.generate(n);

    cout << "Pascal Triangle:\n";
    for(auto row : result) {
        for(auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

 
