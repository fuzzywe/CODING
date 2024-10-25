Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175
Your Task:
You don't need to print or input anything. Complete the function minimumMultiplications() which takes an integer array arr, an integer start and an integer end as the input parameters and returns an integer, denoting the minumum steps to reach in which end can be achieved starting from start.

---

![image](https://github.com/user-attachments/assets/a6f065e8-2117-4072-9e81-c1831e878733)



![image](https://github.com/user-attachments/assets/6088b985-e152-44ef-aa00-f6b2a5341513)


---

```cpp

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>> q;
        vector<int> dist(100000,1e9);
        dist[start]=0;
        q.push({start,0});
        int mod=100000;
        while(!q.empty()){
            int node=q.front().first;
            int step=q.front().second;
            q.pop();
            for(auto it:arr){
                int num=(it*node)%mod;
                if(step+1<dist[num]){
                    dist[num]=step+1;
                    if(num==end) return step+1;
                    q.push({num,step+1});
                }
            }
        }
        if(start==end) return 0;
        return -1;
    }
};

```
