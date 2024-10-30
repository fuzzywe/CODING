31. Next Permutation

https://leetcode.com/problems/next-permutation/


https://www.naukri.com/code360/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 1-43 screenshot](https://github.com/user-attachments/assets/3a98b57e-2c68-4f98-92b5-42a2136cc034)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 3-23 screenshot](https://github.com/user-attachments/assets/85c2d1b4-76e6-49d8-8884-64f28df37329)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 3-24 screenshot](https://github.com/user-attachments/assets/5bdd0622-4e5b-49f1-837f-cd56d88018fb)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 2-18 screenshot](https://github.com/user-attachments/assets/d7fbd572-b24e-4ab3-bb76-affc272e40f0)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 1-43 screenshot](https://github.com/user-attachments/assets/1a06ce05-e469-4ce9-8af3-a4bad0360a66)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 4-49 screenshot (1)](https://github.com/user-attachments/assets/010f3ad3-970d-425e-9c8f-50f54dff8845)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 15-22 screenshot](https://github.com/user-attachments/assets/b515ead2-e4c5-420d-8c24-a120cab67f7c)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 15-22 screenshot](https://github.com/user-attachments/assets/963b109a-b4aa-4ad5-89f2-c48eccf9e553)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 15-33 screenshot](https://github.com/user-attachments/assets/1331eaca-0595-4f9a-85a1-007fc5bd4a25)




**after 5 all elements are decreasing so the break point is from 1**


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 16-7 screenshot](https://github.com/user-attachments/assets/c0be00ae-0498-4204-9121-7f8a13036660)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 16-36 screenshot](https://github.com/user-attachments/assets/d8d12239-00f3-41bb-935e-b058b43c69d2)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 18-5 screenshot](https://github.com/user-attachments/assets/c3ac50d1-015c-4604-88cd-cb6ee8f7cbdc)

break point is 1 and on the right side we have elements < 1 which is 0,0.

from looking right side 

we have elements [2 1 5 4 3 0 0]

3 > 1 so place 2 3 _ _ _ _ _ [ the remaining elements to fill [5 4  1 0 0]

place the remaining elements in sorted order 

2 3 0 0 1 4 5


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 20-58 screenshot](https://github.com/user-attachments/assets/a98bbc6a-5b29-4a6d-8b9b-cf42c81dc331)


if ind = -1 then just reverse the arr

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 21-50 screenshot](https://github.com/user-attachments/assets/e4215b3a-df0d-465d-af72-3644d73714d8)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 22-41 screenshot](https://github.com/user-attachments/assets/c2836a15-a109-40e1-a18e-344b073aa131)

from seeing right to left 3 is greater then 1 so swap .

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 23-24 screenshot](https://github.com/user-attachments/assets/c44e9bd8-6b7f-41b5-9a6b-6d7270017019)

![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 23-56 screenshot](https://github.com/user-attachments/assets/26f49b87-2d69-4e5f-a0d2-74214de64ab3)


![Next Permutation - Intuition in Detail 🔥 _ Brute to Optimal 24-38 screenshot](https://github.com/user-attachments/assets/6990a0a0-b55e-48ba-a1c9-414e0debd1b1)

explain to interviewer
for brute force

1.doing recursion
2.linear search
3.return the next permutation

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
for better approach 
explain the stl function next_permutation.

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


OPTIMAL

Approach
The steps are the following:

Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
So, in this case, we will reverse the whole array and will return it as our answer.
If a break-point exists:
Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.

```cpp

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1 = -1;
        int ind2 = -1;
        
        // Step 1: Find the "breaking point"
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind1 = i;
                break;
            }
        }
        
        // If there's no breaking point, reverse the whole array
        if (ind1 == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            // Step 2: Find the next greater element and swap with ind2
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] > nums[ind1]) {
                    ind2 = i;
                    break;
                }
            }
            swap(nums[ind1], nums[ind2]);
            // Step 3: Reverse the rest of the right half
            reverse(nums.begin() + ind1 + 1, nums.end());
        }
    }
};


```
