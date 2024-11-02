
164. Maximum Gap

https://leetcode.com/problems/maximum-gap/description/

Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

You must write an algorithm that runs in linear time and uses linear extra space.

 

Example 1:

Input: nums = [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: nums = [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.

BRUTE FORCE
```
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = 0;
        for (int i = 1; i < nums.size(); i++) {
            best = max(nums[i]-nums[i-1], best);
        }
        return best;
    }
};

```

OPTIMAL APPROACH
```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long n = nums.size(); //To prevent integer overflow during index calculation
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());

        if(maxi == mini){
            return 0;
        }

        vector<int> bucketLargest(n,INT_MIN);
        vector<int> bucketSmallest(n,INT_MAX);

        for(int i=0;i<n;i++){
            int index = (((nums[i] - mini)*(n-1))/(maxi - mini));
            bucketLargest[index] = max(bucketLargest[index],nums[i]);
            bucketSmallest[index] = min(bucketSmallest[index],nums[i]);
        }

        int lG = 0;
        int i = 0, j = 1;
        while(j<n){
            if(bucketLargest[j] == INT_MIN){
                j++;
            }
            else if(bucketLargest[i] == INT_MIN){
                i++;
            }
            else{
                lG = max(lG,bucketSmallest[j] - bucketLargest[i]);
                i++,j++;
            }
        }

        return lG;
    }
};

```

Let’s go through a detailed dry run of each line in the `maximumGap` function and break down the formula used in each line.

### Code Dry Run and Explanation

```cpp
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        long long n = nums.size(); // To prevent integer overflow during index calculation
```

1. **`long long n = nums.size();`**: 
   - `n` is the size of the `nums` array.
   - We store `nums.size()` as a `long long` to prevent potential overflow in future calculations.
   - **Example**: If `nums = [3, 6, 9, 1]`, then `n = 4`.

```cpp
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
```

2. **`int maxi = *max_element(nums.begin(), nums.end());`** and **`int mini = *min_element(nums.begin(), nums.end());`**:
   - We find the maximum (`maxi`) and minimum (`mini`) elements in the array `nums`.
   - These values help define the range of values in the array.
   - **Example**: For `nums = [3, 6, 9, 1]`, `maxi = 9` and `mini = 1`.

```cpp
        if(maxi == mini){
            return 0;
        }
```

3. **`if (maxi == mini)`**:
   - If all elements in `nums` are the same (`maxi == mini`), then there’s no gap between elements, so we return `0`.
   - **Example**: If `nums = [5, 5, 5]`, `maxi == mini == 5`, so `maximumGap` returns `0`.

```cpp
        vector<int> bucketLargest(n,INT_MIN);
        vector<int> bucketSmallest(n,INT_MAX);
```

4. **`vector<int> bucketLargest(n, INT_MIN);` and `vector<int> bucketSmallest(n, INT_MAX);`**:
   - We create two arrays (`bucketLargest` and `bucketSmallest`) of size `n`, initialized with `INT_MIN` and `INT_MAX`, respectively.
   - `bucketLargest` will store the largest number in each bucket, while `bucketSmallest` will store the smallest number in each bucket.
   - **Example**: For `n = 4`, `bucketLargest = [INT_MIN, INT_MIN, INT_MIN, INT_MIN]`, and `bucketSmallest = [INT_MAX, INT_MAX, INT_MAX, INT_MAX]`.

```cpp
        for(int i = 0; i < n; i++) {
            int index = (((nums[i] - mini) * (n - 1)) / (maxi - mini));
            bucketLargest[index] = max(bucketLargest[index], nums[i]);
            bucketSmallest[index] = min(bucketSmallest[index], nums[i]);
        }
```

5. **`for` loop to distribute elements into buckets**:
   - For each element `nums[i]`, we calculate its bucket index using:
     \[
     \text{index} = \left(\frac{(\text{nums[i]} - \text{mini}) \times (n - 1)}{\text{maxi} - \text{mini}}\right)
     \]
   - This formula normalizes the range of values to fit into `n-1` buckets based on their relative position between `mini` and `maxi`.
   - After finding the bucket index, we update the maximum and minimum values in each bucket (`bucketLargest` and `bucketSmallest`).
   - **Example**:
     - For `nums = [3, 6, 9, 1]`, `mini = 1` and `maxi = 9`.
     - For `nums[0] = 3`: 
       - \[
       \text{index} = \left(\frac{(3 - 1) \times 3}{9 - 1}\right) = \frac{6}{8} = 0
       \]
       - `bucketLargest[0] = 3`, `bucketSmallest[0] = 3`.
     - For `nums[1] = 6`:
       - \[
       \text{index} = \left(\frac{(6 - 1) \times 3}{9 - 1}\right) = \frac{15}{8} = 1
       \]
       - `bucketLargest[1] = 6`, `bucketSmallest[1] = 6`.
     - For `nums[2] = 9`:
       - \[
       \text{index} = \left(\frac{(9 - 1) \times 3}{9 - 1}\right) = 3
       \]
       - `bucketLargest[3] = 9`, `bucketSmallest[3] = 9`.
     - For `nums[3] = 1`:
       - \[
       \text{index} = \left(\frac{(1 - 1) \times 3}{9 - 1}\right) = 0
       \]
       - `bucketSmallest[0]` is updated to `1`.

```cpp
        int lG = 0;
        int i = 0, j = 1;
```

6. **Initialize Variables for Maximum Gap Calculation**:
   - **`int lG = 0;`**: This variable stores the largest gap found.
   - **`int i = 0, j = 1;`**: `i` and `j` are pointers used to traverse the buckets and calculate the gaps.

```cpp
        while(j < n) {
            if(bucketLargest[j] == INT_MIN) {
                j++;
            }
            else if(bucketLargest[i] == INT_MIN) {
                i++;
            }
            else {
                lG = max(lG, bucketSmallest[j] - bucketLargest[i]);
                i++, j++;
            }
        }
```

7. **`while` Loop to Find the Maximum Gap**:
   - We use `i` and `j` to check for gaps between adjacent non-empty buckets.
   - If `bucketLargest[j]` is `INT_MIN`, it means bucket `j` is empty, so we increment `j`.
   - If `bucketLargest[i]` is `INT_MIN`, it means bucket `i` is empty, so we increment `i`.
   - Otherwise, we calculate the gap:
     \[
     \text{lG} = \max(\text{lG}, \text{bucketSmallest[j]} - \text{bucketLargest[i]})
     \]
   - **Example**: 
     - Continuing with `nums = [3, 6, 9, 1]`:
       - Buckets: `bucketLargest = [3, 6, INT_MIN, 9]`, `bucketSmallest = [1, 6, INT_MAX, 9]`.
       - We calculate `lG`:
         - Gap between `bucketLargest[0]` and `bucketSmallest[1]`: `6 - 3 = 3`.
         - Gap between `bucketLargest[1]` and `bucketSmallest[3]`: `9 - 6 = 3`.
       - So, `lG = 3`.

```cpp
        return lG;
    }
};
```

8. **Return the Maximum Gap**:
   - **`return lG;`**: Finally, we return `lG`, which now contains the maximum gap found between successive non-empty buckets.
     
