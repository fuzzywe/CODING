1985. Find the Kth Largest Integer in the Array
Solved
Medium
Topics
Companies
Hint
You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

Return the string that represents the kth largest integer in nums.

Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

 

Example 1:

Input: nums = ["3","6","7","10"], k = 4
Output: "3"
Explanation:
The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
The 4th largest integer in nums is "3".
Example 2:

Input: nums = ["2","21","12","1"], k = 3
Output: "2"
Explanation:
The numbers in nums sorted in non-decreasing order are ["1","2","12","21"].
The 3rd largest integer in nums is "2".
Example 3:

Input: nums = ["0","0"], k = 2
Output: "0"
Explanation:
The numbers in nums sorted in non-decreasing order are ["0","0"].
The 2nd largest integer in nums is "0".



Intuition
Min Heap will work here

Approach
We will use min heap with our custom comparator.
if( a.length()>b.length() ) then definetly "a" is a greater number
Same as if( a.length()>b.length() ) then "b" is greater.
But if length of both are equal then the greater is in term of lexicographical order.
first loop will fill the heap to k size.
Second loop on each itteration compare top of heap with the current element using custom comparator.
Now, if the current is greater than our top? only then we will insert the current in loop
Becase the smaller number is not useful, As we are finding Kth largest
Complexity
Time complexity:
O( n log(k) )

Space complexity:
O(k)

Code
```cpp
struct comp {
    bool operator()(const string& a, const string& b) {
        if(a.length()>b.length()) return true 
        else if (a.length()<b.length()) return  false;
        else return  a > b ;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        comp Comp;
        priority_queue<string,vector<string>,comp> heap;
        for(int i=0;i<k;i++){
            heap.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(Comp(nums[i],heap.top())){
                heap.push(nums[i]);
                heap.pop();
            }
        }
        return heap.top();
    }
};

```
