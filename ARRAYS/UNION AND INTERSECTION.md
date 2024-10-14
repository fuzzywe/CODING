

https://leetcode.com/problems/intersection-of-two-arrays/description/
Examples

Input: arr1[] = [1, 2, 3, 4, 5], arr2[] = [1, 2, 3]
Output: 5
Explanation: 1, 2, 3, 4 and 5 are the elements which comes in the union setof both arrays. So count is 5.
Input: arr1[] = [85, 25, 1, 32, 54, 6], arr2[] = [85, 2] 
Output: 7
Explanation: 85, 25, 1, 32, 54, 6, and 2 are the elements which comes in the union set of both arrays. So count is 7.
Input: arr1[] = [1, 2, 1, 1, 2], arr2[] = [2, 2, 1, 2, 1] 
Output: 2
Explanation: We need to consider only distinct. So count is 2.
 

Expected Time Complexity: O(n+m)
Expected Auxilliary Space: O(n+m)

find the frequency using single map :
why not unordered map?
  in unordered map the keys are stored in random order 
in map hte keys are stored in order(ascending order).

  //{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        // code here
        map<int,int>freq;
        vector<int> Union;
        int n = arr1.size();
        int m = arr2.size();
        for(int i=0;i<n;i++)
        {
            freq[arr1[i]]++;
        }
        for(int i=0;i<m;i++){
            freq[arr2[i]]++;
        }
       return freq.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.doUnion(a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends

using set:
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int doUnion(vector<int> arr1, vector<int> arr2) {
        // code here
        set<int>freq;// the mistake i did here i coded set<int,int>freq which is wrong as iam returning only the index
        vector<int> Union;
        int n = arr1.size();
        int m = arr2.size();
        for(int i=0;i<n;i++)
        {
            freq.insert(arr1[i]);
        }
        for(int i=0;i<m;i++){
            freq.insert(arr2[i]);
        }
       return freq.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> a;
        vector<int> b;

        string input;
        // For a
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // For b
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        cout << ob.doUnion(a, b) << endl;
    }

    return 0;
}
// } Driver Code Ends


RETURNING THE ARRAY OF UNION NUMBERS:

Example 1:
Input:

n = 5,m = 5.
arr1[] = {1,2,3,4,5}  
arr2[] = {2,3,4,4,5}
Output:

 {1,2,3,4,5}

Explanation: 

Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5} 

Example 2:
Input:

n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output:
 {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation:
 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 



Examples
Example 1:
Input:

n = 5,m = 5.
arr1[] = {1,2,3,4,5}  
arr2[] = {2,3,4,4,5}
Output:

 {1,2,3,4,5}

Explanation: 

Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1
Distnict Elemennts in arr2 are : No distinct elements.
Union of arr1 and arr2 is {1,2,3,4,5} 

Example 2:
Input:

n = 10,m = 7.
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12}
Output:
 {1,2,3,4,5,6,7,8,9,10,11,12}
Explanation:
 
Common Elements in arr1 and arr2  are:  2,3,4,5
Distnict Elements in arr1 are : 1,6,7,8,9,10
Distnict Elemennts in arr2 are : 11,12
Union of arr1 and arr2 is {1,2,3,4,5,6,7,8,9,10,11,12} 
Practice:
Solve Problem
code-studio
Disclaimer: Don’t jump directly to the solution, try it out yourself first.

Solution 1:
Algorithm / Intuition
Solution 1: Using Map
Our aim is to find the common elements in arr1 and arr2, and the distinct elements of arr1,arr2. Use a Single map to find the frequencies of elements in arr1 and arr2.

As we are using only a single map the common element in arr1 and arr2 are treated as a single element for finding frequency, so there would be no duplicates.

Why not unordered_map?
In unordered_map the keys are stored in random order, while in the map the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a map is preferable.

We can also use unordered_map, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.

Code
C++
Java
Python
JavaScript
Copy

#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}


Output:

Union of arr1 and arr2 is 

1 2 3 4 5 6 7 8 9 10 11 12.

Complexity Analysis
Time Compleixty : O( (m+n)log(m+n) ) . Inserting a key in map takes logN times, where N is no of elements in map. At max map can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across insertion of all elements in worst it would take O((m+n)log(m+n) time.

Using HashMap also takes the same time, On average insertion in unordered_map takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}



Solution 2:
Algorithm / Intuition
Solution 2: Using Set
Suppose we consider arr1 and arr2 as a single array say arr,  then the union of arr1 and arr2 is the distinct elements in arr.

Example:
arr1[] = {1,2,3,4,5,6,7,8,9,10}
arr2[] = {2,3,4,4,5,11,12} 
arr = arr1 + arr2 = {1,2,3,4,5,67,8,9,
                     10,2,3,4,4,5,11,12}

Distinct element in 
arr = {1,2,3,4,5,6,7,8,9,10,11,12} 
    = Union of arr1 ,arr2.
So using a set we can find the distinct elements because the set does not hold any duplicates. Hence we can find the union of arr1 and arr2.

Why not unordered_set?
In unordered_set the elements are stored in random order, while in a set the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a set is preferable.

We can also use unordered_set, but after finding the union of arr1 and arr2, we need to sort the union vector to get the elements of the union in sorted order.

Code
C++
Java
Python
JavaScript
Copy

#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto & it: s)
    Union.push_back(it);
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}

Output:

Union of arr1 and arr2 is 

1 2 3 4 5 6 7 8 9 10 11 12. 

Complexity Analysis
Time Compleixty : O( (m+n)log(m+n) ) . Inserting an element in a set takes logN time, where N is no of elements in the set. At max set can store m+n elements {when there are no common elements and elements in arr,arr2 are distntict}. So Inserting m+n th element takes log(m+n) time. Upon approximation across inserting all elements in worst, it would take O((m+n)log(m+n) time.

Using HashSet also takes the same time, On average insertion in unordered_set takes O(1) time but sorting the union vector takes O((m+n)log(m+n))  time. Because at max union vector can have m+n elements.

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}

Solution 3:
Algorithm / Intuition
Solution 3: Two Pointers
Solution 1 and 2 work for the unsorted arrays also, The arrays arr1 and arr2 are sorted, can we use this property to reduce the time Complexity?

Using the property that the arrays are sorted we can bring down the time complexity from

O((m+n)log(m+n))    TO    O(m+n).
Approach:
Take two pointers let’s say i,j pointing to the 0th index of arr1 and arr2.
Create an empty vector for storing the union of arr1 and arr2.
From solution 2 we know that the union is nothing but the distinct elements in arr1 + arr2 
Let’s traverse the arr1 and arr2 using pointers i and j and insert the distinct elements found into the union vector.
While traversing we may encounter three cases.

arr1[ i ] == arr2[ j ] 
Here we found a common element, so insert only one element in the union. Let’s insert arr[i] in union and increment i.

NOTE: There may be cases like the element to be inserted is already present in the union, in that case, we are inserting duplicates which is not desired. So while inserting always check whether the last element in the union vector is equal or not to the element to be inserted. If equal we are trying to insert duplicates, so don’t insert the element, else insert the element in the union. This makes sure that we are not inserting any duplicates in the union because we are inserting elements in sorted order.
arr1[ i ]  < arr2[ j ]
arr1[ i ] < arr2[ j ] so we need to insert arr1[ i ] in union.IF last element in  union vector is not equal to arr1[ i ],then insert in union else don’t insert. After checking Increment i.
arr1[ i ] > arr2[ j ]
arr1[ i ] > arr2[ j ] so we need to insert arr2[ j ] in union. IF the last element in the union vector is not equal to arr2[ j ], then insert in the union, else don’t insert. After checking Increment j. After traversing if any elements are left in arr1 or arr2 check for condition and insert in the union.
Code
C++
Java
Python
JavaScript
Copy



#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}

Output:

Union of arr1 and arr2 is 

1 2 3 4 5 6 7 8 9 10 11 12. 

Complexity Analysis
Time Complexity: O(m+n), Because at max i runs for n times and j runs for m times. When there are no common elements in arr1 and arr2 and all elements in arr1, arr2 are distinct. 

Space Complexity : O(m+n) {If Space of Union ArrayList is considered} 

O(1) {If Space of union ArrayList is not considered}



**FINDING INTERSECTION IN AN ARRAY**

Let's break down the function `intersection` that finds the intersection of two arrays `nums1` and `nums2`, meaning it returns the common elements present in both arrays without duplicates.

### Code Explanation

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end()); // Convert nums1 to a set
        set<int> set2(nums2.begin(), nums2.end()); // Convert nums2 to a set
        vector<int> result; // Vector to store the result

        for (const auto& num : set2) { // Iterate through the second set
            if (set1.count(num)) { // Check if num exists in the first set
                result.push_back(num); // If so, add it to the result
            }
        }
        return result; // Return the result vector
    }
};
```

### Detailed Explanation of Each Line

1. **`class Solution {`**
   - Declares a class named `Solution`.

2. **`public:`**
   - Specifies the public access specifier for the class, allowing access to the member functions.

3. **`vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {`**
   - Defines a public member function `intersection` that takes two vectors, `nums1` and `nums2`, as input and returns a `vector<int>` containing the intersection (common elements) of both arrays.

4. **`set<int> set1(nums1.begin(), nums1.end());`**
   - Converts the vector `nums1` into a set `set1`:
     - **Reason:** Sets automatically remove duplicates and store unique elements. By converting `nums1` into a set, we eliminate any duplicate elements and make lookups faster (average O(1) time complexity).
   - `nums1.begin(), nums1.end()` initializes the set with all elements of `nums1`.

5. **`set<int> set2(nums2.begin(), nums2.end());`**
   - Similarly, this converts `nums2` into a set `set2`:
     - **Reason:** To ensure unique elements from `nums2` and allow for efficient comparison with `set1`.
   - `nums2.begin(), nums2.end()` initializes the set with all elements of `nums2`.

6. **`vector<int> result;`**
   - Initializes an empty vector `result` to store the common elements (the intersection of `nums1` and `nums2`).

7. **`for (const auto& num : set2) {`**
   - Iterates over each element `num` in `set2`:
     - **Reason:** We loop through the second set because we only need to check if elements from `set2` exist in `set1`. This reduces redundant checks since sets only store unique elements.

8. **`if (set1.count(num)) {`**
   - For each element `num` in `set2`, it checks if that element exists in `set1`:
     - `set1.count(num)` checks if `num` is present in `set1`. It returns `1` if `num` is present, otherwise `0`.

9. **`result.push_back(num);`**
   - If the element `num` exists in `set1`, it is added to the `result` vector.

10. **`return result;`**
    - After the loop completes, the function returns the `result` vector, which now contains the common elements between `nums1` and `nums2`.

### Dry Run Example

Let's dry run the code with an example:

```cpp
nums1 = [4, 9, 5]
nums2 = [9, 4, 9, 8, 4]
```

#### **Initial State:**
- `nums1 = [4, 9, 5]`
- `nums2 = [9, 4, 9, 8, 4]`

#### Step-by-Step Execution:

1. **Line: `set<int> set1(nums1.begin(), nums1.end());`**
   - `set1` is created from `nums1`:
   ```cpp
   set1 = {4, 9, 5} // All elements in nums1 are added to set1, duplicates are removed.
   ```

2. **Line: `set<int> set2(nums2.begin(), nums2.end());`**
   - `set2` is created from `nums2`:
   ```cpp
   set2 = {9, 4, 8} // All elements in nums2 are added to set2, duplicates are removed.
   ```

3. **Line: `vector<int> result;`**
   - An empty vector `result` is initialized to store the intersection.

4. **Line: `for (const auto& num : set2) {`**
   - The loop starts iterating through each element in `set2`:
   
   **First Iteration:**
   - `num = 9`
   - **Condition:** `if (set1.count(9))` → `set1.count(9)` is `true` because 9 exists in `set1`.
     - `result.push_back(9);`
     - **State of `result`:**
     ```cpp
     result = [9]
     ```

   **Second Iteration:**
   - `num = 4`
   - **Condition:** `if (set1.count(4))` → `set1.count(4)` is `true` because 4 exists in `set1`.
     - `result.push_back(4);`
     - **State of `result`:**
     ```cpp
     result = [9, 4]
     ```

   **Third Iteration:**
   - `num = 8`
   - **Condition:** `if (set1.count(8))` → `set1.count(8)` is `false` because 8 does not exist in `set1`.
     - No action is taken in this iteration.

5. **Line: `return result;`**
   - The loop finishes, and the final `result` vector is returned:
   ```cpp
   result = [9, 4]
   ```

### Final Output:
The intersection of `nums1` and `nums2` is `[9, 4]`.

### Summary:
- The code efficiently finds the common elements between two arrays by converting them into sets to eliminate duplicates and using efficient lookups.
- The result is stored in a vector and returned, containing the elements present in both arrays without duplicates.
