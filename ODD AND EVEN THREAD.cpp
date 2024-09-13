To solve the problem of printing odd and even numbers sequentially using two threads, we will first write a basic brute-force approach. Then, we will modify it slightly to use a global index counter shared between the two threads. Finally, we'll optimize it and analyze the time and space complexity of both approaches.

### **Brute Force Approach:**
In the brute-force approach, we create two threads:
- One thread prints the even numbers.
- Another thread prints the odd numbers.

However, to ensure proper synchronization (i.e., that odd and even numbers are printed in sequence), we'll use a **mutex** and **condition variable**.

### Brute Force Code:

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
bool isOddTurn = true;

void printOdd(int n) {
    for (int i = 1; i <= n; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return isOddTurn; });  // Wait for odd turn
        cout << i << " ";
        isOddTurn = false;  // Switch turn to even
        cv.notify_all();  // Notify other thread
    }
}

void printEven(int n) {
    for (int i = 2; i <= n; i += 2) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return !isOddTurn; });  // Wait for even turn
        cout << i << " ";
        isOddTurn = true;  // Switch turn to odd
        cv.notify_all();  // Notify other thread
    }
}

int main() {
    int n = 10;  // Upper limit to print numbers
    thread t1(printOdd, n);
    thread t2(printEven, n);

    t1.join();
    t2.join();
    return 0;
}
```

### **Explanation:**
- **Thread 1** prints odd numbers.
- **Thread 2** prints even numbers.
- **Mutex (`mtx`)** is used to lock the shared resource (printing).
- **Condition variable (`cv`)** is used to make one thread wait while the other is printing and notify the waiting thread to proceed.
- The boolean flag `isOddTurn` helps in deciding whose turn it is (odd or even).

### **Time Complexity**:
- Each thread prints approximately half the numbers (odd or even).
- For each thread, it takes \( O(n/2) \) operations, where \( n \) is the total number of numbers. Hence the overall time complexity is \( O(n) \).

### **Space Complexity**:
- We are using constant extra space for the mutex, condition variable, and boolean flag. Hence, the space complexity is \( O(1) \).

---

### **Optimized Approach with a Global Counter:**
We can improve the solution by using a global counter shared between both threads, thus eliminating the need for separate logic for odd and even numbers. Both threads will just check the global counter to decide whether to print the number.

### Optimized Code with Global Counter:

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;
condition_variable cv;
int counter = 1;  // Global counter

void printNumbers(int n) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return counter % 2 == 1; });  // Check if odd
        if (counter > n) break;
        cout << counter << " ";
        counter++;  // Increment the global counter
        cv.notify_all();  // Notify other thread
    }
}

void printNumbersEven(int n) {
    while (true) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [] { return counter % 2 == 0; });  // Check if even
        if (counter > n) break;
        cout << counter << " ";
        counter++;  // Increment the global counter
        cv.notify_all();  // Notify other thread
    }
}

int main() {
    int n = 10;  // Upper limit to print numbers
    thread t1(printNumbers, n);  // Thread to print odd
    thread t2(printNumbersEven, n);  // Thread to print even

    t1.join();
    t2.join();
    return 0;
}
```

### **Explanation**:
- **Global counter (`counter`)** is used by both threads to decide which number to print.
- **Thread 1** prints numbers when `counter` is odd.
- **Thread 2** prints numbers when `counter` is even.
- Both threads increment the same counter and notify the other thread once they finish printing their number.

### **Time Complexity**:
- Each thread waits and prints half the numbers. Hence the time complexity remains \( O(n) \) for both approaches.

### **Space Complexity**:
- Constant space is used for the mutex, condition variable, and global counter. Hence the space complexity is still \( O(1) \).

---

### **Mathematics Behind the Code**:

1. **Brute Force Approach**:
   - **Odd thread** prints all odd numbers in the sequence: \( 1, 3, 5, \dots, n \).
   - **Even thread** prints all even numbers: \( 2, 4, 6, \dots, n \).
   - **Mutex and condition variable** ensure mutual exclusion and ordering.

   **Synchronization**:
   - Each thread waits for the correct turn (`isOddTurn`).
   - Every odd or even number takes \( O(1) \) time to print, and switching between threads is handled via condition variables.

2. **Optimized Approach (Global Counter)**:
   - The global counter increments after each print.
   - Instead of checking whether it's odd or even separately, both threads check the global counter's parity.
   - This simplifies logic but introduces an extra check (whether the counter is within bounds and whether it’s odd/even).

In both approaches, **mutex** ensures that only one thread is printing at a time, and **condition variables** handle the coordination of turns.

---

### **Summary**:

- **Brute Force Approach**: Separate logic for odd and even numbers, relies on condition variables for synchronization.
  - **Time Complexity**: \( O(n) \)
  - **Space Complexity**: \( O(1) \)

- **Optimized Global Counter**: Both threads share a global counter and check for odd/even based on the counter's value.
  - **Time Complexity**: \( O(n) \)
  - **Space Complexity**: \( O(1) \)

The **optimized approach** is simpler and more intuitive, but both perform similarly in terms of time and space complexity.
