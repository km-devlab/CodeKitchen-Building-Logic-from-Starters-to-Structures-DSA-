# 🍿 Snackable: Frequency Finder (Min & Max Occurrence)

## 🧠 Level
**🟢 Easy → Early Medium (Hashing Basics)**

---

## 📌 Problem
Given an array of integers, find:
- Element(s) with **highest frequency**
- Element(s) with **lowest frequency**

---

## 💡 Approach
1. Use `unordered_map` to count frequency of each element.
2. Traverse the map to find:
   - `maxFreq` (highest frequency)
   - `minFreq` (lowest frequency)
3. Print elements matching those frequencies.

---

## 🔢 Example
Input: [1, 2, 2, 3, 3, 3]
Output: 
Highest → 3
Lowest → 1


---

## ⏱ Complexity
- Time: **O(n)**
- Space: **O(n)**

---

## 💻 Code

#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Count frequency
    unordered_map<int, int> freq;
    for (int x : arr)
        freq[x]++;

    // Find min and max frequency
    int minFreq = INT_MAX, maxFreq = INT_MIN;
    for (auto& [elem, count] : freq) {
        minFreq = min(minFreq, count);
        maxFreq = max(maxFreq, count);
    }

    // Print highest frequency elements
    cout << "Highest occurrence (freq=" << maxFreq << "): ";
    for (auto& [elem, count] : freq)
        if (count == maxFreq) cout << elem << " ";
    cout << "\n";

    // Print lowest frequency elements
    cout << "Lowest occurrence  (freq=" << minFreq << "): ";
    for (auto& [elem, count] : freq)
        if (count == minFreq) cout << elem << " ";
    cout << "\n";

    return 0;
}
