Triplet Sum in Array
Examples

Input:n = 6, x = 13, arr[] = [1,4,45,6,10,8]
Output: 1
Explanation: The triplet {1, 4, 8} in the array sums up to 13.
Input: n = 6, x = 10, arr[] = [1,2,4,3,6,7]
Output: 1
Explanation: Triplets {1,3,6} & {1,2,7} in the array sum to 10. 
Input: n = 6, x = 24, arr[] = [40,20,10,3,6,7]
Output: 0
Explanation: There is no triplet with sum 24. 
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)
  class Solution {
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (A[i] + A[j] + A[k] == X) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
};
Complexity
Time Complexity: O(N3), As we are running 3 nested loops where N is the number of elements in the array.
Space Complexity: O(1), no extra space is used.

  Input Example:
Let’s consider an example for a dry run:

cpp
Copy code
A = {1, 4, 45, 6, 10, 8}
n = 6
X = 22
Objective:
Check if there exists a triplet in the array A[] whose sum equals 22.

Dry Run (Step by Step Execution):
Outer loop (i = 0):

The first element in the triplet will be A[0] = 1.
Now we need to find two other elements whose sum with 1 equals 22.
Middle loop (j = 1):
The second element in the triplet will be A[1] = 4.

Inner loop (k = 2):
The third element in the triplet will be A[2] = 45.
Check: 1 + 4 + 45 = 50 (not equal to 22).
Inner loop (k = 3):
The third element in the triplet will be A[3] = 6.
Check: 1 + 4 + 6 = 11 (not equal to 22).
Inner loop (k = 4):
The third element in the triplet will be A[4] = 10.
Check: 1 + 4 + 10 = 15 (not equal to 22).
Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 1 + 4 + 8 = 13 (not equal to 22).
Middle loop (j = 2):
The second element in the triplet will be A[2] = 45.

Inner loop (k = 3):
The third element in the triplet will be A[3] = 6.
Check: 1 + 45 + 6 = 52 (not equal to 22).
Inner loop (k = 4):
The third element in the triplet will be A[4] = 10.
Check: 1 + 45 + 10 = 56 (not equal to 22).
Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 1 + 45 + 8 = 54 (not equal to 22).
Middle loop (j = 3):
The second element in the triplet will be A[3] = 6.

Inner loop (k = 4):
The third element in the triplet will be A[4] = 10.
Check: 1 + 6 + 10 = 17 (not equal to 22).
Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 1 + 6 + 8 = 15 (not equal to 22).
Middle loop (j = 4):
The second element in the triplet will be A[4] = 10.

Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 1 + 10 + 8 = 19 (not equal to 22).
Outer loop (i = 1):

The first element in the triplet will be A[1] = 4.
Now we need to find two other elements whose sum with 4 equals 22.
Middle loop (j = 2):
The second element in the triplet will be A[2] = 45.

Inner loop (k = 3):
The third element in the triplet will be A[3] = 6.
Check: 4 + 45 + 6 = 55 (not equal to 22).
Inner loop (k = 4):
The third element in the triplet will be A[4] = 10.
Check: 4 + 45 + 10 = 59 (not equal to 22).
Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 4 + 45 + 8 = 57 (not equal to 22).
Middle loop (j = 3):
The second element in the triplet will be A[3] = 6.

Inner loop (k = 4):
The third element in the triplet will be A[4] = 10.
Check: 4 + 6 + 10 = 20 (not equal to 22).
Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 4 + 6 + 8 = 18 (not equal to 22).
Middle loop (j = 4):
The second element in the triplet will be A[4] = 10.

Inner loop (k = 5):
The third element in the triplet will be A[5] = 8.
Check: 4 + 10 + 8 = 22 (EQUAL TO 22!).
Triplet Found: Since the sum 4 + 10 + 8 = 22 is equal to X, the function returns 1 (or true).

Final Output:
The function returns 1 because the triplet {4, 10, 8} adds up to 22.

Summary of Steps:
The outer loop iterates over the first element of the triplet.
The middle loop iterates over the second element of the triplet.
The inner loop iterates over the third element of the triplet.
If the sum of the triplet matches X, the function returns 1 (true).
If no such triplet is found by the end of the loops, the function returns 0 (false). In this case, a triplet was found, so the function returned 1




  Intuition
By Sorting the array the efficiency of the algorithm can be improved. This efficient approach uses the two-pointer technique. Traverse the array and fix the first element of the triplet. Now use the Two Pointers algorithm to find if there is a pair whose sum is equal to x – array[i]. Two pointers algorithm take linear time so it is better than a nested loop.

Implementation
First sort the entire array.
Now we will try all a[i] values and then try to find if there is pair with sum = X-a[i] after the current index i.
Now we can easily do this using two pointers. We will keep j=i+1 and k=n-1.
Now if a[i]+a[j]+a[k]==X, we return true.
If a[i]+a[j]+a[k]<X, we increment j by 1.
Similarly, if a[i]+a[j]+a[k]>X, we decrement k by 1.
If no triplet is found then return false.
Example : let a=[1, 2, 4, 3, 6] and X=10.
After sorting , a=[1, 2, 3, 4, 6]. 
Now we fix i=0, so a[i]=1. Let j=i+1=1 and k=n-1=4.
Now we have a[i]+a[j]+a[k]=1+2+6=9<X.
So we do j=j+1=2.
Now we have a[i]+a[j]+a[k]=1+3+6=10=X.
So we found the triplet with given sum so we return true.
Code

class Solution {
  public:

    // Function to find if there exists a triplet in the
    // array arr[] which sums up to x.
    bool find3Numbers(int arr[], int n, int x) {
        int l, r;

        // Sorting the elements.
        sort(arr, arr + n);

        // Traversing the array elements.
        for (int i = 0; i < n - 2; i++) {
            // Taking two pointers. One at element after ith index and another
            // at the last index.
            l = i + 1;
            r = n - 1;
            while (l < r) {
                // If sum of elements at indexes i, l and r is equal
                // to required number, we return true.
                if (arr[i] + arr[l] + arr[r] == x)
                    return true;
                // Else if the sum is less than required number, it means we need
                // to increase the sum so we increase the left pointer l.
                else if (arr[i] + arr[l] + arr[r] < x)
                    l++;
                // Else the sum is more than required number and we need to
                // decrease the sum so we decrease the right pointer r.
                else
                    r--;
            }
        }

        // returning false if no triplet sum equal to required number is present.
        return false;
    }
};
Complexity
Time Complexity: O(N2), since sorting takes O(N log(N)) and we run nested for loop which takes O(N2) hence overall time O(N2).
Space Complexity: O(1), no extra space is used.
  et's dry-run the function with this input:

cpp
Copy code
arr = {1, 4, 45, 6, 10, 8}
n = 6
x = 22
Objective:
Check if there exists a triplet in the array arr[] whose sum equals 22.

Dry Run (Step-by-Step Execution):
Initial State:
Array: {1, 4, 45, 6, 10, 8}
Sorted Array after sort(arr, arr + n): {1, 4, 6, 8, 10, 45}
Outer loop (i = 0):

First element: arr[0] = 1
Set pointers:
l = i + 1 = 1 (points to arr[1] = 4)
r = n - 1 = 5 (points to arr[5] = 45)
Inner while loop (l < r):
Iteration 1:

Check sum: arr[0] + arr[1] + arr[5] = 1 + 4 + 45 = 50 (greater than 22)
Decrease right pointer r--: r = 4 (points to arr[4] = 10)
Iteration 2:

Check sum: arr[0] + arr[1] + arr[4] = 1 + 4 + 10 = 15 (less than 22)
Increase left pointer l++: l = 2 (points to arr[2] = 6)
Iteration 3:

Check sum: arr[0] + arr[2] + arr[4] = 1 + 6 + 10 = 17 (less than 22)
Increase left pointer l++: l = 3 (points to arr[3] = 8)
Iteration 4:

Check sum: arr[0] + arr[3] + arr[4] = 1 + 8 + 10 = 19 (less than 22)
Increase left pointer l++: l = 4 (now l == r, exit the loop)
Outer loop (i = 1):

First element: arr[1] = 4
Set pointers:
l = i + 1 = 2 (points to arr[2] = 6)
r = n - 1 = 5 (points to arr[5] = 45)
Inner while loop (l < r):
Iteration 1:

Check sum: arr[1] + arr[2] + arr[5] = 4 + 6 + 45 = 55 (greater than 22)
Decrease right pointer r--: r = 4 (points to arr[4] = 10)
Iteration 2:

Check sum: arr[1] + arr[2] + arr[4] = 4 + 6 + 10 = 20 (less than 22)
Increase left pointer l++: l = 3 (points to arr[3] = 8)
Iteration 3:

Check sum: arr[1] + arr[3] + arr[4] = 4 + 8 + 10 = 22 (EQUAL TO 22!)
Triplet Found: The sum of 4 + 8 + 10 = 22 matches x. The function immediately returns true.

Summary of Steps:
The array is first sorted to enable the two-pointer technique.
The outer loop picks an element arr[i] as the first element of the triplet.
The inner loop uses two pointers, l (left) and r (right), to check if the sum of arr[i] + arr[l] + arr[r] equals x.
If the sum is less than x, the left pointer is incremented to increase the sum. If it's greater, the right pointer is decremented to reduce the sum.
If a triplet is found, the function returns true.
If no triplet is found by the end of the loops, the function returns false.
Final Output:
In this example, the function returns true because the triplet {4, 8, 10} adds up to 22f

Alternate Approach
Intuition
Use Hashing: This approach uses extra space but is simpler than the two-pointers approach. Run two loops outer loop from start to end and the inner loop from i+1 to end. Create a hashmap or set to store the elements in between i+1 to j-1. So if the given sum is x, check if there is a number in the set that is equal to x - arr[i] - arr[j]. If yes print the triplet.

Implementation
Traverse the array from start to end. (loop counter i)
Create a HashMap or set to store unique pairs.
Run another loop from i+1 to end of the array. (loop counter j)
If there is an element in the set which is equal to x- arr[i] - arr[j], then return true.
Insert the jth element in the set.
If triplet not found then return false.
Code

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        //Your Code Here
        for (int i = 0; i < n - 2; i++) 
        {
    
            // Find pair in subarray A[i+1..n-1]
            // with sum equal to sum - A[i]
            unordered_set<int> s;
            int curr_sum = X - A[i];
            for (int j = i + 1; j < n; j++) 
            {
                if (s.find(curr_sum - A[j]) != s.end()) 
                {
                    return true;
                }
                s.insert(A[j]);
            }
        }
    
        // If we reach here, then no triplet was found
        return false;
    }

};
Complexity
Time complexity: O(N2), Since we are running a nested loop.
Auxiliary Space: O(N), since n extra space has been taken for hashmap or set.



