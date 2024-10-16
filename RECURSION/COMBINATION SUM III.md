https://leetcode.com/problems/combination-sum-iii/description/


Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

```cpp

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>comb;
        vector<int>candidates(9);
        iota(candidates.begin(),candidates.end(),1);
        combinationway(candidates,n,k,0,comb,res);
        return res;
    }
    private:
    bool combinationway(vector<int>&candidates, int target,int length,int index,vector<int>&comb,vector<vector<int>>&res)
    {if(comb.size()>length)
    {
        return false;
    }
        if(target==0 && comb.size()==length)

        {
res.push_back(comb);
return true;
        }
        else if(target<0)
        {
            return false;
        }
        for(int i=index;i<candidates.size();i++)
        {
            comb.push_back(candidates[i]);
           auto ans = combinationway(candidates,target-candidates[i],length,i+1,comb,res);
            comb.pop_back();
            if(!ans)
            {
                return true;
            }
        }return true;
    }
};

```
