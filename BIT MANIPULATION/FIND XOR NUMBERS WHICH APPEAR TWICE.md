3158. Find the XOR of Numbers Which Appear Twice

https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/

You are given an array nums, where each number in the array appears either once or twice.

Return the bitwise XOR of all the numbers that appear twice in the array, or 0 if no number appears twice.

 

Example 1:

Input: nums = [1,2,1,3]

Output: 1

Explanation:

The only number that appears twice in nums is 1.

Example 2:

Input: nums = [1,2,3]

Output: 0

Explanation:

No number appears twice in nums.

Example 3:

Input: nums = [1,2,2,1]

Output: 3

Explanation:

Numbers 1 and 2 appeared twice. 1 XOR 2 == 3.

---
BIT MANIPULATION:

```cpp
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) 
    {
        vector<int>store, count(100);
        for(auto val:nums)
        {
            count[val]++;
            if(count[val] == 2)
                store.push_back(val);
        }
        int ans = 0;
        for(auto val:store)
            ans ^= val;
        return ans;
    }
};
```

---

BRUTE FORCE

```cpp
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> countArr(51, 0);
        for(int num : nums) {
            countArr[num]++;
        }
        
        int ans = 0;
        for(int i = 0; i < countArr.size(); i++) {
            if(countArr[i] == 2) {
                ans ^= i;
            }
        }
        return ans;
    }
};

```

Explanation of the Approach:

Counting Occurrences: We first create a counting array countArr to keep track of how many times each number appears. This array has a size of 51 to accommodate all possible numbers from 0 to 50.

Finding the Unique Number: We iterate through the countArr. For each number that appears exactly twice, we XOR it with ans. This is because XOR-ing twice will cancel out the number (due to property 1), leaving us with only the unique number.

Complexity Analysis:

Time Complexity: O(n), where n is the length of the input array. We make a single pass to fill the counting array and another pass to determine the unique number.
Space Complexity: O(1), since the counting array size is constant (51).
