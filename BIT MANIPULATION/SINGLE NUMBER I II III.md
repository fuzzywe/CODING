
https://leetcode.com/problems/single-number/description/
---

136. Single Number


You must implement a solution with a linear runtime complexity and use only constant extra space.

 
---
Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1

---

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto it:nums)
        {
            freq[it]++;
        }
        for(auto it:freq)
        {
            if(it.second ==1) return it.first;

        }return -1;
    }
};

```

TC: O(N)
SC: O(N)

Now , if we see the above method uses variable extra space, which is why it can't be our answer.

(Although it is an approach to solve this problem).

Then how do we solve this ??

Imagine you have blocks with the array elements inscribed on them. Now , if I sort the array for you and now ask you to find the element , CAN YOU DO SO ??

Yes , upon sorting , every element will have a similar element adjacent to it , if it has the frequency of 2.
---
METHOD 2 : USING SORTING (USING CONSTANT SPACE )

As explained above , we do the following :

Sort the array.

Traverse the array and check if one of the adjacent elements is equal to the current element or not.

If yes , move ahead. Else return the current element.

CODE :
 ```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
TC: O(NlogN)
SC: O(1)
```
---

The above approach can be used to solve the problem . But what if we can improve the time complexity ??
What if we don't have to sort the array ??
The following method deals with that approach.

METHOD 3 : USING BITWISE XOR OPERATOR (USING CONSTANT SPACE )

To use this approach you first need to understand about Bitwise XOR operator.

Most of us who have a background in physics ( highschool level ) , are aware of the LOGIC GATES.

One of such gates is the XOR Gate :

According to this gate , the output is true , only if both the inputs are of opposite kind .

That is ,
A B Y

0 0 0

0 1 1

1 0 1

1 1 0

We apply the extended version of this gate in our bitwise XOR operator.

If we do "a^b" , it means that we are applying the XOR gate on the 2 numbers in a bitwise fashion ( on each of the corresponding bits of the numbers).

Similarly , if we observe ,

A^A=0

A^B^A=B

(A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.

Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a



Traverse the array and take the Bitwise XOR of each element.

Return the value.

Why does this work ??

Because , the elements with frequency=2 will result in 0. And then the only element with frequency=1 will generate the answer.

CODE :


```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       int ans=0;
	   for(auto x:nums)
	   ans^=x;
	   return ans;
    }
};
```
TC: O(N)
SC: O(1)
---
**SINGLE NUMBER II**
BRUTE FORCE

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(auto x: nums){
            m[x]++;
        }

        for(auto x: m){
            if(x.second == 1){
                return x.first;
            }
        }
        
        return -1;
    }
};
```
```cpp
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (const int num : nums)
        sum += num >> i & 1;
      sum %= 3;
      ans |= sum << i;
    }

    return ans;
  }
};
```

---

```cpp
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (const int num : nums) {
      ones ^= (num & ~twos);
      twos ^= (num & ~ones);
    }

    return ones;
  }
};
```
**SINGLE NUMBER III**

260. Single Number III
Solved
Medium
Topics
Companies
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

Example 1:

Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.
Example 2:

Input: nums = [-1,0]
Output: [-1,0]
Example 3:

Input: nums = [0,1]
Output: [1,0]

---

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
         int xr = 0;
        for(auto &x: nums) xr ^= x;
        
        // find first set bit from LSB
        int bitNum = 0;
        while(1){
            if(xr & (1 << bitNum)) break;
            bitNum++;
        }

        // divide into even and odd group
        int even = 0, odd = 0;
        for(auto &x: nums){
            if(x & (1 << bitNum)) odd ^= x;
            else even ^= x;
        }

        if(even < odd) return {even, odd};
        return {odd, even};
    }
};

```
---

BRUTE FORCE:

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        vector<int>ans;
      for(auto it: nums)
      {
        freq[it]++;
      }  
      for(auto it: freq)
      {
        if(it.second == 1) ans.push_back(it.first);
      }
      return ans;
    }
};
```
