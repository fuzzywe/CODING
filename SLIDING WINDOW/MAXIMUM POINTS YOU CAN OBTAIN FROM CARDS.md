https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/solutions/2200713/c-sliding-window-easy-to-understand/

1423. Maximum Points You Can Obtain from Cards
Solved
Medium
Topics
Companies
Hint
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.


---


```cpp

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       //////////////////////
        // window of (size - k) size
        // remaining are k elements which are not included in window
        // the sum of those elements will be observed by sliding the window 
        // return the maximum of the sum of rest of the k elements in above step
        int i =0;
        int j = cardPoints.size()-k;
        //////////////////////
        int curr_sum = 0;
        
        for (int k = j;k<cardPoints.size(); k++) {
            curr_sum += cardPoints[k];
        }
        
        int res = curr_sum;
        
        while (j < cardPoints.size()) {
            curr_sum = curr_sum + cardPoints[i] - cardPoints[j];
            res = max(curr_sum, res);
            i++;
            j++;
        }
        return res;
    }
};




```

![image](https://github.com/user-attachments/assets/906237cd-21de-46a5-9e00-d1dc91bee722)

Intuition
The problem statement involves a scenario where we are given an array and allowed to take steps by selecting an element either from the start or end of the array. Once we select an element, it cannot be chosen again. The goal is to find a strategy that maximizes the sum of the selected elements. Let's understand it by an example!

photo_2023-05-28_11-58-46.jpg

To tackle the given problem, we can employ the sliding window technique to iteratively traverse the array.

Approach
We can break down the approach in five easy steps

The initial sum is calculated by adding the first k elements of cardPoints.
The maxSum variable is initialized with the initial sum.
The sliding window approach is used to calculate the sum by sliding the window from the beginning to the end. At each step, the sum is updated by subtracting the first element of the window while adding the next element.
The maxSum is updated whenever a larger sum is found.
Finally, the maxSum is returned as the maximum score.
Complexity
Time complexity: O(n)
Space complexity: O(1)
Code

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        
        // Calculate the initial sum of the first k elements
        for (int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        
        int maxSum = sum;
        
        // Sliding window approach
        // Calculate the sum by sliding the window from the beginning to the end
        // and subtracting the first element of the window while adding the next element
        for (int i = k - 1, j = n - 1; i >= 0; i--, j--) {
            sum -= cardPoints[i];
            sum += cardPoints[j];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};

```
