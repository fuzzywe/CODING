https://www.geeksforgeeks.org/problems/set-bits0143/1

efficient

```cpp

public:
    int setBits(int n) {
         unsigned char lookup_t[256] = {0}; 
         int i, count = 0;
          for (i = 0; i < 256; i++)
          {
            lookup_t[i] = (i & 1) + lookup_t[i / 2];
          }
          for (i = 1; i <= sizeof(int) && n; i++)
          {
            count += lookup_t[n & 255];
            n >>= 8;
          }
         
          return count;
        // Write Your Code here
    }


```

Time Complexity: O(n), time is required for building up the look_up table.
Auxiliary Space: O(256), look up table is used for storing occurrences of set bits.



```cpp
Time Complexity: O(log n), we need not to iterate n times over the binary bits, instead we just keep doing bitwise and and right shift which makes the complexity logn
Auxiliary Space: O(1), no extra space needed

// Function to count the number of set bits in N
class Solution {
  public:
    int setBits(int n) {
        int count = 0; // initializing count variable to 0
        while (n) {
            n &= (n - 1); // with this operation, we remove the rightmost set bit in N
                          // and increment the count
            count++;      // incrementing the count variable by 1
        }
        return count; // returning the final count of set bits in N
    }
};

// The overall time complexity of this function is O(logN), where N is the input number.


```

---


```cpp

class Solution {
  public:
    int setBits(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);  // Check if the least significant bit is 1
            n >>= 1;           // Right shift the number by 1 bit
        }
        return count;
    }
};


```


