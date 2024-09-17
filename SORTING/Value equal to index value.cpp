Input: arr[] = [15, 2, 45, 4 , 7]
Output: 2 , 4
Explanation: 
Here, arr[2] = 2 exists here.
and arr[4] = 4 exists here.
Input: arr[] = [1]
Output: 1
Explanation: Here arr[1] = 1 exists.


best solution:
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (i%10 == nums[i]){
                return i ;
            }
        }
        return -1 ;
    }
};
tc: O(N)
sc:O(1)

Input: A vector of integers nums.
Loop through the array: For each index i, the code checks if i % 10 == nums[i]. The modulo operation % ensures that only the last digit of i is compared with nums[i].
Return the smallest index: As soon as we find an index i that satisfies the condition, we return it. If no index satisfies the condition, we return -1.
Test Cases:
Test case 1: nums = [0, 1, 2]

i = 0: 0 % 10 == 0, so we return 0.
Test case 2: nums = [4, 3, 2, 1]

i = 0: 0 % 10 != 4
i = 1: 1 % 10 != 3
i = 2: 2 % 10 == 2, so we return 2.
Test case 3: nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]

No index satisfies i % 10 == nums[i], so we return -1.
Output:
rust
Copy code
Result for nums = [0, 1, 2]: 0
Result for nums = [4, 3, 2, 1]: 2
Result for nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]: -1

