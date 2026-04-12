# 🍿 Snackable: Max Difference by Digit Replacement
Greedy + String manipulation problem

## 🧠 Level
**🟡 Easy → Medium (Greedy + Strings)**

---

## 📌 Problem
Given an integer `num`, you can replace **all occurrences of a digit** with another digit.

Find the **maximum difference** between two numbers formed by:
- Replacing digits to get the **maximum value**
- Replacing digits to get the **minimum value**

---

## 💡 Approach

### 🔹 Step 1: Convert number to string
Helps in easy digit manipulation.

### 🔹 Step 2: Find Minimum Value
- Take first digit
- Replace all its occurrences with `'0'`
- Convert back to integer

### 🔹 Step 3: Find Maximum Value
- Find first digit that is NOT `'9'`
- Replace all its occurrences with `'9'`

### 🔹 Step 4: Return Difference


---

## ⏱ Complexity
- Time: **O(d)** (d = number of digits)
- Space: **O(d)**

---

## 💻 Code

```cpp
class Solution {
public:
    int minMaxDifference(int num) {
        
        // Convert number to string
        string minstr = to_string(num);
        string maxstr = minstr;

        // Step 1: Find minimum value
        char firstDigit = minstr[0];
        for(char& ch : minstr)
        {
            if(ch == firstDigit)
            {
                ch = '0';
            }
        }
        int minValue = stoi(minstr);

        // Step 2: Find maximum value
        for(int i = 0; i < maxstr.size(); i++)
        {
            if(maxstr[i] != '9')
            {
                char targetDigit = maxstr[i];

                for(int j = i; j < maxstr.size(); j++)
                {
                    if(maxstr[j] == targetDigit)
                    {
                        maxstr[j] = '9';
                    }
                }

                return stoi(maxstr) - minValue;
            }
        }

        // If all digits are 9
        return num - minValue;
    }
};


---

## 🔢 Example

Input: num = 11891

### Minimum:
- First digit = '1'
- Replace all '1' → '0'

### Maximum:
- First non-9 digit = '1'
- Replace all '1' → '9'

### Output:
99899 - 890 = 99009

---

## 🔍 Dry Run

For `num = 90`

### Min:
- First digit = '9' → replace with '0'
00 → 0
### Max:
- First non-9 digit = '0' → replace with '9'
99
99 - 0 = 99
