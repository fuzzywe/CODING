
Code
Testcase
Test Result
Test Result
846. Hand of Straights
Medium
Topics
Companies
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
Example 2:

Input: nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output: true
Explanation: Array can be divided into [1,2,3] , [2,3,4] , [3,4,5] and [9,10,11].
Example 3:

Input: nums = [1,2,3,4], k = 3
Output: false
Explanation: Each array should be divided in subarrays of size 3.
 
 

Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

A simple C++ solution using ordered maps with keys as elements of the array and values as their respective counts.

Start from the first key of the map.(i.e. least element in the array which is not part of any sequence).
Check for the existence of other k-1 consecutive keys.
If any of the keys is not present, then return false.
Else, decrement the count of that key as it is included in the current sequence. If the count is 0, then remove that key as well.
Repeat the above 4 steps (n/k) times where n is the number of elements in the array and k is the size of the sequence, so total number of sequences we can make is (n/k).

```cpp

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        if(n % k != 0)
        {
            return false;
        }
        
        map<int, int> mp;
        
        for(int& num: nums)
        {
            mp[num]++;
        }
        
        int l = n/k;
        
        
        for(int i = 1; i <= l; i++)
        {
            auto it = mp.begin();
            int tmp = it->first;
            
            for(int j = tmp; j < tmp + k; j++)
            {
                if(mp.find(j) == mp.end())
                {
                    return false;
                }
                
                mp[j]--;
                if(mp[j] == 0)
                {
                    mp.erase(j);
                }
            }
        }
        
        
        return true;
    }
};

```

### Code Breakdown and Explanation:

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
```
- **Explanation**: This is the function declaration in C++. It takes in two parameters:
  1. `nums`: A vector of integers, representing the array of numbers.
  2. `k`: An integer representing the group size for consecutive sequences.
- **Example**: Let `nums = [3, 6, 2, 3, 7, 4, 5, 8]` and `k = 4`.

---

```cpp
        int n = nums.size();
```
- **Explanation**: This line calculates the size of the array `nums` and stores it in the variable `n`.
- **Example**: For `nums = [3, 6, 2, 3, 7, 4, 5, 8]`, `n = 8`.

---

```cpp
        if(n % k != 0) {
            return false;
        }
```
- **Explanation**: Checks if the size of the array `n` is divisible by `k`. If not, it's impossible to divide `nums` into consecutive sequences of size `k`, so return `false`.
- **Example**: For `n = 8` and `k = 4`, `n % k = 0`, so the function continues. If `k = 3`, this would return `false` because `8 % 3 != 0`.

---

```cpp
        map<int, int> mp;
```
- **Explanation**: Declares a map `mp` (which stores key-value pairs), where the key is the number from the array and the value is the frequency of that number.
- **Example**: `mp` will map each number to how many times it appears. For `nums = [3, 6, 2, 3, 7, 4, 5, 8]`, initially, `mp = {3: 2, 6: 1, 2: 1, 7: 1, 4: 1, 5: 1, 8: 1}`.

---

```cpp
        for(int& num: nums) {
            mp[num]++;
        }
```
- **Explanation**: Loops through each number in `nums` and increments its frequency in the map `mp`.
- **Example**: After this loop, `mp = {2: 1, 3: 2, 4: 1, 5: 1, 6: 1, 7: 1, 8: 1}`.

---

```cpp
        int l = n/k;
```
- **Explanation**: Calculates how many groups of size `k` the array can be divided into. This value is stored in `l`.
- **Example**: For `n = 8` and `k = 4`, `l = 2`.

---

```cpp
        for(int i = 1; i <= l; i++) {
```
- **Explanation**: Starts a loop that will run `l` times, corresponding to the number of groups that need to be formed.
- **Example**: Here, the loop will iterate twice because `l = 2`.

---

```cpp
            auto it = mp.begin();
            int tmp = it->first;
```
- **Explanation**: Gets the smallest element (key) from the map `mp`. `it` points to the first element in the map, and `tmp` stores the key of that element.
- **Example**: Initially, `mp = {2: 1, 3: 2, 4: 1, 5: 1, 6: 1, 7: 1, 8: 1}`, so `tmp = 2` (the smallest number).

---

```cpp
            for(int j = tmp; j < tmp + k; j++) {
```
- **Explanation**: This is a loop that checks the next `k` consecutive numbers, starting from `tmp`. 
- **Example**: For `tmp = 2` and `k = 4`, the loop checks for numbers `2, 3, 4, 5`.

---

```cpp
                if(mp.find(j) == mp.end()) {
                    return false;
                }
```
- **Explanation**: If the current number `j` (from the consecutive sequence) is not found in the map `mp`, return `false` because we can't form a valid sequence.
- **Example**: If `j = 2`, it finds it in the map, so it continues. If `j = 9` (in the next iteration), it would return `false`.

---

```cpp
                mp[j]--;
                if(mp[j] == 0) {
                    mp.erase(j);
                }
```
- **Explanation**: Decreases the count of `j` in the map `mp` because we are using that number. If the count of `j` becomes 0, it erases the element from the map.
- **Example**: After processing the first group (`2, 3, 4, 5`), `mp` becomes `{3: 1, 6: 1, 7: 1, 8: 1}`.

---

```cpp
        return true;
    }
};
```
- **Explanation**: If all the groups are formed successfully without returning `false`, the function returns `true`, indicating it's possible to divide the array into consecutive sequences of size `k`.

---

### Dry Run:

#### Input:
`nums = [3, 6, 2, 3, 7, 4, 5, 8]`, `k = 4`

1. **Initial map**: `mp = {2: 1, 3: 2, 4: 1, 5: 1, 6: 1, 7: 1, 8: 1}`.
2. **First iteration (`i = 1`)**:
   - Smallest element: `tmp = 2`.
   - Check consecutive elements: `2, 3, 4, 5`.
   - After processing: `mp = {3: 1, 6: 1, 7: 1, 8: 1}`.
3. **Second iteration (`i = 2`)**:
   - Smallest element: `tmp = 3`.
   - Check consecutive elements: `3, 6, 7, 8`.
   - After processing: `mp = {}` (all elements are used).
4. The map is empty, and both groups of 4 elements were successfully formed.
5. **Result**: Return `true`.

---

### Time Complexity:
- The map insertions, deletions, and searches take logarithmic time, so the overall complexity is `O(n log n)`.

### Space Complexity:
- The space complexity is `O(n)` due to the map storing the counts of the elements.
