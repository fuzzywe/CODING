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

Time Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We traverse through both arrays linearly.

Space Complexity: O(n1+n2), where  n1 and n2 are the sizes of the given arrays.
Reason: We are using an extra array of size (n1+n2) to solve this problem.

  best soln:
#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    int n1 = a.size(), n2 = b.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return median(b, a);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}
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

  
