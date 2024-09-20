Maximum and minimum of an array using minimum number of comparisons
Last Updated : 14 Sep, 2024
Given an array of size N. The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

Examples:

Input: arr[] = {3, 5, 4, 1, 9}
Output: Minimum element is: 1
              Maximum element is: 9

Input: arr[] = {22, 14, 8, 17, 35, 3}
Output:  Minimum element is: 3
              Maximum element is: 35


  INT_MAX for mini:
You initialize mini with the largest possible value (INT_MAX) because you're looking for the smallest value in the array. By starting with the largest value, any number in the array will be smaller, ensuring the first comparison correctly updates mini. Then, each subsequent comparison will continue updating mini until the smallest element is found.

INT_MIN for maxi:
Similarly, you initialize maxi with the smallest possible value (INT_MIN) because you're searching for the largest value. Since every number in the array will be larger than INT_MIN, the first comparison will correctly update maxi. It continues updating until the largest value is found.


#include <iostream>
#include <limits.h>
using namespace std;

int setmini(int A[], int N)
{
    int mini = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (A[i] < mini) {
            mini = A[i];
        }
    }
    return mini;
}
int setmaxi(int A[], int N)
{
    int maxi = INT_MIN;

    for (int i = 0; i < N; i++) {
        if (A[i] > maxi) {
            maxi = A[i];
        }
    }
    return maxi;
}
int main()
{
    int A[] = { 4, 9, 6, 5, 2, 3 };
    int N = 6;
    cout <<"Minimum element is: " <<setmini(A, N) << endl;
    cout <<"Miximum  element is: "<< setmaxi(A, N) << endl;
}

Output
Minimum element is: 2
Miximum  element is: 9
Time Complexity: O(N)

Auxiliary Space: O(1)

Maximum and minimum of an array using Sorting:
One approach to find the maximum and minimum element in an array is to first sort the array in ascending order. Once the array is sorted, the first element of the array will be the minimum element and the last element of the array will be the maximum element.

Step-by-step approach:

Initialize an array.
Sort the array in ascending order.
The first element of the array will be the minimum element.
The last element of the array will be the maximum element.
Print the minimum and maximum element.
Below is the implementation of the above approach:


// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int min;
    int max;
};

Pair getMinMax(int arr[], int n)
{
    Pair minmax;

    sort(arr, arr + n);

    minmax.min = arr[0];
    minmax.max = arr[n - 1];

    return minmax;
}

int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    Pair minmax = getMinMax(arr, arr_size);

    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max << endl;

    return 0;
}

// This code is contributed by Tapesh(tapeshdua420)

Output
Minimum element is 1
Maximum element is 3000
Time complexity: O(n log n), where n is the number of elements in the array, as we are using a sorting algorithm.
Auxilary Space: is O(1), as we are not using any extra space


CODE PLATFORM

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public: pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        long long min = INT_MAX;
        long long max = INT_MIN;
        for(int i =0;i<arr.size();i++){
            if(arr[i]>max){
                
                max = arr[i];
            }
             if(arr[i]<min){//DONT PUT ELSE
                min = arr[i];
            }
        }
        return {min,max};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends





2.//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        int n = arr.size();
      
        sort(arr.begin(),arr.end());
    
    // After sorting, the first element is the minimum and the last element is the maximum
    int mini = arr[0];
    int maxi = arr[n - 1];
return{mini,maxi};
}
       
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends

3.
  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        int maxelem=*max_element(arr.begin(),arr.end());
        int minelem=*min_element(arr.begin(),arr.end());
        
        return {minelem,maxelem};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<long long int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        pair<long long, long long> pp = ob.getMinMax(arr);
        cout << pp.first << " " << pp.second << endl;
    }
    return 0;
}
// } Driver Code Ends


