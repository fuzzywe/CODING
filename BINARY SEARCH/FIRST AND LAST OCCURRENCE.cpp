First and Last Occurrences in Array


4

0
Problem Statement: Given a sorted array arr of n integers and a target value k. Write a program to find the indices of the first and the last occurrences of the target value. If the target is not found then return -1 as indices.

Note: Consider 0-based indexing

Pre-requisites: Lower Bound,  Upper Bound, & Binary Search

Examples
Example 1:
Input Format: n = 8, arr[] = {2, 4, 6, 8, 8, 8, 11, 13}, k = 8
Result: 3 5
Explanation: The first occurrence of 8 is at index 3 and the last occurrence is at index 5.

Example 2:
Input Format: n = 8, arr[] = {2, 4, 6, 8, 8, 8, 11, 13}, k = 10
Result: -1 -1
Explanation: The target value is not present in the array. So, we have returned -1 as the indices of the first and the last occurrence.
Practice:
Solve Problem
code-studio
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1:
Algorithm / Intuition
Solution 1 (Using linear search): 
Basically, we will traverse the entire array to find the first and the last occurrences. The steps are as follows:

Algorithm:
First, we will declare two variables ‘first’(to store the first occurrence) and ‘last’(to store the last occurrence). We will initialize them with -1.
We will start traversing the array using a loop. 
When we first encounter the element k in the array, we will store the index in the first and last variables.
But for the next occurrences of k, we will not update the variable ‘first’ instead, we will only update the last variable with the current index. In order to do this update, we will check the value of the variable ‘first’. If the value is -1(i.e. we are facing k for the first time), we will update both the variables, and otherwise, we will only update the variable ‘last’.
Dry-run: Please refer to the video for it.

Code
C++
Java
Python
JavaScript
Copy

#include <bits/stdc++.h>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            if (first == -1) first = i;
            last = i;
        }
    }
    return {first, last};
}


int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}

Output: The first and last positions are: 3 5

Complexity Analysis
Time Complexity: O(N), N = size of the given array
Reason: We are traversing the entire array.

Space Complexity: O(1) as we are not using any extra space.

Solution 2:
Algorithm / Intuition
Solution 2: (Using lower and upper bound): 

We are going to solve this problem using the concepts of binary search algorithms.

The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

Now, we can either write the codes from scratch based on the Binary Search algorithm or we can use the lower bound and the upper bound algorithm to do the same.

In the preceding articles, we have discussed the Lower Bound and the Upper Bound algorithm in detail. Lower bound returns an index, ind, such that arr[ind] >= x(i.e. target element), and similarly, the upper bound returns the index of the first element that is greater than the target element i.e. arr[ind] > x.

For example, if the given array is {2, 4, 6, 8, 8, 8, 11, 13}, and the target k = 8, the lower bound of 8 will be at index 3(lb), and the upper bound will return index 6(ub). 

Therefore,
the first occurrence of the element = lb(the index returned by lower bound)
and the last occurrence = (ub-1)(ub = the index returned by upper bound).

There are some edge cases.

Edge Case 1: If the element is not present in the array.

If the target number is not present in the array, the lower bound will return the index of the nearest greater element. So, in the code, we have to check the following:
If arr[lb] != k: The element is not present in the array and so, there will be no first or last occurrences. So, we will return -1.
Edge Case 2: If the element is not present in the array and all the array elements are smaller than the target number.

In this case, lower bound will return the imaginary index n i.e. the size of the array. We need to handle this case in our code as well.
If lb == n: No first or last occurrence exists. So, we will return -1.
Note: Based on the index returned by the lower bound, we will decide if we need to calculate the upper bound because the absence of the first occurrence will guarantee that there will be no last occurrence.

Algorithm:

We will implement the upperBound() and lowerBound() functions. For the implementations, please refer to the articles: Lower Bound and Upper Bound.

We will first calculate the index of the first occurrence(lb) using the lower bound ().
If lb == n or arr[lb] != k: We will return -1.
Otherwise, We will calculate the upper bound i.e. ub using the upper bound (). Therefore, the last occurrence = ub-1.
Finally, we will return to the first and last positions of the target.
Dry-run: Please refer to the video for it.

Code
C++
Java
Python
JavaScript
Copy

#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int lb = lowerBound(arr, n, k);
    if (lb == n || arr[lb] != k) return { -1, -1};
    int ub = upperBound(arr, n, k);
    return {lb, ub - 1};
}


int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}

Output: The first and last positions are: 3 5

Complexity Analysis
Time Complexity: O(2*logN), where N = size of the given array.
Reason: We are basically using a lower-bound and upper-bound algorithm.

Space Complexity: O(1) as we are using no extra space.

Solution 3:
Algorithm / Intuition
Solution 3: (Code written from scratch using Binary Search): 
We will basically implement 2 binary searches to find the first and the last occurrence. The algorithms are given below:

Algorithm:
firstOccurrence():

We will declare the 2 pointers and a ‘first’ variable initialized to -1(as If we don’t find any index, we will return -1).

Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index, and high will point to the last index.
Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Compare arr[mid] with k: With comparing arr[mid] to k, we can observe 3 different cases:
Case 1 - If arr[mid] == k: This condition means that the index mid may be an answer. So, we will update the ‘first’ variable with mid and search in the left half if there is any smaller index that satisfies the same condition as we want the ‘first’ variable to be as minimum as possible.
Case 2 - If arr[mid] < k: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
Case 3: If arr[mid] > k: In this case, mid cannot be our answer and we need to find some smaller element. So, we will eliminate the right half and search in the left half for the answer.
The above process will continue until the pointer low crosses high.

Note: If the firstOccurrence() function returns a value of -1, it indicates that the target element is not found in the array. In such a scenario, there is no need to proceed with the lastOccurrence() function. We can directly conclude that the element is not present and return -1 from this step.

lastOccurrence():

We will declare the 2 pointers and a ‘last’ variable initialized to -1(as If we don’t find any index, we will return -1).

Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Compare arr[mid] with k: With comparing arr[mid] to k, we can observe 3 different cases:
Case 1 - If arr[mid] == k: This condition means that the index mid may be an answer. So, we will update the ‘last’ variable with mid and search in the right half if there is any larger index that satisfies the same condition as we want the ‘last’ variable to be as maximum as possible.
Case 2 - If arr[mid] < k: In this case, mid cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
Case 3: If arr[mid] > k: In this case, mid cannot be our answer and we need to find some smaller element. So, we will eliminate the right half and search in the left half for the answer.
The above process will continue until the pointer low crosses high. Finally, we will return the ‘first’ and the ‘last’ variables.

Code
C++
Java
Python
JavaScript
Copy

#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            first = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return first;
}

int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] == k) {
            last = mid;
            //look for larger index on the right
            low = mid + 1;
        }
        else if (arr[mid] < k) {
            low = mid + 1; // look on the right
        }
        else {
            high = mid - 1; // look on the left
        }
    }
    return last;
}


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return { -1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}


int main()
{
    vector<int> arr =  {2, 4, 6, 8, 8, 8, 11, 13};
    int n = 8, k = 8;
    pair<int, int> ans = firstAndLastPosition(arr, n, k);
    cout << "The first and last positions are: "
         << ans.first << " " << ans.second << "\n";
    return 0;
}

Output: The first and last positions are: 3 5

Complexity Analysis
Time Complexity: O(2*logN), where N = size of the given array.
Reason: We are basically using the binary search algorithm twice.

Space Complexity: O(1) as we are using no extra space.
