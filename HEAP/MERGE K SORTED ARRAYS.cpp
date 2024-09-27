Merge k Sorted Arrays
Difficulty: MediumAccuracy: 67.25%Submissions: 100K+Points: 4
Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, and list in python).


Examples :

Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)

Brute Force Approach:
Intuition
Create an output array of size (K * K) and then copy all the elements into the output array followed by sorting.

Example:
arr1=[1,2,3,6]
arr2=[4,5,6,7]
arr3=[1,4,5,7]

output vector=[1,2,3,6,4,5,6,7,1,4,5,7]
sorted result= [1,1,2,3,4,4,5,5,6,6,7,7] 

Implementation
Create an output vector. 
Traverse the matrix from start to end and push all the elements in the output vector.
Sort and return the output vector.
Code:


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        for(int i=0;i<K;i++) {
            for(int j=0;j<K;j++) {
                ans.push_back(arr[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
 

Complexity
Time Complexity: O(K2 * log (K2)), Since the resulting vector, is of size K2, and sorting of the vector of size K2 takes (K2 * log (K2) time.
Space Complexity: O(K* K), The output array is of size K * K.

  

expected approach:


//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}

code platform:

// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i =0;i<K;i++){
            for(int j=0;j<K;j++){
            pq.push(arr[i][j]);}
        }
        while(!pq.empty())
        {
            int temp = pq.top();
            ans.push_back(temp);
            pq.pop();
        }return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends
