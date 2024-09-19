Array Subset
Example 1:

Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 2:

Input:
a1[] = {1, 2, 3, 4, 4, 5, 6}
a2[] = {1, 2, 4}
Output:
Yes
Explanation:
a2[] is a subset of a1[]

Example 3:

Input:
a1[] = {10, 5, 2, 23, 19}
a2[] = {19, 5, 3}
Output:
No
Explanation:
a2[] is not a subset of a1[]

// Function to check if a2 is a subset of a1
string isSubset(int a1[], int a2[], int n, int m) {
    
    // Create a unordered map to store the frequency of elements in a1
    unordered_map<int, int> um, um2;

    // Count the frequency of elements in a1
    for (int i = 0; i < n; i++) {
        um[a1[i]]++;
    }
    
    // Count the frequency of elements in a2
    for (int i = 0; i < m; i++) {
        um2[a2[i]]++;
    }

    int count = 0;
    
    // Iterate through the elements in a2
    for (auto it = um2.begin(); it != um2.end(); it++) {
        // If the frequency in a1 is greater than or equal to the frequency in a2,
        // increment the count
        if (um[it->first] >= it->second) {
            count+=it->second;
        }
    }
    
    // If the count is equal to the size of a2, a2 is a subset of a1
    if (count == m)
        return "Yes";
    // Otherwise, a2 is not a subset of a1
    else
        return "No";
}
Complexity
Time Complexity: O(n + m) for counting frequencies in a1 and a2 and O(m) for comparing frequencies.
Space Complexity: O(n + m) for storing frequencies of elements in um and um2.
  a1 = {1, 2, 3, 4, 5, 6}
a2 = {2, 4, 6}
n = 6
m = 3
Objective:
Check if a2[] is a subset of a1[].

Dry Run (Step-by-Step Execution):
Initial State:
Array a1 = {1, 2, 3, 4, 5, 6}
Array a2 = {2, 4, 6}
Size of a1 (n = 6)
Size of a2 (m = 3)
Step 1: Create two unordered maps um and um2 to store the frequency of elements in a1 and a2.

Loop to count frequency in a1 (um):

um[1] = 1
um[2] = 1
um[3] = 1
um[4] = 1
um[5] = 1
um[6] = 1
After this loop, um contains:

yaml
Copy code
um = {1: 1, 2: 1, 3: 1, 4: 1, 5: 1, 6: 1}
Loop to count frequency in a2 (um2):

um2[2] = 1
um2[4] = 1
um2[6] = 1
After this loop, um2 contains:

yaml
Copy code
um2 = {2: 1, 4: 1, 6: 1}
Step 2: Initialize count = 0.

Step 3: Iterate through the elements in a2[] (i.e., um2) and compare their frequencies with a1[] (i.e., um).

Iteration 1 (it = um2[2] = 1):
Check if um[2] >= um2[2]:
um[2] = 1 and um2[2] = 1, so this condition is true.
Increment count by um2[2]: count += 1, making count = 1.
Iteration 2 (it = um2[4] = 1):
Check if um[4] >= um2[4]:
um[4] = 1 and um2[4] = 1, so this condition is true.
Increment count by um2[4]: count += 1, making count = 2.
Iteration 3 (it = um2[6] = 1):
Check if um[6] >= um2[6]:
um[6] = 1 and um2[6] = 1, so this condition is true.
Increment count by um2[6]: count += 1, making count = 3.
Step 4: After iterating through all elements of a2, count = 3.

Step 5: Compare count with m:

Since count == m (i.e., 3 == 3), return "Yes", indicating that a2[] is a subset of a1[].
Final Output:
For this input, the function will return "Yes" because a2 = {2, 4, 6} is a subset of a1 = {1, 2, 3, 4, 5, 6}.

Key Points:
The code uses two unordered maps (um for a1 and um2 for a2) to count the frequency of elements.
It iterates through a2[] and checks if each element's frequency in a1[] is greater than or equal to that in a2[].
If the total count matches the size of a2[], it confirms that a2[] is a subset of a1[].



  best solutin:
string isSubset(int a1[], int a2[], int n, int m) {
    std::sort(a1,a1+n);
    std::sort(a2,a2+m);

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a1[i] < a2[j]) {
            ++i;
        } else if (a1[i] == a2[j]) {
            ++i;
            ++j;
        } else {
            return "No";
        }
    }

    return (j == m) ? "Yes" : "No";
}
Complexity
Time Complexity: O(n log n + m log m) due to the sorting operations.
Space Complexity: O(1) - no extra space used apart from the input arrays and a few variables.

a1 = {1, 5, 2, 3, 7, 9}
a2 = {3, 7, 9}
n = 6
m = 3
Objective:
Check if a2[] is a subset of a1[].

Dry Run (Step-by-Step Execution):
Initial State:
a1[] = {1, 5, 2, 3, 7, 9}
a2[] = {3, 7, 9}
Size of a1 (n = 6)
Size of a2 (m = 3)
Step 1: Sort both arrays a1[] and a2[].

Sorted a1[] becomes: {1, 2, 3, 5, 7, 9}
Sorted a2[] becomes: {3, 7, 9}
Step 2: Initialize two pointers i = 0 and j = 0.
Step 3: Start the while loop that continues until either i < n or j < m.

Iteration 1:
Compare a1[i] and a2[j]: a1[0] = 1 and a2[0] = 3
Since a1[0] < a2[0], increment i to 1.
Iteration 2:
Compare a1[i] and a2[j]: a1[1] = 2 and a2[0] = 3
Since a1[1] < a2[0], increment i to 2.
Iteration 3:
Compare a1[i] and a2[j]: a1[2] = 3 and a2[0] = 3
Since a1[2] == a2[0], increment both i to 3 and j to 1.
Iteration 4:
Compare a1[i] and a2[j]: a1[3] = 5 and a2[1] = 7
Since a1[3] < a2[1], increment i to 4.
Iteration 5:
Compare a1[i] and a2[j]: a1[4] = 7 and a2[1] = 7
Since a1[4] == a2[1], increment both i to 5 and j to 2.
Iteration 6:
Compare a1[i] and a2[j]: a1[5] = 9 and a2[2] = 9
Since a1[5] == a2[2], increment both i to 6 and j to 3.
Step 4: Exit the while loop because j == m (i.e., j == 3), indicating that all elements of a2[] have been matched.

Step 5: Return "Yes" because j == m.

Final Output:
For this input, the function will return "Yes" because a2 = {3, 7, 9} is a subset of a1 = {1, 2, 3, 5, 7, 9}.

Key Points:
Both arrays are sorted first.
Two pointers i and j traverse a1[] and a2[], respectively, comparing elements.
If all elements of a2[] are found in a1[] in sorted order, it returns "Yes". If at any point an element of a2[] is not found, it returns "No".
