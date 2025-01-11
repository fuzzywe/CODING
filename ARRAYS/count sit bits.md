Count Set Bits In A Number
Ninja was given an integer ‘N’. For each number from ‘0’ to ‘N’, he must print the number of set bits present in its binary representation

To solve the problem of counting the set bits (1s) in the binary representation of numbers from `0` to `N` and printing the count for each:

---

### **Approach 1: Naive Method (Iterative Bit Counting)**
#### Explanation
- For each number `i` from `0` to `N`, count the set bits using bitwise operations.
- Right-shift the number repeatedly, checking the least significant bit each time.

#### **C++ Code**
```cpp
#include <iostream>
using namespace std;

// Function to count set bits in a number
int countSetBits(int num) {
    int count = 0;
    while (num > 0) {
        count += (num & 1);  // Check the least significant bit
        num >>= 1;           // Right-shift the number
    }
    return count;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    for (int i = 0; i <= N; i++) {
        cout << "Number: " << i << ", Set Bits: " << countSetBits(i) << endl;
    }

    return 0;
}
```

---

### **Approach 2: Dynamic Programming (Using Previously Computed Results)**
#### Explanation
- Leverage the observation:  
  `countSetBits(i) = countSetBits(i >> 1) + (i & 1)`  
- Precompute and store the set bit counts.

#### **C++ Code (Optimal)**
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> countSetBitsUptoN(int N) {
    vector<int> setBitsCount(N + 1, 0);  // Initialize with 0
    for (int i = 1; i <= N; i++) {
        setBitsCount[i] = setBitsCount[i >> 1] + (i & 1);  // Use previously computed value
    }
    return setBitsCount;
}

int main() {
    int N;
    cout << "Enter N: ";
    cin >> N;

    vector<int> result = countSetBitsUptoN(N);
    for (int i = 0; i <= N; i++) {
        cout << "Number: " << i << ", Set Bits: " << result[i] << endl;
    }

    return 0;
}
```

---

### **Explanation**
1. **Naive Method** uses a loop and bitwise operations to count bits for each number.  
   **Time Complexity:** O(N * log N)  
   **Space Complexity:** O(1)

2. **Dynamic Programming Method** precomputes results for better efficiency.  
   **Time Complexity:** O(N)  
   **Space Complexity:** O(N)

This second method is efficient and well-suited for larger values of `N`.
