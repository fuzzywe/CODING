https://www.geeksforgeeks.org/problems/last-index-of-15847/1

https://www.geeksforgeeks.org/must-do-coding-questions-for-companies-like-amazon-microsoft-adobe/



---



```cpp

class Solution {
  public:
    int lastIndex(string s) {
        
        int index = -1;
        for(int i= 0;i<s.size();i++)
        {
            if(s[i]=='1') index = i;
            
        }return index;
    }
};

```
