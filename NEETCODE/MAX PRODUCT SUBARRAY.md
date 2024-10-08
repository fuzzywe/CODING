152. Maximum Product Subarray
Medium
Topics
Companies
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Complexity
Time complexity:
O(N) + O(N) = O(N), where N is size of array.

Space complexity:
O(1)

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          maxi=max(prod,maxi);
          if(prod==0)
           prod=1;
        }
        return maxi;
    }
};

```
Key Explanation and proof for this algorithm:
let n be the # of negative numbers.
If n is even it obviously works.
If n is odd, then the answer is some subarray without one of the negative numbers, i.e. to the right or to the left of that negative number.
Take a look at any negative number in the array.
Consider the subarrays to the left of this number and to the right of this number. they both have an even # of negative numbers,
Then, when we take max products from the right and from the left, we encounter these arrays` product too.
And this is true for every negative number in the array, so for sure we will encounter the answer.

Nice One

43
Reply




Wow really cool solution. I think the reason getting prefix product, suffix product and getting max works is because there are only 2 things you have to look out for(zero and the greatest negative number in a odd negative number array). Thus your algorithm completes the 2 cases by finding the max product to the greatest negative number from both sides and reseting product when it reaches 0.
