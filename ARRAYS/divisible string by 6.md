Given a number represented in binary as a string( length <=100). Return 1 if divisible by 6 else return 0.

For question 1, if the last bit is 0, the number is divisible by 2, if the number of non-zero bits in even positions – number of bits in odd positions is a multiple of 3, the number is a multiple of 3.


```cpp

#include <iostream>
#include <string>
using namespace std;

// Function to check if binary string is divisible by 6
int isDivisibleBy6(string binary) {
    int n = binary.length();

    // Step 1: Check divisibility by 2
    if (binary[n - 1] != '0') {
        // If the last bit is not '0', it's not divisible by 2
        return 0; // Not divisible by 6
    }

    // Step 2: Check divisibility by 3
    int odd_count = 0, even_count = 0;
    for (int i = 0; i < n; i++) {
        if (binary[i] == '1') {
            if ((i + 1) % 2 == 0) { 
                // Increment count for even positions (1-based index)
                even_count++;
            } else {
                // Increment count for odd positions (1-based index)
                odd_count++;
            }
        }
    }

    // Step 3: Check if the difference of counts is divisible by 3
    if ((odd_count - even_count) % 3 == 0) {
        return 1; // Divisible by 6
    }

    return 0; // Not divisible by 6
}

// Test cases to validate the function
void runTestCases() {
    // Test cases
    string testCases[] = {"110", "1001", "1100", "111000", "101010"};
    int expectedResults[] = {1, 0, 1, 1, 0}; // Expected results for each case

    // Dry run for test case 1 ("110")
    string binary = "110"; 
    cout << "Dry run for binary string: " << binary << endl;

    // Divisibility by 2
    if (binary[binary.length() - 1] == '0') {
        cout << "Step 1: Last bit is 0 -> Divisible by 2" << endl;
    } else {
        cout << "Step 1: Last bit is not 0 -> Not divisible by 2" << endl;
    }

    // Counting 1s in odd and even positions
    int odd_count = 0, even_count = 0;
    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '1') {
            if ((i + 1) % 2 == 0) {
                even_count++;
                cout << "1 found at even position " << i + 1 << endl;
            } else {
                odd_count++;
                cout << "1 found at odd position " << i + 1 << endl;
            }
        }
    }

    // Print counts
    cout << "Odd count: " << odd_count << ", Even count: " << even_count << endl;

    // Divisibility by 3
    if ((odd_count - even_count) % 3 == 0) {
        cout << "Step 2: Difference is divisible by 3 -> Divisible by 6" << endl;
    } else {
        cout << "Step 2: Difference is not divisible by 3 -> Not divisible by 6" << endl;
    }

    cout << "Result for " << binary << ": " << (isDivisibleBy6(binary) ? "Divisible by 6" : "Not divisible by 6") << endl;

    // Running additional test cases
    for (int i = 0; i < 5; i++) {
        int result = isDivisibleBy6(testCases[i]);
        cout << "Test case " << i + 1 << ": " << testCases[i] 
             << " -> " << (result == expectedResults[i] ? "Passed" : "Failed") << endl;
    }
}

int main() {
    runTestCases();
    return 0;
}


```

It must be divisible by 2 (binary numbers ending in 0).
It must be divisible by 3 (based on the alternating sum of 1s in odd and even positions).
Function: isDivisibleBy6
Step 1: Check Divisibility by 2
cpp
Copy code
if (binary[n - 1] != '0') {
    return 0; // Not divisible by 2, hence not divisible by 6
}
Explanation:
The divisibility rule for 2 in binary is simple: the last bit must be 0.
If the last bit is 1, the number is odd and cannot be divisible by 6.
Step 2: Calculate Odd and Even Counts
cpp
Copy code
int odd_count = 0, even_count = 0;
for (int i = 0; i < n; i++) {
    if (binary[i] == '1') {
        if ((i + 1) % 2 == 0) { // Even position (1-based)
            even_count++;
        } else { // Odd position (1-based)
            odd_count++;
        }
    }
}
Explanation:
The loop iterates through all characters in the binary string.
If the character is 1, it checks whether its position (1-based index) is odd or even:
(i + 1) % 2 == 0 → Even position.
Otherwise, it's an odd position.
The odd_count and even_count variables track the number of 1s in odd and even positions, respectively.
Step 3: Check Divisibility by 3
cpp
Copy code
if ((odd_count - even_count) % 3 == 0) {
    return 1; // Divisible by 6
}
Explanation:
The rule for divisibility by 3 in binary:
Compute the difference: odd_count - even_count.
If the result is divisible by 3 (% 3 == 0), the number is divisible by 3.
If both conditions (divisibility by 2 and divisibility by 3) are satisfied, the function returns 1.
Step 4: Return the Result
cpp
Copy code
return 0; // Not divisible by 6
If the binary string fails any of the checks, the function returns 0.
Test Case Execution: runTestCases
Test Cases
cpp
Copy code
string testCases[] = {"110", "1001", "1100", "111000", "101010"};
int expectedResults[] = {1, 0, 1, 1, 0};
Each test case checks a binary string against the function isDivisibleBy6. The expected results are pre-defined.
Execution Loop
cpp
Copy code
for (int i = 0; i < 5; i++) {
    int result = isDivisibleBy6(testCases[i]);
    cout << "Test case " << i + 1 << ": " << testCases[i] 
         << " -> " << (result == expectedResults[i] ? "Passed" : "Failed") << endl;
}
The loop:
Calls isDivisibleBy6 for each binary string.
Compares the result to the expected output.
Prints whether the test case passed or failed.
Example Execution
Test Case 1: "110"
Divisibility by 2: Last bit = 0 → Divisible by 2.
Odd and Even Counts:
Positions: 1 1 0 (1-based indices).
Odd count: 2 (1s at positions 1 and 3).
Even count: 0.
Difference: odd_count - even_count = 2 - 0 = 2.
Divisibility by 3: 2 % 3 != 0 → Not divisible by 3.
Result: 1 (Divisible by 6).
Test Case 2: "1001"
Divisibility by 2: Last bit = 1 → Not divisible by 2.
Result: 0 (Not divisible by 6).
Test Case 3: "1100"
Divisibility by 2: Last bit = 0 → Divisible by 2.
Odd and Even Counts:
Positions: 1 1 0 0 (1-based indices).
Odd count: 1 (1 at position 1).
Even count: 1 (1 at position 2).
Difference: odd_count - even_count = 1 - 1 = 0.
Divisibility by 3: 0 % 3 == 0 → Divisible by 3.
Result: 1 (Divisible by 6).
Test Case 4: "111000"
Divisibility by 2: Last bit = 0 → Divisible by 2.
Odd and Even Counts:
Positions: 1 1 1 0 0 0 (1-based indices).
Odd count: 2 (1s at positions 1 and 3).
Even count: 1 (1 at position 2).
Difference: odd_count - even_count = 2 - 1 = 1.
Divisibility by 3: 1 % 3 != 0 → Not divisible by 3.
Result: 0 (Not divisible by 6).
