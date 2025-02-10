You can solve this problem using **binary search** for an efficient approach. Here's the implementation in C++:
https://www.geeksforgeeks.org/problems/square-root/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
https://www.geeksforgeeks.org/square-root-of-an-integer/?utm_source=chatgpt.com
https://leetcode.com/problems/sqrtx/description/?utm_source=chatgpt.com
https://leetcode.com/problems/sqrtx/description/

### **C++ Solution:**
```cpp
#include <iostream>
using namespace std;

int integerSquareRoot(int N) {
    if (N == 0 || N == 1) return N; // Base cases
    
    int low = 1, high = N, ans = 0;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long midSq = mid * mid;
        
        if (midSq == N)
            return mid;  // Perfect square case
        else if (midSq < N) {
            ans = mid;   // Store possible floor value
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return ans;
}

int main() {
    int N1 = 25, N2 = 20, N3 = 2;
    cout << integerSquareRoot(N1) << endl;
    cout << integerSquareRoot(N2) << endl;
    cout << integerSquareRoot(N3) << endl;
    return 0;
}
```

### **Explanation:**
1. **Binary Search Approach**  
   - Start with `low = 1` and `high = N`.
   - Check `mid = (low + high) / 2` and compute `mid^2`.
   - If `mid^2 == N`, return `mid` (perfect square case).
   - If `mid^2 < N`, move `low` to `mid + 1` and store `mid` as a possible answer.
   - Otherwise, move `high` to `mid - 1`.
   - Continue this until `low` exceeds `high`.
   
2. **Time Complexity:**  
   - **O(log N)** due to binary search.

3. **Test Cases:**
   ```
   Input:
   N = 25
   Output: 5

   Input:
   N = 20
   Output: 4

   Input:
   N = 2
   Output: 1
   ```

Would you like a Python solution as well? 🚀
