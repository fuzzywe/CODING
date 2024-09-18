Find Median of the given Array

Examples:

Example 1:
Input: [2,4,1,3,5]
Output: 3

Example 2:
Input: [2,5,1,7]
Output: 3.5
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{int n = v.size();
		    // Code here.
		    sort(v.begin(), v.end());
		    if(n%2==1)
		    {return v[n/2];}
		    else {
		        double median = (v[n/2] + v[(n/2)-1])/2.0;
		        return median;
		    }
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
O(n log n) due to the sorting operation, as the constant time to compute the median is insignificant compared to sorting.
O(n) for storing the input array. The sorting itself is in-place, so it doesn't add extra space proportional to the input size.

#include<bits/stdc++.h>
using namespace std;
void getMedian(int arr[],int n)
{
    sort(arr,arr+n);
    if(n%2==0)
    {
        int ind1 = (n/2)-1;
        int ind2 = (n/2);
        cout<<(double)(arr[ind1]+arr[ind2])/2;
    }
    else
    {
        cout<<arr[(n/2)];
    }
}
int main()
{
    int arr[] = {4,7,1,2,5,6};
    int n = 6;
    cout<<"The median of the array is: ";
    getMedian(arr,n);
    return 0;
}
Output:

The median of the array is: 4.5

Time Complexity: O(N*log N), Sorting of array

Space Complexity: O(1)


  If you need a better solution for finding the median of an unsorted array, you can use the **Quickselect Algorithm**. This approach has an **expected time complexity of O(n)**, making it more efficient than the sorting-based methods or heap-based methods for larger datasets.

### Quickselect Algorithm

The Quickselect algorithm is a selection algorithm to find the k-th smallest (or largest) element in an unordered list. It is related to the Quicksort sorting algorithm. You can use Quickselect to find the median by looking for the middle element (or two middle elements for even-sized arrays).

### Optimized C++ Code Using Quickselect

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }

    int quickselect(vector<int>& nums, int left, int right, int k) {
        if (left == right) return nums[left];
        
        int pivotIndex = partition(nums, left, right);
        
        if (pivotIndex == k) {
            return nums[pivotIndex];
        } else if (pivotIndex < k) {
            return quickselect(nums, pivotIndex + 1, right, k);
        } else {
            return quickselect(nums, left, pivotIndex - 1, k);
        }
    }

    double find_median(vector<int>& nums) {
        int n = nums.size();
        if (n % 2 == 1) {
            // If the size is odd, return the middle element
            return quickselect(nums, 0, n - 1, n / 2);
        } else {
            // If the size is even, return the average of the two middle elements
            int leftMedian = quickselect(nums, 0, n - 1, n / 2 - 1);
            int rightMedian = quickselect(nums, 0, n - 1, n / 2);
            return (leftMedian + rightMedian) / 2.0;
        }
    }
};

// Driver Code
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution ob;
        double ans = ob.find_median(nums);
        cout << fixed << setprecision(1) << ans << "\n";
    }
    return 0;
}
```

### Explanation:
1. **Partition Function**:
   - We choose the last element as a pivot and partition the array such that all elements smaller than or equal to the pivot are on the left side and those larger are on the right side.
2. **Quickselect Function**:
   - This recursively selects the k-th smallest element in the array.
   - If the pivot is at the k-th position, we return it. If it's greater, we search in the left partition; if smaller, we search in the right partition.
3. **Finding the Median**:
   - If the array has an odd number of elements, the median is the element at the middle index (`n/2`).
   - If the array has an even number of elements, the median is the average of the two middle elements (`n/2` and `n/2 - 1`).

### Time Complexity:
- **O(n)** on average: Quickselect has an average time complexity of **O(n)** because, unlike QuickSort, it only recurses on one half of the array each time.
- In the worst case, the time complexity could be **O(n^2)**, but this is rare.

### Space Complexity:
- **O(1)** (excluding the input array): This is an in-place algorithm, and no additional storage is required beyond the recursive function stack.
