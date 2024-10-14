https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Examples:

Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
Output : [1, 3, 2, 11, 6, -1, -7, -5]
Explanation: By doing operations we separated the integers without changing the order.
Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
Output : [7, 9, 10, 11, -5, -3, -4, -1]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

```cpp
Time Complexity: O(n) — both the first and second loops traverse the vector, making the overall time complexity linear in the size of a.
Space Complexity: O(n) — due to the extra vector b used to store the negative numbers.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
       vector<int>b;
      int j=0;
      for(int i=0;i<arr.size();i++){
          if(arr[i]<0)b.push_back(arr[i]);
          else arr[j++]=arr[i];
      }
      for(auto &i:b)arr[j++]=i;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends
```

```cpp

Time Complexity: O(n)
Space Complexity: O(n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int>neg;
      vector<int>pov;
      for(int i=0;i<arr.size();i++){
          if(arr[i]<0) neg.push_back(arr[i]);
          else pov.push_back(arr[i]);
      }
      int k=0;
      for(int i=0;i<pov.size();i++){
          arr[k++]=pov[i];
      }
      for(int i=0;i<neg.size();i++){
          arr[k++]=neg[i];
      }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends
```

