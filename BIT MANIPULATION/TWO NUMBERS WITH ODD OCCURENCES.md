https://www.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1

Two numbers with odd occurrences
Difficulty: MediumAccuracy: 49.49%Submissions: 60K+Points: 4
Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences.

Example 1:

Input:
N = 8
Arr = {4, 2, 4, 5, 2, 3, 3, 1}
Output: {5, 1} 
Explanation: 5 and 1 have odd occurrences.

Example 2:

Input:
N = 8
Arr = {1 7 5 7 5 4 7 4}
Output: {7, 1}
Explanation: 7 and 1 have odd occurrences.

Your Task:
You don't need to read input or print anything. Your task is to complete the function twoOddNum() which takes the array Arr[] and its size N as input parameters and returns the two numbers in decreasing order which have odd occurrences.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

---

BRUTE FORCE

```cpp
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        vector<long long int>v;
        map<long long int,int>mpp;
        
        for(int i=0;i<N;i++){
            
            mpp[Arr[i]]++;
        }
        
        for(auto it:mpp) if(it.second%2) v.push_back(it.first);
        
        if(v[0]<v[1]) swap(v[0],v[1]);
        
        return v;
    }
};

Time Complexity: O(n)
Auxiliary Space: O(n)

```

7 /25
Time limit exceeded.

Your program took more time than expected.Expected Time Limit : 1.94sec
Hint : Please optimize your code and submit again.

---

OPTIMIZED

```cpp
class Solution{
    
    public:
    
    vector<long long int> twoOddNum(long long int Arr[], long long int N){
        
        // Step 1: Xor all the elements
        long xr = 0;
        for(int i=0; i<N; i++) xr = xr ^ Arr[i];
        
        // Step 2: Find the rightmost set bit
        int rightMost = (xr & xr - 1) ^ xr;
        
        // Step 3: Store elements with rightmost set bit set into b1 and 0 into b2
        long long int b1 = 0, b2 = 0;
        for(int i=0; i<N; i++){
            
            if(Arr[i] & rightMost) b1 ^= Arr[i];
            else b2 ^= Arr[i];
            
        }
        
        if(b1 > b2) return {b1, b2};
        
        return {b2, b1};
        
    }
};

```

