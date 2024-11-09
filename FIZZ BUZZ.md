412. Fizz Buzz

https://leetcode.com/problems/fizz-buzz/description/

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i (as a string) if none of the above conditions are true.
 

Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

optimal 

```cpp

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++)
            ans.push_back(i % 3 == 0 && i % 5 == 0 ? "FizzBuzz" : i % 3 == 0 ? "Fizz" : i % 5 == 0 ? "Buzz" : to_string(i));
        return ans;
    }
};

```

---


```cpp

class Solution {
public:
    vector<string> fizzBuzz(int n) {

        vector<string> ans;
        int cnt = 1;

        while(cnt <= n) {
            string temp = "";
            if(cnt%15 == 0) 
                temp = "FizzBuzz";
            else if(cnt%5 == 0) 
                temp = "Buzz";
            else if(cnt%3 == 0) 
                temp = "Fizz";
            else 
                temp = to_string(cnt);
            ans.push_back(temp);
            cnt++;
        }

        return ans;
        
    }
};

```


