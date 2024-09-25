Assign Cookies

Problem Statement: Given two arrays representing children’s green factor and cookie sizes, the goal is to maximise the number of content children.

Each child i has a greed factor of g[i], which is the minimum size of a cookie that will make the child content. 
 Each cookie j has a size of s[j]. If s[j] >= g[j], we can assign cookie j to child i, making the child content.
Each child can only receive one cookie.

Examples
Example 1:
Input:g = [1, 2, 3], s = [1, 1]
                
Output: 1
Explanation:  We have 3 children and 2 cookies. The greed factors of the 3 children are 1, 2, 3. The sizes of the 2 cookies are both 1. We can only make the child with greed factor 1 content. Hence, the output is 1.

Example 2:
Input:g = [1, 5, 3, 3, 4], s = [4, 2, 1, 2, 1, 3]
                
Output: 0
Explanation: You have 5 children and 6 cookies. The greed factors of the 5 children are 1, 5, 3, 3, and 4. The sizes of the 6 cookies are 4, 2, 1, 2, 1, and 3.
                
The child with greed factor 1 can be satisfied with the cookie of size 1.
One child with greed factor 3 can be satisfied with the cookie of size 3.
One child with greed factor 4 can be satisfied with the cookie of size 4.

                Hence, the output is 3.     
                            
#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to find the maximum
// number of content children
int findContentChildren(vector<int>& greed, vector<int>& cookieSize) {
    // Get the size of
    // the greed array
    int n = greed.size();

    // Get the size of
    // the cookieSize array
    int m = cookieSize.size();

    // Sort the greed factors in ascending
    // order to try and satisfy the
    // least greedy children first
    sort(greed.begin(), greed.end());

    // Sort the cookie sizes in ascending
    // order to use the smallest cookies first
    sort(cookieSize.begin(), cookieSize.end());

    // Initialize a pointer for the
    // cookieSize array, starting
    // from the first cookie
    int l = 0;

    // Initialize a pointer for the
    // greed array, starting from
    // the first child
    int r = 0;

    // Iterate while there are
    // cookies and children
    // left to consider
    while (l < m && r < n) {
        // If the current cookie can
        // satisfy the current child's greed
        if (greed[r] <= cookieSize[l]) {
            // Move to the next child,
            // as the current child is satisfied
            r++;
        }
        // Always move to the next cookie
        // whether the current child
        // was satisfied or not
        l++;
    }



  

    // The value of r at the end of
    // the loop represents the number
    // of children that were satisfied
    return r;
}


int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
    
    cout << "Array Representing Greed: ";
    for(int i = 0; i < greed.size(); i++){
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for(int i = 0; i < cookieSize.size(); i++){
        cout << cookieSize[i] << " ";
    }
    
    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies "<< ans;
    cout << endl;

    return 0;
}
                            
                        
                            
                        
Output Array Representing Greed: 1 5 3 3 4

Array Representing Cookie Size: 4 2 1 2 1 3

No. of kids assigned cookies 3

Complexity Analysis

Let's perform a dry run of the provided code to understand how it works step-by-step.

### Code Overview
The problem aims to assign cookies to children based on their greed and cookie sizes. A child can only be satisfied if a cookie of size equal to or greater than the child's greed is given to them. The goal is to maximize the number of satisfied children.

### Given Input
- `greed` array: `{1, 5, 3, 3, 4}`
- `cookieSize` array: `{4, 2, 1, 2, 1, 3}`

### Dry Run

1. **Step 1:** Initialize arrays and display their values.
   ```
   Greed Array: {1, 5, 3, 3, 4}
   Cookie Size Array: {4, 2, 1, 2, 1, 3}
   ```
   
2. **Step 2:** Sort both arrays to help in satisfying the least greedy child first and using the smallest cookie possible.
   - Sorted `greed` array: `{1, 3, 3, 4, 5}`
   - Sorted `cookieSize` array: `{1, 1, 2, 2, 3, 4}`
   
3. **Step 3:** Initialize pointers:
   - `r = 0` (points to the first child)
   - `l = 0` (points to the first cookie)

4. **Step 4:** Loop through cookies and children until either the cookies or children run out.

#### Iteration 1:
   - `greed[0] = 1` and `cookieSize[0] = 1`
   - Condition: `greed[0] <= cookieSize[0]` (1 <= 1) → True.
     - Satisfy the child, increment `r` to 1 (next child).
   - Increment `l` to 1 (next cookie).

#### Iteration 2:
   - `greed[1] = 3` and `cookieSize[1] = 1`
   - Condition: `greed[1] <= cookieSize[1]` (3 <= 1) → False.
     - Do not satisfy the child, just increment `l` to 2 (next cookie).

#### Iteration 3:
   - `greed[1] = 3` and `cookieSize[2] = 2`
   - Condition: `greed[1] <= cookieSize[2]` (3 <= 2) → False.
     - Do not satisfy the child, just increment `l` to 3 (next cookie).

#### Iteration 4:
   - `greed[1] = 3` and `cookieSize[3] = 2`
   - Condition: `greed[1] <= cookieSize[3]` (3 <= 2) → False.
     - Do not satisfy the child, just increment `l` to 4 (next cookie).

#### Iteration 5:
   - `greed[1] = 3` and `cookieSize[4] = 3`
   - Condition: `greed[1] <= cookieSize[4]` (3 <= 3) → True.
     - Satisfy the child, increment `r` to 2 (next child).
   - Increment `l` to 5 (next cookie).

#### Iteration 6:
   - `greed[2] = 3` and `cookieSize[5] = 4`
   - Condition: `greed[2] <= cookieSize[5]` (3 <= 4) → True.
     - Satisfy the child, increment `r` to 3 (next child).
   - Increment `l` to 6 (no more cookies).

### Step 5: Exit loop since `l = 6` (no more cookies left). The value of `r = 3` represents the number of satisfied children.

### Final Output:
- Number of kids assigned cookies: `3`



Time Complexity: O(N logN + M logM + M) where N is the length of the greedy array, M is the length of the cookies array. To sort the greedy and cookies array, the complexity is O(N logN) and O(M logM).

After sorting, we iterate over the arrays at most M times as M is the total number of cookies.
Since each child and each cookie is considered at most once, the time complexity of this part is linear in terms of the size of the cookie array, which is O(M).
Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.
