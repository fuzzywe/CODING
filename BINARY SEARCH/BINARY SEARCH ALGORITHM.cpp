

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return mid;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = binarySearch(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}


Output: The target is at index: 2

Complexity Analysis
Time Complexity:
In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

Let’s derive the number of divisions mathematically,

If a number n can be divided by 2 for x times:
	2^x = n
Therefore, x = logn (base is 2)
So the overall time complexity is O(logN), where N = size of the given array.

Recursive Approach
Algorithm / Intuition
Recursive implementation:
Pre-requisite: Recursion section

Approach:
Assume, the recursive function will look like this: binarySearch(nums, low, high). It basically takes 3 parameters i.e. the array, the low pointer, and the high pointer. In each recursive call, we will change the value of low and high pointers to trim down the search space. Except for this, the rest of the steps will be the same.

The steps are as follows:

Step 1: Divide the search space into 2 halves:
In order to divide the search space, we need to find the middle point of it. So, we will take a ‘mid’ pointer and do the following:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Step 2: Compare the middle element with the target and trim down the search space:
In this step, we can observe 3 different cases:
If arr[mid] == target: We have found the target. From this step, we can return the index of the target, and the recursion will end.
If target > arr[mid]: This case signifies our target is located on the right half of the array. So, the next recursion call will be binarySearch(nums, mid+1, high).
If target < arr[mid]: This case signifies our target is located on the left half of the array. So, the next recursion call will be binarySearch(nums, low, mid-1).
Base case: The base case of the recursion will be low > high. If (low > high), the search space becomes invalid which means the target is not present in the array.
Note: For a better understanding, please watch the video at the bottom of the page.


#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int target) {

    if (low > high) return -1; //Base case.

    // Perform the steps:
    int mid = (low + high) / 2;
    if (nums[mid] == target) return mid;
    else if (target > nums[mid])
        return binarySearch(nums, mid + 1, high, target);
    return binarySearch(nums, low, mid - 1, target);
}

int search(vector<int>& nums, int target) {
    return binarySearch(nums, 0, nums.size() - 1, target);
}

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}

Output: The target is at index: 2

Complexity Analysis
Time Complexity:
In the algorithm, in every step, we are basically dividing the search space into 2 equal halves. This is actually equivalent to dividing the size of the array by 2, every time. After a certain number of divisions, the size will reduce to such an extent that we will not be able to divide that anymore and the process will stop. The number of total divisions will be equal to the time complexity.

Let’s derive the number of divisions mathematically,

If a number n can be divided by 2 for x times:
	2^x = n
Therefore, x = logn (base is 2)
So the overall time complexity is O(logN), where N = size of the given array.
