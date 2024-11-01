Median of two Sorted Arrays of Different Sizes


Input: arr1[] = {-5, 3, 6, 12, 15}, arr2[] = {-12, -10, -6, -3, 4, 10}
Output: The median is 3.
Explanation: The merged array is arr3[] = {-12, -10, -6, -5 , -3, 3, 4, 6, 10, 12, 15}. So the median of the merged array is 3.

Input: arr1[] = {2, 3, 5, 8}, arr2[] = {10, 12, 14, 16, 18, 20}
Output: The median is 11.
Explanation : The merged array is arr3[] = {2, 3, 5, 8, 10, 12, 14, 16, 18, 20}. The total number of the elements are even, so there are two middle elements.
Take the average between the two: (10 + 12) / 2 = 11

Input: arr1[] = {}, arr2[] = {2, 4, 5, 6}
Output: The median is 4.5
Explanation: The merges array is arr3[] = {2, 4, 5, 6}. The total number of elements are even, so there are two middle elements.
Take the average between the two: (4 + 5) / 2 = 4.5


  Example 1:
Input Format:
 n1 = 3, arr1[] = {2,4,6}, n2 = 3, arr2[] = {1,3,5}
Result:
 3.5
Explanation:
 The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 5, 6 }. As the length of the merged list is even, the median is the average of the two middle elements. Here two medians are 3 and 4. So the median will be the average of 3 and 4, which is 3.5.

Example 2:
Input Format:
 n1 = 3, arr1[] = {2,4,6}, n2 = 2, arr2[] = {1,3}
Result:
 3
Explanation:
 The array after merging 'a' and 'b' will be { 1, 2, 3, 4, 6 }. The median is simply 3.


```cpp

#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();

    vector<int> arr3;
    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < n1) arr3.push_back(a[i++]);
    while (j < n2) arr3.push_back(b[j++]);

    //Find the median:
    int n = n1 + n2;
    if (n % 2 == 1) {
        return (double)arr3[n / 2];
    }

    double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    return median;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}

```

![FireShot Capture 002 - ChatGPT - chatgpt com](https://github.com/user-attachments/assets/88f07213-a019-4a95-8e48-7d4431ef5a7b)

Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We traverse through both arrays linearly.

Space Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We are using an extra array of size (n1+n2) to solve this problem

---.

**  best soln:**

```cpp

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            
        if (nums1.size() > nums2.size()) swap(nums1, nums2); // make sure a1 is shorter
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        // range of a1 cut location: n1 means no right half for a1
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int cut1 = (lo + hi)/2; // cut location is counted to right half
            int cut2 = (n1 + n2)/2 - cut1;
            
            int l1 = cut1 == 0? INT_MIN : nums1[cut1-1];
            int l2 = cut2 == 0? INT_MIN : nums2[cut2-1];
            int r1 = cut1 == n1? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2? INT_MAX : nums2[cut2];
            
            if (l1 > r2) hi = cut1-1;
            else if (l2 > r1) lo = cut1+1;
            else return (n1+n2)%2? min(r1,r2) : (max(l1,l2) + min(r1,r2))/2.;
        }return 0.0;
    }

};
    

  

```

![image](https://github.com/user-attachments/assets/c1c044ea-abd7-4fea-9634-33c0c7ad145b)


![FireShot Capture 004 - ChatGPT - chatgpt com](https://github.com/user-attachments/assets/e4620c18-f5a4-4847-b664-d78ada9519f2)



Time Complexity: O(log(min(n1,n2))), where n1 and n2 are the sizes of two given arrays.
Reason: We are applying binary search on the range [0, min(n1, n2)].

Space Complexity: O(1) as no extra space is used.

Array a: {1, 4, 7, 10, 12}
Array b: {2, 3, 6, 15}
Step-by-Step Execution:

Initial Setup:

n1 = 5, n2 = 4
Since n1 > n2, swap a and b so a becomes {2, 3, 6, 15} and b becomes {1, 4, 7, 10, 12}.
Binary Search Initialization:

low = 0, high = 4 (size of a).
Binary Search Iteration:

First Iteration:

mid1 = (0 + 4) / 2 = 2
mid2 = (5 + 4 + 1) / 2 - 2 = 4
l1 = a[1] = 3
r1 = a[2] = 6
l2 = b[3] = 10
r2 = b[4] = 12
Condition l1 <= r2 and l2 <= r1 is not satisfied. Since l1 <= r2 is true, adjust low to mid1 + 1 which is 3.
Second Iteration:

mid1 = (3 + 4) / 2 = 3
mid2 = (5 + 4 + 1) / 2 - 3 = 3
l1 = a[2] = 6
r1 = a[3] = 15
l2 = b[2] = 7
r2 = b[3] = 10
Conditions are now satisfied. For odd total length, the median is max(l1, l2) which is 7.

  
