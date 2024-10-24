Fruit Into Baskets

https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array of arr[], where arr[i]  is the type of fruit the ith tree produces.
You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow :

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of the baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array of fruits, return the maximum number of fruits you can pick.

Examples:

Input: arr[]= [2, 1, 2]
Output: 3
Explanation: We can pick one fruit from all three trees. Please note that the type of fruits is same in the 1st and 3rd baskets.
Input: arr[] = [3, 1, 2, 2, 2, 2]
Output: 5
Explanation: It's optimal to pick from the last 5 trees. Please note that we do not pick the first basket as we would have to stop at thrid tree which would result in only 2 fruits collected.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

---
```cpp
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0, right = 0, maxLen = 0;
        
        map<int, int> fruitCount;
        
        while (right < n) {
            fruitCount[fruits[right]]++;
            
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};


```

Overall, the time complexity is O(n).

Overall, the space complexity is O(n) due to the input array.
