https://www.geeksforgeeks.org/problems/maximum-product-subarray3604/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

https://leetcode.com/problems/maximum-product-subarray/description/


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


---
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
    }
};

```


Let's go through the code line by line with explanations, and then we'll do a dry run with an example to see how it works.

### Code Explanation

This function calculates the **maximum product of a contiguous subarray** in the given integer array `nums`. The approach used here keeps track of the maximum and minimum products at each position, as multiplying by a negative number can turn a small product into a large one, or vice versa.

Here’s a breakdown:

```cpp
int prod1 = nums[0], prod2 = nums[0], result = nums[0];
```
- `prod1` keeps track of the maximum product ending at the current position.
- `prod2` keeps track of the minimum product ending at the current position (important for handling negative values).
- `result` stores the overall maximum product found so far.

---

```cpp
for(int i = 1; i < nums.size(); i++) {
```
- We start iterating from the second element because we initialized `prod1`, `prod2`, and `result` with `nums[0]`.

---

```cpp
int temp = max({nums[i], prod1 * nums[i], prod2 * nums[i]});
```
- For each element `nums[i]`, we calculate the maximum possible product ending at `i` by considering:
  - `nums[i]` itself (starting a new subarray),
  - `prod1 * nums[i]` (extending the previous maximum product),
  - `prod2 * nums[i]` (extending the previous minimum product, which might turn large if multiplied by a negative number).

- We store this result in a temporary variable `temp` to avoid overwriting `prod1` before updating `prod2`.

---

```cpp
prod2 = min({nums[i], prod1 * nums[i], prod2 * nums[i]});
```
- Similarly, we calculate the minimum possible product at `i` by considering the same options as above. This helps handle cases where the product might flip due to a negative value.

---

```cpp
prod1 = temp;
```
- Update `prod1` with the temporary maximum product calculated earlier.

---

```cpp
result = max(result, prod1);
```
- Update `result` to store the maximum product found so far.

---

```cpp
return result;
```
- Finally, return the maximum product of any contiguous subarray.

---

### Dry Run with an Example

Let's dry run with `nums = [2, 3, -2, 4]`.

1. **Initialization**: 
   - `prod1 = 2`, `prod2 = 2`, `result = 2`.

2. **First iteration** (`i = 1`, `nums[1] = 3`):
   - `temp = max({3, prod1 * 3, prod2 * 3}) = max(3, 2 * 3, 2 * 3) = 6`
   - `prod2 = min({3, prod1 * 3, prod2 * 3}) = min(3, 2 * 3, 2 * 3) = 3`
   - Update `prod1 = 6`
   - Update `result = max(result, prod1) = max(2, 6) = 6`

   So, `prod1 = 6`, `prod2 = 3`, `result = 6`.

3. **Second iteration** (`i = 2`, `nums[2] = -2`):
   - `temp = max({-2, prod1 * -2, prod2 * -2}) = max(-2, 6 * -2, 3 * -2) = max(-2, -12, -6) = -2`
   - `prod2 = min({-2, prod1 * -2, prod2 * -2}) = min(-2, 6 * -2, 3 * -2) = min(-2, -12, -6) = -12`
   - Update `prod1 = -2`
   - `result = max(result, prod1) = max(6, -2) = 6`

   So, `prod1 = -2`, `prod2 = -12`, `result = 6`.

4. **Third iteration** (`i = 3`, `nums[3] = 4`):
   - `temp = max({4, prod1 * 4, prod2 * 4}) = max(4, -2 * 4, -12 * 4) = max(4, -8, -48) = 4`
   - `prod2 = min({4, prod1 * 4, prod2 * 4}) = min(4, -2 * 4, -12 * 4) = min(4, -8, -48) = -48`
   - Update `prod1 = 4`
   - `result = max(result, prod1) = max(6, 4) = 6`

   So, `prod1 = 4`, `prod2 = -48`, `result = 6`.

### Final Output:
After the loop, `result = 6`, which is the maximum product of any contiguous subarray in `[2, 3, -2, 4]`.

### Summary of Results:
- The code keeps track of both maximum and minimum products at each step to handle negative numbers.
- The `result` variable stores the maximum product found, which is returned as the final answer.
