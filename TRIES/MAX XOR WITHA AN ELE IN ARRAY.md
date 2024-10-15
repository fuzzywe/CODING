https://leetcode.com/problems/maximum-xor-with-an-element-from-array/


1707. Maximum XOR With an Element From Array
Hard
Topics
Companies
Hint
You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

 

Example 1:

Input: nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
Output: [3,3,7]
Explanation:
1) 0 and 1 are the only two integers not greater than 1. 0 XOR 3 = 3 and 1 XOR 3 = 2. The larger of the two is 3.
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
Example 2:

Input: nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
Output: [15,-1,5]
```cpp
struct Node
{
    Node* length[2];
    void put(int bit,Node* node)
    {
        length[bit]=node;
    }

    Node* get(int bit)
    {
        return length[bit];
    }

    bool containsKey(int bit)
    {
        return (length[bit]!=NULL);
    }
};


class Solution {
public:
    void insert(int num,Node* root)
    {
            Node *node= root;
            for(int i=31;i>=0;i--)
            {
                int currbit=(num>>i) & 1;
                if(!node->containsKey(currbit))
                {
                    node->put(currbit,new Node());
                }
                node=node->get(currbit);
            } 
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> query;
        for(int i=0;i<queries.size();i++)
        {
         query.push_back({queries[i][1],queries[i][0],i});
        }

        int ms=query.size();
        int n=nums.size();

        sort(query.begin(),query.end());
        vector<int> result(ms);

        Node* root=new Node();
        int index=0;
        for(int i=0;i<ms;i++)
        {
            int x=query[i][1];
            int m=query[i][0];
            int pos=query[i][2];
            while(index<n && nums[index]<=m)
            {
                insert(nums[index],root);
                index++;
            }
            if(index==0)
             result[pos]=-1;
            else
            {
            int currSum=0;
            Node* node=root;
            for(int i=31;i>=0;i--)
            {
                int req=1-((x>>i)&1);
                if(node->containsKey(req))
                {
                 currSum |= (1<<i);
                 node=node->get(req);
                }
                else
                {
                    node=node->get(1-req);
                }
            }
            result[pos]=currSum;
            }
        }

        return result;
    }
};
```
