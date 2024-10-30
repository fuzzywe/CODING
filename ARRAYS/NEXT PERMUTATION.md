31. Next Permutation

https://leetcode.com/problems/next-permutation/


https://www.naukri.com/code360/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 1-43 screenshot](https://github.com/user-attachments/assets/3a98b57e-2c68-4f98-92b5-42a2136cc034)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 3-23 screenshot](https://github.com/user-attachments/assets/85c2d1b4-76e6-49d8-8884-64f28df37329)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 3-24 screenshot](https://github.com/user-attachments/assets/5bdd0622-4e5b-49f1-837f-cd56d88018fb)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 2-18 screenshot](https://github.com/user-attachments/assets/d7fbd572-b24e-4ab3-bb76-affc272e40f0)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 1-43 screenshot](https://github.com/user-attachments/assets/1a06ce05-e469-4ce9-8af3-a4bad0360a66)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 4-49 screenshot (1)](https://github.com/user-attachments/assets/010f3ad3-970d-425e-9c8f-50f54dff8845)


A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

**BRUTE FORCE **

```cpp

#include <algorithm> // For std::next_permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        std::next_permutation(nums.begin(), nums.end());
    }
};


```

```cpp

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}



```

---

To understand why we need to find the **breaking point** and sometimes **reverse the array** in finding the next lexicographical permutation, let’s compare the process with the mathematics behind permutations.

### Permutation Basics
In a set of all permutations of elements, each permutation has a **lexicographical order**. This order moves from the smallest (ascending) arrangement to the largest (descending) arrangement. For example, the permutations of `{1, 2, 3}` are ordered as follows:

1. 1 2 3 (smallest)
2. 1 3 2
3. 2 1 3
4. 2 3 1
5. 3 1 2
6. 3 2 1 (largest)

To move to the **next lexicographical permutation**, we need to find a way to minimally increase the current permutation order without skipping any arrangements.

### Why We Find the Breaking Point
The **breaking point** allows us to identify where we can make a small change that increases the current permutation. 

1. Starting from the right, the "breaking point" is the first position where `nums[i] < nums[i + 1]`.
2. By finding this position, we can make the smallest possible change to increase the permutation order. This ensures we are moving to the next permutation rather than skipping any permutations in between.

For instance, in the permutation `1 3 2`, the breaking point is at index `0` (where `1 < 3`). If we swap `1` with the smallest number larger than `1` in the right segment (`2` in this case), we get `2 1 3`, which is the next permutation in lexicographical order.

### Why We Reverse if There’s No Breaking Point
If no breaking point exists, it means the entire array is in **descending order**. In a descending arrangement, there are no higher permutations available, so this is the **last permutation**. To reset to the first permutation in lexicographical order (i.e., the smallest possible arrangement), we reverse the array.

For example:
- For `3 2 1` (the largest permutation of `[1, 2, 3]`), no breaking point exists.
- Reversing gives `1 2 3`, the smallest permutation, starting the cycle over again.

### Connecting with the Permutation Formula
The permutation formula \( P(n, r) = \frac{n!}{(n - r)!} \) gives the count of permutations but does not describe the **order** or how to find the **next permutation**. The algorithm here uses **lexicographical order** to navigate from one permutation to the next by:

1. Identifying where we can make the smallest possible increase.
2. Adjusting the order minimally after that point.

This method ensures we cover all \( n! \) permutations one by one in sequence, which is essential for applications like generating permutations in combinatorial problems or for use in lexicographical ordering tasks.
