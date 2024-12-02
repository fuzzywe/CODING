```cpp

class Solution {
public:
    static int findTheWinner(int n, int k) {
        int winner = 1;
        for (int i = 2; i <= n; i++)
            winner = (winner + (k - 1)) % i + 1;
        return winner;
    }
};

```
---
recursive

```cpp
class Solution {
private:
    int solve(int n, int k) {
        if (n == 1) {
            return 0; // Base case: only one person remains
        }
        return (solve(n - 1, k) + k) % n; // Recursive step
    }
    
public:
    int findTheWinner(int n, int k) {
        int val = solve(n, k) + 1; // Adjusting for 1-based indexing
        return val;
    }
};

```

```java

class Solution {
    private int solve(int n, int k) {
        if(n==1)
        {
            return 0;
        }
        return (solve(n-1,k)+k)%n;
        
    }
    public int findTheWinner(int n, int k) 
    {
        int val =solve(n,k)+1;
        return val;
    }
}

```
