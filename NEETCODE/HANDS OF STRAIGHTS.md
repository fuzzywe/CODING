Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if (hand.size() % groupSize != 0) {
        return false;
    }

    map<int, int> cardCount;
    for (int card : hand) {
        cardCount[card]++;
    }

    for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
        if (it->second > 0) {
            int count = it->second;
            for (int i = 0; i < groupSize; ++i) {
                if (cardCount[it->first + i] < count) {
                    return false;
                }
                cardCount[it->first + i] -= count;
            }
        }
    }

    return true;
    }
};
```

Complexity
Time complexity:O(n)
Space complexity:O(k)

Let's break down the code step by step with explanations and a dry run example.

### Problem:  
We are given a `hand` of cards, and we need to check if we can divide it into groups of `groupSize` consecutive cards. If possible, the function returns `true`; otherwise, it returns `false`.

### Code Breakdown:

```cpp
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
```
- **Explanation**: The function `isNStraightHand` takes two inputs:
  1. `hand`: A vector of integers representing the cards.
  2. `groupSize`: An integer representing the size of each consecutive group.
  
---

```cpp
        if (hand.size() % groupSize != 0) {
        return false;
    }
```
- **Explanation**: First, we check if the total number of cards is divisible by `groupSize`. If not, it's impossible to form the required groups, so we return `false`.
- **Example**: If `hand = [1, 2, 3, 4, 5]` and `groupSize = 3`, `hand.size() % groupSize = 5 % 3 = 2`, so the function returns `false`.

---

```cpp
    map<int, int> cardCount;
    for (int card : hand) {
        cardCount[card]++;
    }
```
- **Explanation**: We use a map `cardCount` to count the frequency of each card in the `hand`.
- **Example**: If `hand = [1, 2, 3, 6, 2, 3, 4, 7, 8]`, after this loop:
  - `cardCount = {1: 1, 2: 2, 3: 2, 4: 1, 6: 1, 7: 1, 8: 1}`.
  
---

```cpp
    for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
```
- **Explanation**: We iterate through each element in the map `cardCount` from the smallest card number to the largest.
- **Example**: The iterator starts with `it = 1` (the smallest key in `cardCount`).

---

```cpp
        if (it->second > 0) {
            int count = it->second;
```
- **Explanation**: If the count of the current card `it->first` is greater than 0, we proceed. The variable `count` stores the number of this card available in `hand`.
- **Example**: For `it = 1`, `it->second = 1`, so `count = 1`.

---

```cpp
            for (int i = 0; i < groupSize; ++i) {
                if (cardCount[it->first + i] < count) {
                    return false;
                }
                cardCount[it->first + i] -= count;
            }
```
- **Explanation**: This loop checks for `groupSize` consecutive cards starting from the current card (`it->first`). For each consecutive card, we check if its count is at least `count`. If not, we return `false`.
- After validating, we reduce the count of each card by `count`.
  
- **Example**: Let's say `groupSize = 3` and `it = 1`:
  - The loop checks for cards `1, 2, 3`.
  - `cardCount[1] = 1`, `cardCount[2] = 2`, `cardCount[3] = 2` (all greater than or equal to `count = 1`).
  - Now, we reduce their counts:
    - `cardCount[1] -= 1`, `cardCount[2] -= 1`, `cardCount[3] -= 1`.
    - Updated `cardCount = {1: 0, 2: 1, 3: 1, 4: 1, 6: 1, 7: 1, 8: 1}`.

---

```cpp
        }
    }
```
- **Explanation**: The outer loop continues to process the next cards in `cardCount` if they have a count greater than 0.

---

```cpp
    return true;
    }
};
```
- **Explanation**: If all cards are successfully divided into groups of consecutive numbers, we return `true`.

---

### Dry Run Example:

**Input**: `hand = [1, 2, 3, 6, 2, 3, 4, 7, 8]`, `groupSize = 3`.

#### Step 1: Check if divisible
- `hand.size() = 9`, `groupSize = 3`.
- `9 % 3 == 0`, so continue.

#### Step 2: Count cards
- `cardCount = {1: 1, 2: 2, 3: 2, 4: 1, 6: 1, 7: 1, 8: 1}`.

#### Step 3: Process cards in sorted order
- Start with `it = 1`.
  - Group of `1, 2, 3` is valid:
    - Reduce `cardCount[1] -= 1`, `cardCount[2] -= 1`, `cardCount[3] -= 1`.
    - Updated `cardCount = {1: 0, 2: 1, 3: 1, 4: 1, 6: 1, 7: 1, 8: 1}`.
  
- Next, `it = 2`.
  - Group of `2, 3, 4` is valid:
    - Reduce `cardCount[2] -= 1`, `cardCount[3] -= 1`, `cardCount[4] -= 1`.
    - Updated `cardCount = {1: 0, 2: 0, 3: 0, 4: 0, 6: 1, 7: 1, 8: 1}`.

- Next, `it = 6`.
  - Group of `6, 7, 8` is valid:
    - Reduce `cardCount[6] -= 1`, `cardCount[7] -= 1`, `cardCount[8] -= 1`.
    - Updated `cardCount = {1: 0, 2: 0, 3: 0, 4: 0, 6: 0, 7: 0, 8: 0}`.

#### Step 4: Return result
- All cards have been grouped successfully.
- Return `true`.

### Time Complexity:
- Sorting the `cardCount` map takes `O(n log n)`.
- Iterating over the map and adjusting counts is `O(n)`.
- Overall complexity is `O(n log n)`.

### Space Complexity:
- The map `cardCount` uses `O(n)` space.


