/*
Function: printInvertedPyramid(int n)

Purpose:
Prints an inverted star pyramid of height n.

Example (n = 4):

*******
 *****
  ***
   *

--------------------------------------------------

Logic Explanation:

1) Outer Loop → Controls Rows
   for(int i = 1; i <= n; i++)

   - Runs from 1 to n.
   - Each iteration prints one row.
   - As i increases:
       → Spaces increase
       → Stars decrease

--------------------------------------------------

2) Space Loop → Prints Leading Spaces
   for(int space = 1; space <= i - 1; space++)

   - For row 1 → 0 spaces
   - For row 2 → 1 space
   - For row 3 → 2 spaces
   - Pattern: spaces = i - 1

   This shifts stars to the right,
   forming the inverted pyramid shape.

--------------------------------------------------

3) Star Loop → Prints Stars
   for(int symbol = 1; symbol <= 2*(n - i) + 1; symbol++)

   - Formula: 2*(n - i) + 1
   - Ensures odd number of stars.
   - For n = 4:

     i = 1 → 2*(4-1)+1 = 7 stars
     i = 2 → 2*(4-2)+1 = 5 stars
     i = 3 → 2*(4-3)+1 = 3 stars
     i = 4 → 2*(4-4)+1 = 1 star

   Stars decrease by 2 each row,
   creating the inverted pyramid shape.

--------------------------------------------------

Pattern Summary:

Row i:
   Spaces = i - 1
   Stars  = 2*(n - i) + 1

Spaces increase by 1 each row.
Stars decrease by 2 each row.

--------------------------------------------------
*/
#include<iostream>
using namespace std;

void printInvertedPyramid(int n)
{
    for(int i = 1; i <= n; i++)
    {
        // Print spaces
        for(int space = 1; space <= i - 1; space++)
        {
            cout << " ";
        }

        // Print stars
        for(int symbol = 1; symbol <= 2*(n - i) + 1; symbol++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    printInvertedPyramid(n);
    return 0;
}
