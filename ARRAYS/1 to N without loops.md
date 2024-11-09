"Recursion" involves two key elements:


1.the base case (or termination case).
2. the recursive case.


Understanding these elements is crucial for solving recursive problems. I used to encounter challenges with recursion, but I've recently started learning and solving problems to improve my understanding.


here is some of the problem which is solved till now are.


Print 1 to N || vice verca

Height of a Binary Tree.

Sort an array using recursion

Sort a stack using recursion.

Delete middle Element Using stack.

Reverse stack Using recursion.

here is the code of
---

**Print 1 To N**
```cpp
void oneton(int n){
    if(n == 1){
        cout << n<<" ";
        return;
    }
    oneton(n-1);
    cout << n;
    return;
}

```
---

**Height of a binary Tree.**

```cpp

int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
            
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1 + max(left,right);
        
    }

```
---

**Sort an array Using Recursion.**

approch for this code is , 

we first try to decrease the size of the array and then sort the array while we decrese it
```cpp

void insertin(vector<int> & nums,int temp){
       if(nums.size() == 0 || nums[nums.size()-1] <= temp){
           nums.push_back(temp);
           return;
       }
       int val = nums[nums.size() -1];
       nums.pop_back();
       insertin(nums,temp);
       nums.push_back(val);
       return;
   }
   void arraysort(vector<int>& nums){
       if(nums.size() == 1){
           return;
       }
       int temp = nums[nums.size()-1];
       nums.pop_back();
       arraysort(nums);
       insertin(nums,temp);
       return;
       
   }
```
   ---
   
**Sort Stack Using Recursion.**

```cpp

void insertin(stack<int> &st,int temp){
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insertin(st,temp);
    st.push(val);
    return;
}

void sortstack(stack<int> &st){
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();
    sortstack(st);
    insertin(st,temp);
    return;

}

```
---

**Delete Middle Element in stack Using Recursion.**

```cpp

Here d is the middle elemnt d = ( st.size()/2 ) +1 

void delstack(stack<int> &st,int d){
    if(st.size() == d){
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    delstack(st,d);
    st.push(temp);
    return;
    
}

```
---

**Reverse Stack Using recursion**

```cpp

void insertin(stack<int> &st,int ele){
    if(st.empty()){
        st.push(ele);
        return;
    }
    int temp = st.top();
    st.pop();
    insertin(st,ele);
    st.push(temp);
    return;
}
void revstack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int ele = st.top();
    st.pop();
    revstack(st);
    
    insertin(st,ele);
    return;
}

```
---
7 . [Subsets]

```cpp
	void subset(vector<int> & nums, vector<int>temp, int i,vector<vector<int>> &ans){
        if(i >=  nums.size()){
            ans.push_back(temp);
            
            return;
        }
        subset(nums,temp,i+1,ans);
        temp.push_back(nums[i]);
        subset(nums,temp,i+1,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        subset(nums,temp,0,ans);
        return ans;
    }

```

---

Subset ||

```cpp
	void print(vector<int>&nums, int i, vector<int>ss,set<vector<int>>&st){
        
        if(i >= nums.size()){
            st.insert(ss);
            return;
        }
        print(nums,i+1, ss,st);
        int ele = nums[i];
        ss.push_back(ele);
        print(nums,i+1, ss,st);
        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>>st;
        vector<int>ss;
        sort(nums.begin(), nums.end());
        print(nums,0, ss,st);
        for(auto it = st.begin(); it != st.end(); it++){
            res.push_back(*it);
            
        }
        return res;
        
            
    }


    ```
