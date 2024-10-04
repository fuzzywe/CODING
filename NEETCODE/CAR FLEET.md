There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]

Output: 3

Explanation:

The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12. The fleet forms at target.
The car starting at 0 (speed 1) does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Example 2:

Input: target = 10, position = [3], speed = [3]

Output: 1

Explanation:

There is only one car, hence there is only one fleet.
Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]

Output: 1

Explanation:

The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The car starting at 4 (speed 1) travels to 5.
Then, the fleet at 4 (speed 2) and the car at position 5 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.


class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
       vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
       sort(cars.begin(), cars.end());
     stack<double> stack;

        for (int i = n - 1; i >= 0; --i){
            // If the current car's time is greater than the time of the last fleet on the stack,
            // it means this car will form a new fleet.
            if (stack.empty() || cars[i].second > stack.top()) {
                stack.push(cars[i].second);
            }
        }
        
        // The size of the stack is the number of fleets
        return stack.size();
    }
};

Complexity
Time complexity:o(nlogn)
Space complexity:o(n)
Sure! Let's delve into the **Car Fleet** problem by breaking down the provided C++ code line by line, using a detailed example to illustrate each step. This will help you understand how the code works and how it determines the number of car fleets that will arrive at the destination.

---

## **Problem Overview: Car Fleet**

**Objective:**
Given a target destination and multiple cars with their starting positions and speeds, determine how many fleets of cars will arrive at the target.

**Definitions:**
- **Fleet:** A group of cars traveling at the same speed. A fleet is formed when one or more cars catch up to the slower car in front.
- **Target:** The position where all cars are trying to reach.

**Example:**

- **Target:** `12`
- **Positions:** `[10, 8, 0, 5, 3]` (Each number represents the starting position of a car)
- **Speeds:** `[2, 4, 1, 1, 3]` (Each number represents the speed of the corresponding car)

**Goal:** Determine how many fleets will reach the target.

---

## **Code Explanation**

Here's the provided C++ code for the Car Fleet problem:

```cpp
class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        sort(cars.begin(), cars.end());
        std::stack<double> stack;

        for (int i = n - 1; i >= 0; --i){
            // If the current car's time is greater than the time of the last fleet on the stack,
            // it means this car will form a new fleet.
            if (stack.empty() || cars[i].second > stack.top()) {
                stack.push(cars[i].second);
            }
        }

        // The size of the stack is the number of fleets
        return stack.size();
    }
};
```

### **Detailed Line-by-Line Explanation**

Let's go through the code step by step, using the example:

- **Target:** `12`
- **Positions:** `[10, 8, 0, 5, 3]`
- **Speeds:** `[2, 4, 1, 1, 3]`

#### **1. Function Signature**

```cpp
int carFleet(int target, std::vector<int>& position, std::vector<int>& speed)
```

- **Purpose:** Defines a function `carFleet` that takes:
  - `target`: An integer representing the destination.
  - `position`: A vector of integers representing the starting positions of the cars.
  - `speed`: A vector of integers representing the speeds of the cars.
- **Returns:** An integer indicating the number of car fleets that will arrive at the target.

#### **2. Initialize Variables**

```cpp
int n = position.size();
std::vector<std::pair<int, double>> cars(n);
```

- **Explanation:**
  - `n`: Stores the number of cars, determined by the size of the `position` vector.
  - `cars`: A vector of pairs where each pair contains:
    - The starting position of a car (`int`).
    - The time it takes for that car to reach the target (`double`).

- **Example with our data:**
  - `n = 5`
  - `cars` is initialized as a vector of 5 pairs: `[(0, 0.0), (0, 0.0), (0, 0.0), (0, 0.0), (0, 0.0)]`

#### **3. Populate the `cars` Vector**

```cpp
for (int i = 0; i < n; ++i) {
    cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
}
```

- **Explanation:**
  - Loop through each car and calculate the time it takes to reach the target.
  - **Time Calculation:** `(target - position[i]) / speed[i]`
    - `target - position[i]`: Distance remaining to the target.
    - `/ speed[i]`: Time = Distance / Speed.

- **Populating `cars` with our example:**
  
  | Car Index (`i`) | Position (`position[i]`) | Speed (`speed[i]`) | Time to Target (`(12 - position[i]) / speed[i]`) |
  |-----------------|--------------------------|--------------------|----------------------------------------------------|
  | 0               | 10                       | 2                  | `(12 - 10) / 2 = 1.0`                              |
  | 1               | 8                        | 4                  | `(12 - 8) / 4 = 1.0`                               |
  | 2               | 0                        | 1                  | `(12 - 0) / 1 = 12.0`                              |
  | 3               | 5                        | 1                  | `(12 - 5) / 1 = 7.0`                               |
  | 4               | 3                        | 3                  | `(12 - 3) / 3 = 3.0`                               |

  - **Updated `cars` vector:**
    ```
    [
      (10, 1.0),
      (8, 1.0),
      (0, 12.0),
      (5, 7.0),
      (3, 3.0)
    ]
    ```

#### **4. Sort the `cars` Vector by Position**

```cpp
sort(cars.begin(), cars.end());
```

- **Explanation:**
  - Sorts the `cars` vector based on the starting positions in ascending order.
  - Sorting ensures that we process cars starting from the furthest to the closest relative to the target.

- **Sorted `cars` vector:**

  Before sorting:
  ```
  [
    (10, 1.0),
    (8, 1.0),
    (0, 12.0),
    (5, 7.0),
    (3, 3.0)
  ]
  ```

  After sorting by position (ascending):
  ```
  [
    (0, 12.0),
    (3, 3.0),
    (5, 7.0),
    (8, 1.0),
    (10, 1.0)
  ]
  ```

#### **5. Initialize a Stack to Track Fleets**

```cpp
std::stack<double> stack;
```

- **Explanation:**
  - A stack is used to keep track of the time it takes for each fleet to reach the target.
  - The stack will store the times of fleets in decreasing order of their positions (from furthest to closest to the target).

#### **6. Iterate Through the Sorted `cars` Vector in Reverse**

```cpp
for (int i = n - 1; i >= 0; --i){
    // If the current car's time is greater than the time of the last fleet on the stack,
    // it means this car will form a new fleet.
    if (stack.empty() || cars[i].second > stack.top()) {
        stack.push(cars[i].second);
    }
}
```

- **Explanation:**
  - Iterate through the `cars` vector from the car closest to the target to the furthest.
  - **Condition:**
    - If the stack is empty, push the current car's time.
    - If the current car's time is greater than the top of the stack (i.e., it takes longer to reach the target than the fleet in front), push it onto the stack as a new fleet.
    - If the current car's time is less than or equal to the top of the stack, it means this car will join the fleet ahead of it and won't form a new fleet.

- **Why Iterate in Reverse?**
  - Processing from the closest car to the target ensures that we only count a new fleet when a car cannot catch up to the fleet in front.

- **Step-by-Step with Example:**

  **Sorted `cars` vector:**
  ```
  [
    (0, 12.0),
    (3, 3.0),
    (5, 7.0),
    (8, 1.0),
    (10, 1.0)
  ]
  ```

  **Iteration Order:** Start from the last element to the first:
  
  - **i = 4** (Car at position 10, time = 1.0)
    - Stack is empty.
    - Push `1.0` onto the stack.
    - **Stack:** `[1.0]`
  
  - **i = 3** (Car at position 8, time = 1.0)
    - Current car's time (`1.0`) is not greater than `stack.top()` (`1.0`).
    - It joins the existing fleet.
    - **Stack:** `[1.0]`
  
  - **i = 2** (Car at position 5, time = 7.0)
    - Current car's time (`7.0`) is greater than `stack.top()` (`1.0`).
    - Push `7.0` onto the stack as a new fleet.
    - **Stack:** `[1.0, 7.0]`
  
  - **i = 1** (Car at position 3, time = 3.0)
    - Current car's time (`3.0`) is not greater than `stack.top()` (`7.0`).
    - It joins the fleet at `7.0`.
    - **Stack:** `[1.0, 7.0]`
  
  - **i = 0** (Car at position 0, time = 12.0)
    - Current car's time (`12.0`) is greater than `stack.top()` (`7.0`).
    - Push `12.0` onto the stack as a new fleet.
    - **Stack:** `[1.0, 7.0, 12.0]`

#### **7. Return the Number of Fleets**

```cpp
return stack.size();
```

- **Explanation:**
  - The number of elements in the stack represents the number of distinct fleets that will reach the target.
  - Each time we pushed a new time onto the stack, it indicated the formation of a new fleet.

- **Final Stack after Iteration:**
  ```
  [1.0, 7.0, 12.0]
  ```
  - **Size:** `3` fleets.

---

## **Complete Dry Run with Example**

Let's perform a complete dry run with the example:

- **Target:** `12`
- **Positions:** `[10, 8, 0, 5, 3]`
- **Speeds:** `[2, 4, 1, 1, 3]`

### **1. Initialize Variables**

```cpp
int n = position.size(); // n = 5
std::vector<std::pair<int, double>> cars(n);
```

- `n = 5`
- `cars` is initialized as `[(0, 0.0), (0, 0.0), (0, 0.0), (0, 0.0), (0, 0.0)]`

### **2. Populate `cars` Vector**

```cpp
for (int i = 0; i < n; ++i) {
    cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
}
```

- **Calculations:**

  | `i` | `position[i]` | `speed[i]` | `(12 - position[i]) / speed[i]` | `cars[i]`       |
  |-----|---------------|------------|----------------------------------|-----------------|
  | 0   | 10            | 2          | `(12 - 10) / 2 = 1.0`             | `(10, 1.0)`     |
  | 1   | 8             | 4          | `(12 - 8) / 4 = 1.0`              | `(8, 1.0)`      |
  | 2   | 0             | 1          | `(12 - 0) / 1 = 12.0`             | `(0, 12.0)`     |
  | 3   | 5             | 1          | `(12 - 5) / 1 = 7.0`              | `(5, 7.0)`      |
  | 4   | 3             | 3          | `(12 - 3) / 3 = 3.0`              | `(3, 3.0)`      |

- **Updated `cars` Vector:**
  ```
  [
    (10, 1.0),
    (8, 1.0),
    (0, 12.0),
    (5, 7.0),
    (3, 3.0)
  ]
  ```

### **3. Sort `cars` Vector by Position**

```cpp
sort(cars.begin(), cars.end());
```

- **Sorted `cars` Vector:**
  ```
  [
    (0, 12.0),
    (3, 3.0),
    (5, 7.0),
    (8, 1.0),
    (10, 1.0)
  ]
  ```

### **4. Initialize Stack**

```cpp
std::stack<double> stack;
```

- **Stack:** Empty

### **5. Iterate Through `cars` in Reverse Order**

Loop from `i = 4` to `i = 0`.

#### **Iteration 1: `i = 4` (Car at position 10, time = 1.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `true`.
- **Action:**
  - Push `1.0` onto the stack.
- **Stack:** `[1.0]`

#### **Iteration 2: `i = 3` (Car at position 8, time = 1.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[3].second (1.0)` is **not** greater than `stack.top() (1.0)`.
- **Action:**
  - Do **not** push onto the stack. It joins the existing fleet.
- **Stack:** `[1.0]`

#### **Iteration 3: `i = 2` (Car at position 5, time = 7.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[2].second (7.0)` is **greater** than `stack.top() (1.0)`.
- **Action:**
  - Push `7.0` onto the stack.
- **Stack:** `[1.0, 7.0]`

#### **Iteration 4: `i = 1` (Car at position 3, time = 3.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[1].second (3.0)` is **not** greater than `stack.top() (7.0)`.
- **Action:**
  - Do **not** push onto the stack. It joins the existing fleet.
- **Stack:** `[1.0, 7.0]`

#### **Iteration 5: `i = 0` (Car at position 0, time = 12.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[0].second (12.0)` is **greater** than `stack.top() (7.0)`.
- **Action:**
  - Push `12.0` onto the stack.
- **Stack:** `[1.0, 7.0, 12.0]`

### **6. Return the Number of Fleets**

```cpp
return stack.size();
```

- **Explanation:** The number of elements in the stack represents the number of distinct fleets that will arrive at the target.
- **Final Stack Size:** `3`

---

## **Summary of the Dry Run**

- **Initial Setup:**
  - **Cars:** `[(10, 1.0), (8, 1.0), (0, 12.0), (5, 7.0), (3, 3.0)]`
  - **Sorted Cars:** `[(0, 12.0), (3, 3.0), (5, 7.0), (8, 1.0), (10, 1.0)]`
  - **Target:** `12`
  
- **Processing:**
  1. **Car at position 10 (time = 1.0):** Forms Fleet 1.
  2. **Car at position 8 (time = 1.0):** Joins Fleet 1.
  3. **Car at position 5 (time = 7.0):** Forms Fleet 2.
  4. **Car at position 3 (time = 3.0):** Joins Fleet 2.
  5. **Car at position 0 (time = 12.0):** Forms Fleet 3.
  
- **Total Fleets:** `3`

### **Final Answer:**

The function returns `3`, indicating that there are **3 car fleets** that will arrive at the target `12`.

---

## **Additional Example**

Let's consider another example for clarity.

### **Example 2:**

- **Target:** `10`
- **Positions:** `[3, 9, 7, 4, 6]`
- **Speeds:** `[3, 3, 1, 2, 1]`

**Goal:** Determine how many fleets will reach the target `10`.

### **Step-by-Step Dry Run:**

#### **1. Initialize Variables**

```cpp
int n = position.size(); // n = 5
std::vector<std::pair<int, double>> cars(n);
```

- `n = 5`
- `cars` is initialized as `[(0, 0.0), (0, 0.0), (0, 0.0), (0, 0.0), (0, 0.0)]`

#### **2. Populate `cars` Vector**

```cpp
for (int i = 0; i < n; ++i) {
    cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
}
```

- **Calculations:**

  | `i` | `position[i]` | `speed[i]` | `(10 - position[i]) / speed[i]` | `cars[i]`       |
  |-----|---------------|------------|----------------------------------|-----------------|
  | 0   | 3             | 3          | `(10 - 3) / 3 ≈ 2.333`            | `(3, 2.333)`    |
  | 1   | 9             | 3          | `(10 - 9) / 3 ≈ 0.333`            | `(9, 0.333)`    |
  | 2   | 7             | 1          | `(10 - 7) / 1 = 3.0`              | `(7, 3.0)`      |
  | 3   | 4             | 2          | `(10 - 4) / 2 = 3.0`              | `(4, 3.0)`      |
  | 4   | 6             | 1          | `(10 - 6) / 1 = 4.0`              | `(6, 4.0)`      |

- **Updated `cars` Vector:**
  ```
  [
    (3, 2.333),
    (9, 0.333),
    (7, 3.0),
    (4, 3.0),
    (6, 4.0)
  ]
  ```

#### **3. Sort `cars` Vector by Position**

```cpp
sort(cars.begin(), cars.end());
```

- **Sorted `cars` Vector:**
  ```
  [
    (3, 2.333),
    (4, 3.0),
    (6, 4.0),
    (7, 3.0),
    (9, 0.333)
  ]
  ```

#### **4. Initialize Stack**

```cpp
std::stack<double> stack;
```

- **Stack:** Empty

#### **5. Iterate Through `cars` in Reverse Order**

Loop from `i = 4` to `i = 0`.

##### **Iteration 1: `i = 4` (Car at position 9, time = 0.333)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `true`.
- **Action:**
  - Push `0.333` onto the stack.
- **Stack:** `[0.333]`

##### **Iteration 2: `i = 3` (Car at position 7, time = 3.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[3].second (3.0)` is **greater** than `stack.top() (0.333)`.
- **Action:**
  - Push `3.0` onto the stack.
- **Stack:** `[0.333, 3.0]`

##### **Iteration 3: `i = 2` (Car at position 6, time = 4.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[2].second (4.0)` is **greater** than `stack.top() (3.0)`.
- **Action:**
  - Push `4.0` onto the stack.
- **Stack:** `[0.333, 3.0, 4.0]`

##### **Iteration 4: `i = 1` (Car at position 4, time = 3.0)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[1].second (3.0)` is **not** greater than `stack.top() (4.0)`.
- **Action:**
  - Do **not** push onto the stack. It joins the existing fleet at `4.0`.
- **Stack:** `[0.333, 3.0, 4.0]`

##### **Iteration 5: `i = 0` (Car at position 3, time = 2.333)**

```cpp
if (stack.empty() || cars[i].second > stack.top()) {
    stack.push(cars[i].second);
}
```

- **Condition:**
  - `stack.empty()` is `false`.
  - `cars[0].second (2.333)` is **not** greater than `stack.top() (4.0)`.
- **Action:**
  - Do **not** push onto the stack. It joins the existing fleet at `4.0`.
- **Stack:** `[0.333, 3.0, 4.0]`

### **6. Return the Number of Fleets**

```cpp
return stack.size();
```

- **Explanation:** The number of elements in the stack represents the number of distinct fleets.
- **Final Stack Size:** `3`

---

## **Summary of the Dry Run**

- **Initial Setup:**
  - **Cars:** `[(3, 2.333), (4, 3.0), (6, 4.0), (7, 3.0), (9, 0.333)]`
  - **Sorted Cars:** `[(3, 2.333), (4, 3.0), (6, 4.0), (7, 3.0), (9, 0.333)]`
  - **Target:** `10`
  
- **Processing:**
  1. **Car at position 9 (time = 0.333):** Forms Fleet 1.
  2. **Car at position 7 (time = 3.0):** Forms Fleet 2.
  3. **Car at position 6 (time = 4.0):** Forms Fleet 3.
  4. **Car at position 4 (time = 3.0):** Joins Fleet 3.
  5. **Car at position 3 (time = 2.333):** Joins Fleet 3.
  
- **Total Fleets:** `3`

### **Final Answer:**

The function returns `3`, indicating that there are **3 car fleets** that will reach the target `10`.

---

## **Key Points to Remember**

1. **Sorting by Position:**
   - Sorting the cars based on their starting positions in ascending order ensures that we process cars from the furthest to the closest relative to the target.
   
2. **Calculating Time to Reach Target:**
   - For each car, calculate the time it takes to reach the target using `(target - position[i]) / speed[i]`.
   
3. **Using a Stack to Track Fleets:**
   - The stack keeps track of the time it takes for each fleet to reach the target.
   - If a car takes more time than the fleet in front of it, it forms a new fleet.
   - If it takes less or equal time, it joins the fleet ahead, meaning they travel together at the speed of the slower car.

4. **Final Fleet Count:**
   - The number of distinct times stored in the stack after processing all cars indicates the number of fleets.

---

## **Visualization**

Let's visualize the example to better understand:

### **Example 1:**

- **Target:** `12`
- **Positions:** `[10, 8, 0, 5, 3]`
- **Speeds:** `[2, 4, 1, 1, 3]`

**Cars Sorted by Position:**
```
[
  (0, 12.0),
  (3, 3.0),
  (5, 7.0),
  (8, 1.0),
  (10, 1.0)
]
```

**Processing:**
1. **Car at 10 (1.0):** Forms Fleet 1.
2. **Car at 8 (1.0):** Joins Fleet 1.
3. **Car at 5 (7.0):** Forms Fleet 2.
4. **Car at 3 (3.0):** Joins Fleet 2.
5. **Car at 0 (12.0):** Forms Fleet 3.

**Fleets:**
- **Fleet 1:** Cars at positions `[8, 10]`
- **Fleet 2:** Cars at positions `[3, 5]`
- **Fleet 3:** Car at position `[0]`

**Total Fleets:** `3`

### **Example 2:**

- **Target:** `10`
- **Positions:** `[3, 9, 7, 4, 6]`
- **Speeds:** `[3, 3, 1, 2, 1]`

**Cars Sorted by Position:**
```
[
  (3, 2.333),
  (4, 3.0),
  (6, 4.0),
  (7, 3.0),
  (9, 0.333)
]
```

**Processing:**
1. **Car at 9 (0.333):** Forms Fleet 1.
2. **Car at 7 (3.0):** Forms Fleet 2.
3. **Car at 6 (4.0):** Forms Fleet 3.
4. **Car at 4 (3.0):** Joins Fleet 3.
5. **Car at 3 (2.333):** Joins Fleet 3.

**Fleets:**
- **Fleet 1:** Car at position `[9]`
- **Fleet 2:** Car at position `[7]`
- **Fleet 3:** Cars at positions `[3, 4, 6]`

**Total Fleets:** `3`

---

## **Conclusion**

This code efficiently determines the number of car fleets that will reach the target using the following steps:

1. **Calculate Time to Reach Target:**
   - For each car, calculate how long it will take to reach the target.

2. **Sort Cars by Position:**
   - Sort the cars based on their starting positions to process them from the furthest to the closest relative to the target.

3. **Use a Stack to Determine Fleets:**
   - Iterate through the sorted cars in reverse.
   - Use a stack to track the time of each fleet.
   - If a car takes longer to reach the target than the fleet in front, it forms a new fleet.
   - Otherwise, it joins the existing fleet.

4. **Return the Number of Fleets:**
   - The size of the stack after processing all cars indicates the number of fleets.

This approach ensures that each car is only considered once, leading to an efficient solution with a time complexity of **O(n log n)** due to the sorting step, where `n` is the number of cars.

---

Feel free to ask if you have any further questions or need more examples!
