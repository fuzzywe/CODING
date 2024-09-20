Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array using binary search.

  class Solution {
  public:
     int binarysearch(vector<int> &arr, int k) {
        // code here
        int low =0;
        int high= arr.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]==k){
                return mid;
            }
            else if(arr[mid]<k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Time Complexity

The time complexity of binary search is O(log n), where n is the number of elements in the array. Here's why:

    The algorithm splits the search space in half during each iteration. Each time, the size of the array is reduced by half.
    At every iteration, we perform constant-time operations such as comparison and updating low and high pointers.
    Since halving continues until the search space becomes empty (or the element is found), the number of iterations is proportional to the logarithm of n base 2, hence O(log n).

Dry Run Example

Let's dry run the code with a sample array to understand how it works.
Input Example

Let:

    arr = [1, 2, 4, 7, 10, 13, 15]
    k = 7

Initial Setup:

    low = 0
    high = 6 (since the array size is 7)

Step 1: First Iteration

    mid = low + (high - low) / 2
    mid = 0 + (6 - 0) / 2 = 3
    Now, arr[mid] = arr[3] = 7
    Since arr[mid] == k, the function returns mid = 3.

The element is found at index 3 after just one iteration.
Another Example

Let:

    arr = [1, 2, 4, 7, 10, 13, 15]
    k = 10

Initial Setup:

    low = 0
    high = 6

Step 1: First Iteration

    mid = low + (high - low) / 2 = 0 + (6 - 0) / 2 = 3
    Now, arr[mid] = arr[3] = 7
    Since arr[mid] < k, update low = mid + 1 = 3 + 1 = 4

Step 2: Second Iteration

    mid = low + (high - low) / 2 = 4 + (6 - 4) / 2 = 5
    Now, arr[mid] = arr[5] = 13
    Since arr[mid] > k, update high = mid - 1 = 5 - 1 = 4

Step 3: Third Iteration

    mid = low + (high - low) / 2 = 4 + (4 - 4) / 2 = 4
    Now, arr[mid] = arr[4] = 10
    Since arr[mid] == k, the function returns mid = 4.

The element is found at index 4 after three iterations.
Detailed Iteration Breakdown

    Initial bounds:
        low = 0
        high = arr.size() - 1

    Calculate mid:
        mid = low + (high - low) / 2

    Check condition:
        If arr[mid] == k, return mid.
        If arr[mid] < k, search in the right half by updating low = mid + 1.
        If arr[mid] > k, search in the left half by updating high = mid - 1.

    Stop condition:
        The loop continues until low <= high. If the loop ends and no match is found, return -1.

Conclusion

    Time Complexity: O(log n)
    Space Complexity: O(1) (since no extra space is used apart from variables)
