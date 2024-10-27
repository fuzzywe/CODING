1. 1D/2D Array Counting Problems

These problems often require counting subarrays, subsequences, or submatrices with specific properties, and slight variations in counting logic or result tracking can adapt the solution to multiple problems.

Count Square Submatrices with All Ones - Count all submatrices with only 1s.

Maximal Square - Find the largest square with only 1s and return its area.

Largest Rectangle in Histogram - Identify the largest rectangular area in a histogram (similar logic used in maximal submatrices).

Count Submatrices with All Ones - Variants like "count rectangular submatrices," focusing on maximum width/height submatrices.

84. Largest Rectangle in Histogram
Solved
Hard
Topics
Companies
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:
![27 10 2024_08 21 51_REC](https://github.com/user-attachments/assets/9746fdfc-6f76-45b0-8299-9b1444df82cf)


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
Example 2:

![27 10 2024_08 22 05_REC](https://github.com/user-attachments/assets/ab32c475-f56a-4b4c-ba28-597d2d1d9e3b)

Input: heights = [2,4]
Output: 4
---
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s; // Stack to store indices of histogram bars
        int maxArea = 0; // Variable to keep track of the maximum area

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            s.push(i);
        }

        // Calculate area for remaining bars in the stack
        while (!s.empty()) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? heights.size() : heights.size() - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};

```
---
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // this problem should be solved using stack .
        /* whenever you see a monotonic increase in the input which      
		would yield  the answer closest to 
		required you gotta understand that you should
		use  a stack datastructure to  calculate the answer*/
        // so let's begin by creating a stack and ans that we return 
        stack<int> st;
        int ans=0;
        //just to make our code understand better i'm adding 0 at the end of
        //heights
        heights.push_back(0);
        /* how do you add the elements to the stack ? mmmmmm? okay 
		let us think 
        way ,lets add all the ascending order elements to the stack so that 
		it
        looks like climbing steps .coz in that way we can have atleast the 
		min
        size step * number of elements in the stack .if we encounter any 
		bar with         lesser height than the top element of the stack ,we 
		will compute the 
        existing stack element area and pop the top element just to check 
		if the 
        current top < bar height ,if it is so ..add it to the stack ..i think it        
		will be more clearer if you go through the code*/
         //very important note .. we are adding indices ..not the values
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                //here we are checking if stack is empty or if we encounter 
				any 
                // number that doesn't satisfy our stack filling property
                int top=heights[st.top()];
                st.pop();
                int ran=st.empty()?-1:st.top();
                //this is to check if stack is empty, if so we will just take the                 //index
                ans=max(ans,top*(i-ran-1));
                // this is just to take the max area covered so far
            }
            st.push(i);
            //we push into the stack as long as it satsifies our stack condition
        }
        return ans;
        // i know it's not a very clever explanation ..but i tried to explain 
        //whatever i can ...HAPPY CODING!!
    }
};

```
