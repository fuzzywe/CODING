Here's the C++ implementation to find the sum of all digits between \( M \) and \( N \) (inclusive):

### C++ Code Implementation
```cpp
#include <iostream>
using namespace std;

// Function to calculate the sum of digits from M to N
int sumOfDigitsInRange(int M, int N) {
    int totalSum = 0;

    // Iterate through each number in the range
    for (int num = M; num <= N; ++num) {
        int current = num;
        
        // Extract and sum the digits of the current number
        while (current > 0) {
            totalSum += current % 10; // Add the last digit
            current /= 10;           // Remove the last digit
        }
    }
    
    return totalSum;
}

// Main function
int main() {
    int M1 = 1, N1 = 10;
    cout << "Sum of digits from " << M1 << " to " << N1 << " is: " 
         << sumOfDigitsInRange(M1, N1) << endl; // Output: 46

    int M2 = 10, N2 = 15;
    cout << "Sum of digits from " << M2 << " to " << N2 << " is: " 
         << sumOfDigitsInRange(M2, N2) << endl; // Output: 21

    return 0;
}
```

### Explanation
1. **Iterate through numbers**: Use a `for` loop from \( M \) to \( N \).
2. **Extract digits**: For each number, repeatedly take the last digit using `% 10` and divide by 10 (`/= 10`) to remove the last digit.
3. **Sum digits**: Accumulate the sum of digits for each number.
4. **Output the result**.

### Example Output
For the inputs \( M = 1, N = 10 \):
```
Sum of digits from 1 to 10 is: 46
```
For the inputs \( M = 10, N = 15 \):
```
Sum of digits from 10 to 15 is: 21
```
