
https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

421. Maximum XOR of Two Numbers in an Array
Medium
Topics
Companies
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127

```cpp
class TrieNode{
	public :
		TrieNode* left;
		TrieNode* right;

		TrieNode(){
			left = nullptr;
			right = nullptr;
		}
};

class Trie{
	TrieNode* root;

	public :
		Trie(){
			root = new TrieNode();        
		}

		void Insert(int num){
			TrieNode* curr = root;
			for(int i = 31 ; i >= 0 ; i--){
			   int bit = (1 << i)&num;
			   if(bit == 0){
				  if(curr -> left == nullptr){
					 curr -> left = new TrieNode();
				  }
				  curr = curr -> left;
			   }else{
				  if(curr -> right == nullptr){
					 curr -> right = new TrieNode();
				  }
				  curr = curr -> right;
			   }
			}
		}

		int MaxXorPair(int n , vector<int> v){

			for(int i = 0 ; i < n ; i++){
				Insert(v[i]);
			}

			int Xor = INT_MIN;
			for(int i = 0 ;i < n ; i++){
				int curr_xor = 0;
				TrieNode* curr = root;
				for(int j = 31 ;j >= 0 ; j--){
					int bit = (1 << j) & v[i];
					if(bit == 0){
						if(curr -> right != nullptr){
							curr_xor += (1 << j);
							curr = curr -> right;
						}else{
							curr = curr -> left;
						}
					}else{
						if(curr -> left != nullptr){
							curr_xor += (1 << j);
							curr = curr -> left;
						}else{
							curr = curr -> right;
						}
					}
				}
				Xor = max(Xor , curr_xor);
			}
			return Xor;
		}
};


class Solution {
public:

	int findMaximumXOR(vector<int>& nums) {
		 Trie t;
		 return t.MaxXorPair(nums.size() , nums);    
	}
};
```
