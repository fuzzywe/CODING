https://leetcode.com/problems/maximum-product-subarray/

**152. Maximum Product Subarray**

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
```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Initialize the result with the minimum possible integer value
        int result = nums[0]; // Start with the first element instead of INT_MIN
        
        // Outer loop to choose the starting point of the subarray
        for(int i = 0; i < nums.size(); i++) {
            int prod = 1; // Initialize product for each subarray starting from i
            // Inner loop to calculate the product for subarrays starting from i
            for(int j = i; j < nums.size(); j++) {
                prod *= nums[j]; // Calculate the product of the subarray from i to j
                result = max(result, prod); // Update the result if the product is larger
            }
        }
        return result;
    }
};



```

Time Complexity: O(N3)

Reason: We are using 3 nested loops for finding all possible subarrays and their product.

Space Complexity: O(1)

Reason: No extra data structure was used


 OPTIMAL 

 ```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // If nums is empty, we return 0 as there's no product possible.
        if (nums.empty()) return 0;
        
        // Initialize maxProduct, minProduct, and result with the first element
        int maxProduct = nums[0], minProduct = nums[0], result = nums[0];
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the current number is negative, swap maxProduct and minProduct
            if (nums[i] < 0) {
                std::swap(maxProduct, minProduct);
            }
            
            // Calculate the new max and min products considering the current element
            maxProduct = std::max(nums[i], maxProduct * nums[i]);
            minProduct = std::min(nums[i], minProduct * nums[i]);
            
            // Update the result with the maximum product found so far
            result = std::max(result, maxProduct);
        }
        
        return result;
    }
};


```

Time Complexity: O(n), where n is the size of the nums array.
Space Complexity: O(1), as the algorithm only uses a constant amount of extra space


```cpp
int maxProductSubArray(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}

```

Time Complexity: O(N)

Reason: A single iteration is used.

Space Complexity: O(1)


