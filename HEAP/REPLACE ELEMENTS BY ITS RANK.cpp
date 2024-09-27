Replace elements by its rank in the array


30

3
Replace elements by its rank in the array

Problem Statement: Given an array of N integers, the task is to replace each element of the array by its rank in the array.

Examples:

Example 1:
Input: 20 15 26 2 98 6
Output: 4 3 5 1 6 2
Explanation: When sorted,the array is 2,6,15,20,26,98. So the rank of 2 is 1,rank of 6 is 2,rank of 15 is 3 and so…

Example 2:
Input: 1 5 8 15 8 25 9
Output: 1 2 3 5 3 6 4
Explanation: When sorted,the array is 1,5,8,8,9,15,25. So the rank of 1 is 1,rank of 5 is 2,rank of 8 is 3 and so…
Solution 1:Naive approach

Intuition: Use two for loops and calculate a rank for each element.

Approach:

Iterative over the array using a for loop.
Now use another for loop to check the number of elements having value less than the current element.
We can use a set to get the number of unique elements having value less than the current element.
Number of such unique elements + 1 is the rank of that element.
Code:

C++
Java
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
	for (int i = 0; i < n; i++) {
		set<int>s;
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[i]) {
				s.insert(arr[j]);
			}
		}
		cout << s.size() + 1 << " ";
	}

}
Output: 4 3 5 1 6 2

Time Complexity: O(N*N) as we are using double for loop.

Space Complexity: O(N) as we are using set.

Given array: {20, 15, 26, 2, 98, 6}

First iteration (i=0, arr[0]=20):

Inner loop checks all elements arr[j] where j=0 to 5:
arr[1] = 15 (15 < 20) → Insert into set s: s = {15}
arr[3] = 2 (2 < 20) → Insert into set s: s = {2, 15}
arr[5] = 6 (6 < 20) → Insert into set s: s = {2, 6, 15}
Set s after inner loop: {2, 6, 15}
Output: size(s) + 1 = 3 + 1 = 4
Second iteration (i=1, arr[1]=15):

Inner loop checks all elements arr[j] where j=0 to 5:
arr[3] = 2 (2 < 15) → Insert into set s: s = {2}
arr[5] = 6 (6 < 15) → Insert into set s: s = {2, 6}
Set s after inner loop: {2, 6}
Output: size(s) + 1 = 2 + 1 = 3
Third iteration (i=2, arr[2]=26):

Inner loop checks all elements arr[j] where j=0 to 5:
arr[0] = 20 (20 < 26) → Insert into set s: s = {20}
arr[1] = 15 (15 < 26) → Insert into set s: s = {15, 20}
arr[3] = 2 (2 < 26) → Insert into set s: s = {2, 15, 20}
arr[5] = 6 (6 < 26) → Insert into set s: s = {2, 6, 15, 20}
Set s after inner loop: {2, 6, 15, 20}
Output: size(s) + 1 = 4 + 1 = 5
Fourth iteration (i=3, arr[3]=2):

Inner loop checks all elements arr[j] where j=0 to 5:
No element is less than 2.
Set s after inner loop: {} (empty)
Output: size(s) + 1 = 0 + 1 = 1
Fifth iteration (i=4, arr[4]=98):

Inner loop checks all elements arr[j] where j=0 to 5:
arr[0] = 20 (20 < 98) → Insert into set s: s = {20}
arr[1] = 15 (15 < 98) → Insert into set s: s = {15, 20}
arr[2] = 26 (26 < 98) → Insert into set s: s = {15, 20, 26}
arr[3] = 2 (2 < 98) → Insert into set s: s = {2, 15, 20, 26}
arr[5] = 6 (6 < 98) → Insert into set s: s = {2, 6, 15, 20, 26}
Set s after inner loop: {2, 6, 15, 20, 26}
Output: size(s) + 1 = 5 + 1 = 6
Sixth iteration (i=5, arr[5]=6):

Inner loop checks all elements arr[j] where j=0 to 5:
arr[3] = 2 (2 < 6) → Insert into set s: s = {2}
Set s after inner loop: {2}
Output: size(s) + 1 = 1 + 1 = 2
Final Output:
The output for each iteration would be:

Copy code
4 3 5 1 6 2
Explanation of Outputs:
For each element in the array, you are finding how many elements are smaller than that element, and then adding 1 to include the current element itself. Thus, for each iteration, the program calculates the number of elements smaller than arr[i] and outputs the result.


  

Solution 2: optimized

Intuition: Sort the array and store the rank of the element in a map.

Approach:

Copy all the elements of the array in a dummy array.
Sort the dummy array.
Take a variable temp to calculate the rank of each element.Initially the value of temp is 1.
Maintain a map to store the rank of each element.
Now traverse through the dummy array,if element is previously not stored in map then store the value of element with the temp and then increament temp.
Now traverse through the original array and print the rank of that corresponding element using map.
Code:

C++
Java
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 6;
	int arr[n] = {20, 15, 26, 2, 98, 6};
	map<int, int>mp;
	int temp = 1;
	int brr[n];
	for (int i = 0; i < n; i++) {
		brr[i] = arr[i];
	}
	sort(brr, brr + n);
	for (int i = 0; i < n; i++) {
		//if element is previously not store in the map
		if (mp[brr[i]] == 0) {
			mp[brr[i]] = temp;
			temp++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << mp[arr[i]] << " ";
	}

}
Output: 4 3 5 1 6 2

Time Complexity:O(n)+O(nlogn)+O(n). O(n) for copying the elements from the original to the dummy array, O(nlogn) for sorting the dummy array, and O(n) for printing the ranks.

Space Complexity:O(N+N), for using dummy array and hashmap.
Let's break down this code and understand how it works, step-by-step.

### **Code Breakdown**

1. **Initialization and Input Array Setup:**
   ```cpp
   int n = 6;
   int arr[n] = {20, 15, 26, 2, 98, 6};
   ```
   - We are given an array `arr` with `n=6` elements: `{20, 15, 26, 2, 98, 6}`.

2. **Map and Temporary Variables:**
   ```cpp
   map<int, int>mp;
   int temp = 1;
   int brr[n];
   ```
   - A `map<int, int> mp` is used to store the rank of each element from `arr`.
   - The variable `temp` is initialized to 1, which will be used to assign ranks.
   - `brr[]` is a copy of the `arr[]` array, which will be used for sorting.

3. **Copying Array:**
   ```cpp
   for (int i = 0; i < n; i++) {
       brr[i] = arr[i];
   }
   ```
   - The array `brr[]` is initialized as a copy of `arr[]`. So initially, `brr[] = {20, 15, 26, 2, 98, 6}`.

4. **Sorting the Array:**
   ```cpp
   sort(brr, brr + n);
   ```
   - After sorting `brr[]`, the array becomes `brr[] = {2, 6, 15, 20, 26, 98}`.

5. **Assigning Ranks:**
   ```cpp
   for (int i = 0; i < n; i++) {
       if (mp[brr[i]] == 0) {
           mp[brr[i]] = temp;
           temp++;
       }
   }
   ```
for (int i = 0; i < n; i++):
This loop goes through each element in the sorted array brr[] (which is a sorted version of arr[]).
if (mp[brr[i]] == 0):
The condition checks if the current element brr[i] is not already present in the mp map.
In C++, when you access mp[brr[i]] for the first time, if brr[i] does not exist in the map, it will automatically initialize the value to 0 (since map is initialized with default values for new keys).
So, mp[brr[i]] == 0 means that the element brr[i] has not been assigned a rank yet.
mp[brr[i]] = temp;:
If the element brr[i] doesn't already have a rank, we assign it the current rank stored in temp.
temp++;:
After assigning a rank to the current element, temp is incremented by 1, so that the next unique element gets the next rank.
Example Walkthrough:
Let's say brr[] is the sorted version of the original array arr[]:

brr[] = {2, 6, 15, 20, 26, 98}
The goal of this loop is to assign a rank to each unique element in brr[].

Iteration 1 (i = 0):

brr[0] = 2
mp[2] == 0 → true, because 2 is not yet in the map.
We assign mp[2] = 1 (rank 1), then increment temp to 2.
Iteration 2 (i = 1):

brr[1] = 6
mp[6] == 0 → true, because 6 is not yet in the map.
We assign mp[6] = 2 (rank 2), then increment temp to 3.
Iteration 3 (i = 2):

brr[2] = 15
mp[15] == 0 → true, because 15 is not yet in the map.
We assign mp[15] = 3 (rank 3), then increment temp to 4.
Iteration 4 (i = 3):

brr[3] = 20
mp[20] == 0 → true, because 20 is not yet in the map.
We assign mp[20] = 4 (rank 4), then increment temp to 5.
Iteration 5 (i = 4):

brr[4] = 26
mp[26] == 0 → true, because 26 is not yet in the map.
We assign mp[26] = 5 (rank 5), then increment temp to 6.
Iteration 6 (i = 5):

brr[5] = 98
mp[98] == 0 → true, because 98 is not yet in the map.
We assign mp[98] = 6 (rank 6), then increment temp to 7.
By the end of the loop, the mp map will contain the following key-value pairs, representing the element and its rank:

mp[2] = 1
mp[6] = 2
mp[15] = 3
mp[20] = 4
mp[26] = 5
mp[98] = 6
Why check if (mp[brr[i]] == 0)?
This check ensures that each element in the sorted array brr[] is only assigned a rank once. If we encounter a repeated element in brr[] (which can happen if the array has duplicates), it won't be assigned a new rank. Instead, the previously assigned rank will be used.

This ensures that each unique element gets a unique rank based on its position in the sorted array.







   - This loop iterates through the sorted array `brr[]` and assigns ranks to each element using the `map mp`.
   - The rank (`temp`) is incremented for each unique element.
   - **Rank assignment process:**
     - `brr[0] = 2` → `mp[2] = 1`
     - `brr[1] = 6` → `mp[6] = 2`
     - `brr[2] = 15` → `mp[15] = 3`
     - `brr[3] = 20` → `mp[20] = 4`
     - `brr[4] = 26` → `mp[26] = 5`
     - `brr[5] = 98` → `mp[98] = 6`

6. **Outputting the Rank:**
   ```cpp
   for (int i = 0; i < n; i++) {
       cout << mp[arr[i]] << " ";
   }
   ```
   - Finally, for each element in the original array `arr[]`, the corresponding rank from the `map mp` is printed.
   - **Mapping process for output:**
     - `arr[0] = 20` → `mp[20] = 4`
     - `arr[1] = 15` → `mp[15] = 3`
     - `arr[2] = 26` → `mp[26] = 5`
     - `arr[3] = 2` → `mp[2] = 1`
     - `arr[4] = 98` → `mp[98] = 6`
     - `arr[5] = 6` → `mp[6] = 2`

### **Dry Run**

Given input array: `{20, 15, 26, 2, 98, 6}`

- **Step 1:** Copy `arr[]` to `brr[]` → `brr = {20, 15, 26, 2, 98, 6}`.
- **Step 2:** Sort `brr[]` → `brr = {2, 6, 15, 20, 26, 98}`.
- **Step 3:** Assign ranks to elements in `brr[]`:
  - `mp[2] = 1`
  - `mp[6] = 2`
  - `mp[15] = 3`
  - `mp[20] = 4`
  - `mp[26] = 5`
  - `mp[98] = 6`
- **Step 4:** Output the ranks of elements in `arr[]`:
  - For `arr[0] = 20` → Output `4`
  - For `arr[1] = 15` → Output `3`
  - For `arr[2] = 26` → Output `5`
  - For `arr[3] = 2` → Output `1`
  - For `arr[4] = 98` → Output `6`
  - For `arr[5] = 6` → Output `2`

### **Final Output:**
```
4 3 5 1 6 2
```

This code effectively maps each element in the array to its rank in the sorted order and prints the ranks in the original order of the array.
