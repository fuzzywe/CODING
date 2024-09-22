Overlapping Intervals


0

1
Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Examples:

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]] 
Output: 1 
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping. 

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]] 
Output: 2 
Explanation: remove two [1,2] to make the rest of the intervals non-overlapping. 
Solution 
Disclaimer: Don't jump directly to the solution, try it out yourself first. 

Approach: We can know if an interval is overlapping another interval if the end of the current interval is less than the start of the next interval. 

Example - 1,3 and 2,4. 2,4 is overlapping because 2 starts before 3 ends.


Note: that in the question we are not supposed to merge intervals, if any interval overlaps, we completely remove that interval. 

Now, in order to minimize the no. of removals, we'll try to make our end point as small as possible .

Like in the case 1,100 11,22 1,11 2,12. If we start checking with end=100, we will have to remove all the other points. But if we sort it on the basis of end points 1,11 2,12 11,22 1,100. We remove 2,12 because that coincides with 1,11. Now 11,22 is the next interval, we remove 1,100 because that coincides. Ans is 2, which is the best case.

Example:

 intervals = [[1,2],[2,3],[3,4],[1,3]] 
Sort intervals :: 1,2 2,3 1,3 3,4 

Start =1 end = 2 Iterate from 1 to intervals.size()-1 

At iteration 1,  

End > intervals[i][0] , if cur end is greater than interval start. Not true, So this interval can be accepted. We  update start=2 end=3 

At iteration 2, 

End>intervals[i][0] , 3>1, true , So this interval is overlapping , we increment ans. We don't update start and end as this interval is being removed from the array. 

At iteration 3, 

End>intervals[i][0] , Not true , So this interval can be accepted . We update start=3 end=4 Loop Ends 

Code:

C++
#include<iostream> 
#include<bits/stdc++.h> 
using namespace std; 
//comparator function for sorting based on endpoints 
bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];} 
 
int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
 sort(intervals.begin(), intervals.end(),cmp); 
  
 int ans=0; 
 int start=intervals[0][0],end = intervals[0][1]; 
 for(int i=1;i<intervals.size();i++){ 
 if(intervals[i][0] < end){ 
 ans++; 
 } 
 else if(intervals[i][0] >= end){  
 start=intervals[i][0]; 
 end=intervals[i][1]; 
 } 
 } 
 return ans; 
 } 
int main(){ 
vector<vector<int>>intervals; 
intervals.push_back({1,100}); 
intervals.push_back({1,11}); 
intervals.push_back({11,22}); 
intervals.push_back({2,12}); 
cout<<eraseOverlapIntervals(intervals); 
return 0; 
} 
Output: 2

Time Complexity: O(n) 

Space Complexity: O(1)
