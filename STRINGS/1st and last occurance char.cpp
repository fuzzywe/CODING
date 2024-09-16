Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.

//Initial Template for Java
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> ans(2, -1);
        
        // Find the first occurrence of x
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                ans[0] = mid;
                right = mid - 1; 
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    
        // Find the last occurrence of x
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x)
            {
                ans[1] = mid;
                left = mid + 1; 
            }
            else if (arr[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return ans;
    }
};
Time Complexity: O(logn), As in this we use binary search to find the answer whose complexity is O(logn) as in binary search each time we divide the search space by half.
Space Complexity: O(1), As the code uses a fixed amount of extra space to store the ans vector, which has a constant size (2 elements).


class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        
        vector<int>ans;
        int first = -1, last = -1;
         
        for (int i = 0; i < n; i++) {
            if (x != arr[i])
                continue;
            if (first == -1)
                first = i;
            last = i;
        }
        
        if (first != -1){
            ans.push_back(first);
            ans.push_back(last);
        }
        else{
              ans.push_back(-1);
            ans.push_back(-1);
        }
    
        return ans;
    }
};
Time Complexity: O(n), As we traverse the entire array once.
Space Complexity :O(1), As we only use a constant amount of extra space to store first and last, as well as the result vector, which has a fixed size of 2.
