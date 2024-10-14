https://www.geeksforgeeks.org/problems/move-all-negative-elements-to-end1813/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

Examples:

Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
Output : [1, 3, 2, 11, 6, -1, -7, -5]
Explanation: By doing operations we separated the integers without changing the order.
Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
Output : [7, 9, 10, 11, -5, -3, -4, -1]
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

```cpp
Time Complexity: O(n) — both the first and second loops traverse the vector, making the overall time complexity linear in the size of a.
Space Complexity: O(n) — due to the extra vector b used to store the negative numbers.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
       vector<int>b;
      int j=0;
      for(int i=0;i<arr.size();i++){
          if(arr[i]<0)b.push_back(arr[i]);
          else arr[j++]=arr[i];
      }
      for(auto &i:b)arr[j++]=i;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends
```
Sure! Let's provide a detailed line-by-line explanation of the code with a dry run using the example input array. We'll go through each line of the code, explain its purpose, and track the values during execution.

### Code:
```cpp
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int> b; 
        int j = 0;  
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0)
                b.push_back(arr[i]);
            else
                arr[j++] = arr[i];
        }
        for (auto &i : b)
            arr[j++] = i;  
    }
};
```

### Dry Run with Input:
```cpp
arr = [12, -7, 5, -3, -8, 6]
```

### Line-by-Line Explanation:

1. **`class Solution {`**
   - Defines a class named `Solution`.

2. **`public:`**
   - Specifies that the following members of the class are accessible from outside the class.

3. **`void segregateElements(vector<int>& arr) {`**
   - Declares a method `segregateElements` that takes a reference to a vector of integers `arr`. This method will rearrange the elements in `arr`.

4. **`vector<int> b;`**
   - Declares an empty vector `b` to store negative numbers encountered in `arr`.
   - **Dry Run:** `b = []`

5. **`int j = 0;`**
   - Initializes an integer `j` to 0. This variable will keep track of where to place positive numbers in the original array.
   - **Dry Run:** `j = 0`

6. **`for (int i = 0; i < arr.size(); i++) {`**
   - Begins a for-loop to iterate through each element in `arr`, using `i` as the index variable.

### Iteration of the First Loop:
#### **Current State of `arr`:** `[12, -7, 5, -3, -8, 6]`

- **Iteration 1 (`i = 0`):**
  - **Line:** `if (arr[i] < 0)`
    - `arr[0] = 12` (not negative)
  - **Line:** `else arr[j++] = arr[i];`
    - Place `12` at `arr[j]` (where `j = 0`).
    - **Dry Run:** `arr = [12, -7, 5, -3, -8, 6]`, `j = 1`

- **Iteration 2 (`i = 1`):**
  - **Line:** `if (arr[i] < 0)`
    - `arr[1] = -7` (negative)
  - **Line:** `b.push_back(arr[i]);`
    - Add `-7` to vector `b`.
    - **Dry Run:** `b = [-7]`

- **Iteration 3 (`i = 2`):**
  - **Line:** `if (arr[i] < 0)`
    - `arr[2] = 5` (not negative)
  - **Line:** `arr[j++] = arr[i];`
    - Place `5` at `arr[j]` (where `j = 1`).
    - **Dry Run:** `arr = [12, 5, 5, -3, -8, 6]`, `j = 2`

- **Iteration 4 (`i = 3`):**
  - **Line:** `if (arr[i] < 0)`
    - `arr[3] = -3` (negative)
  - **Line:** `b.push_back(arr[i]);`
    - Add `-3` to vector `b`.
    - **Dry Run:** `b = [-7, -3]`

- **Iteration 5 (`i = 4`):**
  - **Line:** `if (arr[i] < 0)`
    - `arr[4] = -8` (negative)
  - **Line:** `b.push_back(arr[i]);`
    - Add `-8` to vector `b`.
    - **Dry Run:** `b = [-7, -3, -8]`

- **Iteration 6 (`i = 5`):**
  - **Line:** `if (arr[i] < 0)`
    - `arr[5] = 6` (not negative)
  - **Line:** `arr[j++] = arr[i];`
    - Place `6` at `arr[j]` (where `j = 2`).
    - **Dry Run:** `arr = [12, 5, 6, -3, -8, 6]`, `j = 3`

### End of First Loop:
- The first loop is complete. All positive numbers are at the beginning of `arr`, and negative numbers are stored in vector `b`.
- **Final State after First Loop:**
  - **`arr`:** `[12, 5, 6, -3, -8, 6]`
  - **`b`:** `[-7, -3, -8]`

7. **`for (auto &i : b)`**
   - Begins a second loop to iterate through each element `i` in vector `b`, which contains negative numbers.

### Iteration of the Second Loop:
- **Iteration 1:**
  - **Line:** `arr[j++] = i;`
    - Place `-7` (the first element in `b`) at `arr[j]` (where `j = 3`).
    - **Dry Run:** `arr = [12, 5, 6, -7, -8, 6]`, `j = 4`

- **Iteration 2:**
  - **Line:** `arr[j++] = i;`
    - Place `-3` (the second element in `b`) at `arr[j]` (where `j = 4`).
    - **Dry Run:** `arr = [12, 5, 6, -7, -3, 6]`, `j = 5`

- **Iteration 3:**
  - **Line:** `arr[j++] = i;`
    - Place `-8` (the third element in `b`) at `arr[j]` (where `j = 5`).
    - **Dry Run:** `arr = [12, 5, 6, -7, -3, -8]`, `j = 6`

### End of Second Loop:
- The second loop is complete, and all elements from `b` have been appended to `arr` after the positive elements.

8. **`}`**
   - Closes the `segregateElements` method.

### Final State of `arr`:
- The final rearranged array is `[12, 5, 6, -7, -3, -8]`, with all positive numbers at the beginning followed by all negative numbers.

### Summary:
- The function effectively separates positive and negative numbers while preserving their original order. The positive numbers are directly placed back into the original array, and negative numbers are appended at the end.

- 
```cpp

Time Complexity: O(n)
Space Complexity: O(n)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes here
        vector<int>neg;
      vector<int>pov;
      for(int i=0;i<arr.size();i++){
          if(arr[i]<0) neg.push_back(arr[i]);
          else pov.push_back(arr[i]);
      }
      int k=0;
      for(int i=0;i<pov.size();i++){
          arr[k++]=pov[i];
      }
      for(int i=0;i<neg.size();i++){
          arr[k++]=neg[i];
      }
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        ob.segregateElements(nums);

        for (int x : nums)
            cout << x << " ";
        cout << endl;
    }
}
// } Driver Code Ends
```

