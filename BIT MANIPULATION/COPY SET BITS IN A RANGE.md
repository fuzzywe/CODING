Copy Set Bits in Range
Difficulty: EasyAccuracy: 39.22%Submissions: 55K+Points: 2
Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 32. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.

Note: Range count will be from Right to Left & start from 1.

Example 1:

Input: 
X = 44, Y = 3 
L = 1,  R = 5
Output: 
47
Explaination: 
Binary represenation of 44 and 3 is 101100 and 000011. So in the range 1 to 5 there are two set bits of 3 (1st & 2nd position). If those are set in 44 it will become 101111 which is 47.
Example 2:

Input: 
X = 16, Y = 2
L = 1,  R = 3
Output: 18
Explaination: Binary represenation of 16 and 2 is 10000 and 10. If the mentioned conditions are applied then 16 will become 10010 which is 18.
Your Task:
You do not need to read input or print anything. Your task is to complete the function setSetBit() which takes the numbers X, Y, L and R as input parameters and returns the modified value of X.

Expected Time Complexity: O(R - L)
Expected Auxiliary Space: O(1)

---

```cpp

return ( x | (y & (((1 << ((r-l)+1))-1) << (l-1))));

```

---

```cpp
 int setSetBit(int x, int y, int l, int r){
        // code here
        int m=0;
        vector<int> v;
        //cout<<pow(2,32);
        while(x>0 || y>0){
            m++;
            int rx=x%2;
            int ry=y%2;
        
            if(m>=l && m<=r){
                if(rx==1 && ry==1)
                    v.push_back(1);
                else
                    v.push_back(rx+ry);
                    
            }
            else
                v.push_back(rx);
            x/=2;
            y/=2;
            
        }
        
        int ans=0;
        for(int i=0;i<v.size();i++){
             int t=pow(2,i);
             ans+=(t*v[i]);
            //cout<<v[i];
            
        }
        //cout<<endl;
        return(ans);
    }
```
