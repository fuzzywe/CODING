
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

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
 

Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

A simple C++ solution using ordered maps with keys as elements of the array and values as their respective counts.

Start from the first key of the map.(i.e. least element in the array which is not part of any sequence).
Check for the existence of other k-1 consecutive keys.
If any of the keys is not present, then return false.
Else, decrement the count of that key as it is included in the current sequence. If the count is 0, then remove that key as well.
Repeat the above 4 steps (n/k) times where n is the number of elements in the array and k is the size of the sequence, so total number of sequences we can make is (n/k).

``cpp
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
