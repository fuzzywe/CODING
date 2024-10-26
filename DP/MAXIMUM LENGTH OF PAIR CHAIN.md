646. Maximum Length of Pair Chain
Medium

![Maximum Length of Pair Chain - Leetcode 646 - Python 1-14 screenshot](https://github.com/user-attachments/assets/86d02834-5ef4-4800-817a-9de152c337e8)

![Maximum Length of Pair Chain - Leetcode 646 - Python 2-10 screenshot](https://github.com/user-attachments/assets/21f05421-568e-4b0c-ad10-d9c7f8698b50)

![Maximum Length of Pair Chain - Leetcode 646 - Python 2-24 screenshot](https://github.com/user-attachments/assets/73333e4a-7022-4d72-b290-5927599dc886)

![Maximum Length of Pair Chain - Leetcode 646 - Python 2-44 screenshot](https://github.com/user-attachments/assets/bce87103-739f-4bb1-8642-2dd39daa03fa)



https://leetcode.com/problems/maximum-length-of-pair-chain/description/

Similar Questions


435. Non-overlapping Intervals

56. Merge Intervals

1353. Maximum Number of Events That Can Be Attended


You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.

A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.

Return the length longest chain which can be formed.

You do not need to use up all the given intervals. You can select pairs in any order.

 

Example 1:

Input: pairs = [[1,2],[2,3],[3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4].
Example 2:

Input: pairs = [[1,2],[7,8],[4,5]]
Output: 3
Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].


Approach
sort(pairs.begin(), pairs.end(), compare);: The pairs are sorted using the custom comparison function compare. This sorting is done based on the ending values of the pairs in ascending order.

Initialize prev to 0 and res to 1:

prev keeps track of the index of the last selected pair that was added to the chain.
res represents the length of the current longest chain, initialized to 1 because the first pair is always included.
Loop through the pairs starting from the second pair (index 1):

If the ending value of the pair at index prev is less than the starting value of the current pair, it means that the current pair can be added to the chain. Increase the res count and update prev to the current index (i).
Return the final value of res, which represents the length of the longest chain of pairs.

Complexity
Time complexity:O(nlogn)
Space complexity:O(1)
Code

```cpp
class Solution {
public:
 static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
         sort(pairs.begin(),pairs.end(),compare);
        int prev=0;
        int res=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[prev][1]<pairs[i][0]){
                prev=i;
                res++;
            }
        }
        return res;
    }
};

```
Code 2
Approach
just sort according to start and explore the options Ie pick / not pick and memoize the code for code optimization.

```cpp
class Solution {
public:
	int solve(int i,int prev,vector<vector<int>>& pairs,int n,vector<vector<int>>& dp){
		if(i==n) return 0;

		if(dp[i][prev+1]!=-1) return dp[i][prev+1];

		int pick=-1e9;

		if(prev==-1 || pairs[prev][1]<pairs[i][0])pick=1+solve(i+1,i,pairs,n,dp);
		int not_pick=solve(i+1,prev,pairs,n,dp);

		return dp[i][prev+1]=max(pick,not_pick);
	}

	int findLongestChain(vector<vector<int>>& pairs) {
		int n=pairs.size();
		sort(pairs.begin(),pairs.end());
		vector<vector<int>> dp(n,vector<int>(n+1,-1));
		return solve(0,-1,pairs,n,dp);
	}
};

```
Complexity
Time complexity:O(n∗n)
Space complexity:O(n∗n)
