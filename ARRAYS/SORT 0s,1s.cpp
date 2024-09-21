Sort 0s, 1s and 2s
Difficulty: EasyAccuracy: 50.58%Submissions: 698K+Points: 2
Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 0]
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int cnt1 =0,cnt2 =0,cnt3 =0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i] ==0) cnt1++;
            else if(arr[i] ==1) cnt2++;
            else if(arr[i] ==2) cnt3++;
        }
        for (int i=0;i<cnt1;i++) {arr[i]=0;}
        for(int i=cnt1;i<cnt1+cnt2;i++){arr[i]=1;}
        for(int i=cnt1+cnt2;i<arr.size();i++) {arr[i] = 2;}
    }//
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

Time Complexity: O(N) + O(N), where N = size of the array. First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.

Space Complexity: O(1) as we are not using any extra space.


  BETTER:

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

Output:
After sorting:
0 0 1 1 2 2  

Complexity Analysis
Time Complexity: O(N), where N = size of the given array.
Reason: We are using a single loop that can run at most N times.

Space Complexity: O(1) as we are not using any extra space.

  class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>freq(3,0);
        for(auto it:nums){
            freq[it]++;
        }
        int j=0;
        for(int i=0;i<3;i++){
            while(freq[i]>0){
                nums[j]=i;
                j++;
                freq[i]--;
            }
        }
    }
};
Complexity
Time complexity: O(n)
Space complexity: O(1)

  Dutch National Flag Algo (2 pointer)

Complexity
Time complexity: O(n)
Space complexity: O(1)
Code
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l, m, r;
        l = 0;
        m = 0;
        r = nums.size() - 1;
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;
            }
            else if (nums[m] == 1)
                m++;
            else {
                swap(nums[m], nums[r]);
                r--;
            }
        }
    }
};
