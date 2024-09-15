Input:  A = "ABD", B = "BAD"
Output: 1
Explanation: Pick B and insert it at front.
Input:  A = "EACBD", B = "EABCD"
Output: 3
Explanation: Pick B and insert at front, EACBD => BEACD
             Pick A and insert at front, BEACD => ABECD
             Pick E and insert at front, ABECD => EABCD

#include <bits/stdc++.h>
using namespace std;

int transform(string A, string B)
{
	if (A.length() != B.length()) {
		return -1;
	}

	// create a map to store the frequency of characters in string A
	unordered_map<char, int> m;
	int n = A.length();
	for (int i = 0; i < n; i++) {
		if (m.count(A[i])) // if the character already exists in the map
			m[A[i]]++;	 // increment its frequency
		else
			m[A[i]] = 1; // add the character to the map with a frequency of 1
	}

	// subtract the frequency of characters in string B from the map
	for (int i = 0; i < n; i++) {
		if (m.count(B[i]))
			m[B[i]]--;
	}

	// check if all the frequencies in the map are 0, indicating equal frequency of characters in both strings
	for (auto it : m) {
		if (it.second != 0) // if frequency is not zero
			return -1;	 // strings cannot be transformed into each other, return -1
	}

	// calculate the minimum number of operations required to transform string A into string B
	int i = n - 1, j = n - 1;
	int res = 0;
	while (i >= 0 && j >= 0) {
		while (i >= 0 && A[i] != B[j]) {
			res++; // increment the number of operations required
			i--;	 // move the pointer i to the left
		}
		i--;
		j--;
	}
return res; // returning result
}

// Driver code
int main()
{
	string A = "EACBD";
	string B = "EABCD";

	cout << "Minimum number of operations required is " << transform(A, B) << endl;
	return 0;
}
Time Complexity: O(N)
Auxiliary Space: O(N), since we are using a HashMap.

Step 1: Frequency Map Creation for A
After processing string A = "EACBD", the map looks like this:

arduino
Copy code
{
    'E': 1,
    'A': 1,
    'C': 1,
    'B': 1,
    'D': 1
}
Step 2: Subtract Frequencies Using B
After processing string B = "EABCD", the map becomes:

arduino
Copy code
{
    'E': 0,
    'A': 0,
    'C': 0,
    'B': 0,
    'D': 0
}
Since all values are 0, it means A and B have the same characters in equal frequencies, so transformation is possible.

Step 3: Minimum Operations to Transform A to B
Now, we calculate how many moves are needed:

Starting at the end, A[4] = D and B[4] = D (they match, so move i and j to the left).
Now, A[3] = B and B[3] = C (they don't match, so we need to move B in A earlier, increment res to 1 and move i left).
Now, A[2] = C and B[3] = C (they match, move i and j left).
Now, A[1] = A and B[2] = B (they don't match, increment res to 2 and move i left).
Now, A[0] = E and B[0] = E (they match).
Therefore, res = 2, meaning 2 operations are needed to transform A into B.

output: 2


// C++ program to find minimum number of operations required
// to transform one string to other
#include <bits/stdc++.h>
using namespace std;
 
// Function to find minimum number of operations required to
// transform A to B.
int minOps(string& A, string& B)
{
    int m = A.length(), n = B.length();
 
    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    // count characters in A
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    // subtract count for every character in B
    for (int i = 0; i < n; i++)
        count[B[i]]--;
    // Check if all counts become 0
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;
 
    // This part calculates the number of operations
    // required
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;) {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j]) {
            i--;
            res++;
        }
        // If A[i] and B[j] match
        if (i >= 0) {
            i--;
            j--;
        }
    }
    return res;
}
 
// Driver program
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations required is " << minOps(A, B);
    return 0;
}
 
// This code is contributed by Aditya Kumar (adityakumar129)
Output: 

Minimum number of operations required is 3
Time Complexity: O(n), please note that i is always decremented (in while loop and in if), and the for loop starts from n-1 and runs while i >= 0.

Auxiliary Space: O(1).
