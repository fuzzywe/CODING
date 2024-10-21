
Non Repeating Numbers


https://www.geeksforgeeks.org/problems/finding-the-numbers0215/1


Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs whereas the other two number occur exactly once and are distinct. Find the other two numbers. Return in increasing order.

Example 1:

Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation:
3 and 4 occur exactly once.
Example 2:

Input:
N = 1
arr[] = {2, 1, 3, 2}
Output:
1 3
Explanation:
1 3 occur exactly once.

---

```cpp
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0; i< nums.size(); i++){
            mp[nums[i]]++;
        }
        for(auto elem:mp){
            if(elem.second == 1){
                ans.push_back(elem.first);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
```

Runtime Error 
Test Cases Passed: 
1110 /1113
Time limit exceeded.

Your program took more time than expected.Expected Time Limit : 1.3sec
Hint : Please optimize your code and submit again.

---

```cpp
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    
        // Code here.
        vector<int> singleNumber(vector<int> nums) 
    {
        vector<int>v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n-1;i++)
        {
            if((nums[i]!=nums[i+1])&&(nums[i]!=nums[i-1]))
            {
                v.push_back(nums[i]);               
            }
        }
        if(nums[0]!=nums[1])v.push_back(nums[0]);
        if(nums[n-1]!=nums[n-2])v.push_back(nums[n-1]);
        sort(v.begin(),v.end());
        return v;
    
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
```
