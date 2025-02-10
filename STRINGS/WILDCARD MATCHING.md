Here’s an optimized **O(M) space complexity** version of the **Wildcard Pattern Matching** problem using **1D DP array** instead of a **2D DP table**. 🚀  

https://leetcode.com/problems/wildcard-matching/description/

https://www.geeksforgeeks.org/problems/wildcard-pattern-matching/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650?interviewBundleRedirection=true
---

### **Optimized Approach (1D DP)**
We **only use a 1D array (`prev`)** instead of a full `2D` matrix because at any point, we only need values from the **previous row**.

---

### **C++ Code (Space Optimized)**
```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<bool> prev(m + 1, false);
        
        prev[0] = true;  // Empty string matches empty pattern
        
        // Handle patterns with leading '*' (can match empty string)
        for (int j = 0; j < m && p[j] == '*'; ++j) {
            prev[j + 1] = true;
        }

        for (int i = 1; i <= n; ++i) {
            vector<bool> curr(m + 1, false);
            
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] == '*') {
                    curr[j] = curr[j - 1] || prev[j];
                } else {
                    curr[j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && prev[j - 1];
                }
            }

            prev = curr; // Update the previous row for next iteration
        }
        
        return prev[m];  // Final result
    }
};
```

---

No worries! I'll explain it in the **simplest way possible** so you can understand it clearly. Let's take it **step by step** with a very simple example. 😊  

---

## **🔹 Problem Recap (Wildcard Matching)**
We have:
- A **string `s`** (input string)
- A **pattern `p`** (which may contain `*` and `?`)

✅ Our goal is to check if `s` matches `p`, where:
- `?` → Matches **exactly one** character.
- `*` → Matches **any sequence** (including an empty sequence).

---

## **🔹 Understanding the Code Step by Step**
Let's take this input:  

```cpp
s = "abcde";
p = "a*de";
```
✅ Does `"abcde"` match `"a*de"`? → **YES!**  

Now, let's break the code into **3 simple steps**:

---

### **Step 1: Create a DP Table**
We create a **2D table (`dp`)** where:
- `dp[i][j]` means:  
  **Does the first `i` characters of `s` match the first `j` characters of `p`?**  

💡 **Example:**
For `s = "abcde"` and `p = "a*de"`, the table will have **rows = 6** (because `s` has 5 chars + 1 extra row)  
and **columns = 5** (because `p` has 4 chars + 1 extra column).  

---

### **Step 2: Initialize Base Cases**
✅ If **both `s` and `p` are empty**, then they match:
```cpp
dp[0][0] = true;
```
✅ If **pattern `p` starts with `*`**, then it can match an **empty string**:
```cpp
for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
    dp[0][j + 1] = true;
}
```
💡 Example:
- `p = "*"`, it can match an empty string → ✅ `dp[0][1] = true`
- `p = "**"`, still empty → ✅ `dp[0][2] = true`
- `p = "***"`, still empty → ✅ `dp[0][3] = true`

---

### **Step 3: Fill the DP Table**
We now go through each character of `s` and `p`, and check:

#### **Case 1: If `p[j-1] == '*'`**
✅ We have **2 choices**:
1️⃣ Treat `*` as **an empty sequence** → Just ignore `*`  
   ```cpp
   dp[i][j] = dp[i][j-1];  // '*' is skipped
   ```
2️⃣ Treat `*` as **matching a character** → Extend the previous match  
   ```cpp
   dp[i][j] = dp[i-1][j];  // '*' takes one character
   ```
💡 **Example**
- `s = "abcde"`, `p = "a*de"`
  - `"a"` matches `"a"`
  - `"*"` can match `"bc"` (or nothing)
  - `"d"` must match `"d"`
  - `"e"` must match `"e"`
  - ✅ **Match found!**

---

#### **Case 2: If `p[j-1] == '?'` or `s[i-1] == p[j-1]`**
✅ This is a **direct match**, so we take the **previous diagonal value**:
```cpp
dp[i][j] = dp[i-1][j-1];
```
💡 **Example**
- `s = "abcde"`, `p = "a?cde"`
  - `"a"` matches `"a"`
  - `"?"` matches `"b"` (because `?` can be anything)
  - `"c"` matches `"c"`
  - `"d"` matches `"d"`
  - `"e"` matches `"e"`
  - ✅ **Match found!**

---

### **Step 4: Return the Final Answer**
The final answer is stored at:
```cpp
return dp[s.size()][p.size()];
```
- If `dp[s.size()][p.size()] == true`, `s` matches `p`.
- Otherwise, it doesn't match.

---

## **🚀 Example Walkthrough**
### **Example 1**
#### **Input**
```cpp
s = "abcde", p = "a*de";
```
#### **Table Filled Step-by-Step**
| `s` \ `p` | ` ` | `a` | `*` | `d` | `e` |
|-----------|----|----|----|----|----|
| **` `**    | ✅ | ❌ | ✅ | ❌ | ❌ |
| **`a`**    | ❌ | ✅ | ✅ | ❌ | ❌ |
| **`b`**    | ❌ | ❌ | ✅ | ❌ | ❌ |
| **`c`**    | ❌ | ❌ | ✅ | ❌ | ❌ |
| **`d`**    | ❌ | ❌ | ✅ | ✅ | ❌ |
| **`e`**    | ❌ | ❌ | ✅ | ❌ | ✅ |

✅ `dp[5][4] = true` (Pattern Matches)

---

## **🎯 Interview Explanation (EASY Version)**
If an interviewer asks you, explain it like this:  

1️⃣ **We create a DP table**, where `dp[i][j]` means **whether the first `i` characters of `s` match the first `j` characters of `p`.**  
2️⃣ **Base case**: An empty pattern matches an empty string (`dp[0][0] = true`).  
3️⃣ **If `p[j-1] == '*'`, it can:**
   - **Match 0 characters** (ignore `*`).
   - **Match 1 or more characters** (extend match).  
4️⃣ **If `p[j-1] == '?'` or matches `s[i-1]`,** we **take the diagonal value** (`dp[i-1][j-1]`).  
5️⃣ **Return `dp[s.size()][p.size()]` as the final answer.**  

✅ This ensures **fast matching in `O(N*M)` time complexity**.

---

## **⏳ Time & Space Complexity**
✅ **Time Complexity**: `O(N*M)`  
✅ **Space Complexity**: `O(N*M)`, but can be **optimized to `O(M)`**.

---

Great! Let's go through **another example** **step by step** so that you fully understand it. 😊  

---

## **🔹 Example 2**
### **📌 Input**
```cpp
s = "abceb";
p = "*a*b";
```
### **📌 Output**
```cpp
true
```
✅ `"abceb"` **matches** `"*a*b"`  

---

### **Step 1: Create a DP Table**
We create a **DP table `dp[i][j]`**, where:
- `i` → Represents the **first `i` characters** of `s`
- `j` → Represents the **first `j` characters** of `p`
- `dp[i][j] = true` means that **the first `i` characters of `s` match the first `j` characters of `p`**  

💡 **We create a (6 x 6) table** because:
- `s = "abceb"` (5 characters + 1 extra row)
- `p = "*a*b"` (4 characters + 1 extra column)

---

### **Step 2: Initialize Base Cases**
✅ **If both `s` and `p` are empty, they match:**  
```cpp
dp[0][0] = true;
```

✅ **If `p` starts with `*`, it can match an empty string:**  
```cpp
for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
    dp[0][j + 1] = true;
}
```
Since `p` starts with `*`, we set:
```cpp
dp[0][1] = true;
```

---

### **Step 3: Fill the DP Table**
We now **iterate over each character** of `s` and `p`:

#### **🔹 Case 1: If `p[j-1] == '*'`**
✅ We have **2 choices**:
1️⃣ Ignore `*` (treat it as an empty sequence) → `dp[i][j] = dp[i][j-1]`  
2️⃣ Match `*` with a character from `s` → `dp[i][j] = dp[i-1][j]`

#### **🔹 Case 2: If `p[j-1] == '?'` or `s[i-1] == p[j-1]`**
✅ **They match**, so we take the diagonal value:
```cpp
dp[i][j] = dp[i-1][j-1];
```

---

### **Step 4: Fill the Table Step-by-Step**
| `s` \ `p` | ` ` | `*` | `a` | `*` | `b` |
|-----------|----|----|----|----|----|
| **` `**    | ✅ | ✅ | ❌ | ❌ | ❌ |
| **`a`**    | ❌ | ✅ | ✅ | ✅ | ❌ |
| **`b`**    | ❌ | ✅ | ❌ | ✅ | ✅ |
| **`c`**    | ❌ | ✅ | ❌ | ✅ | ❌ |
| **`e`**    | ❌ | ✅ | ❌ | ✅ | ❌ |
| **`b`**    | ❌ | ✅ | ❌ | ✅ | ✅ |

✅ `dp[5][4] = true`, so **the pattern matches the string!**

---

### **Step 5: Return the Final Answer**
```cpp
return dp[s.size()][p.size()];  // returns true
```

---

## **🎯 Summary**
1️⃣ **We create a DP table `dp[i][j]`**, where `i` and `j` represent the first `i` characters of `s` and `j` characters of `p`.  
2️⃣ **Base case:** An empty pattern matches an empty string (`dp[0][0] = true`).  
3️⃣ **If `p[j-1] == '*'`, we have 2 choices:**
   - Ignore `*`
   - Match `*` with one or more characters.  
4️⃣ **If `p[j-1] == '?'` or `s[i-1] == p[j-1]`, take the diagonal value (`dp[i-1][j-1]`).**  
5️⃣ **Return `dp[s.size()][p.size()]` as the final answer.**

✅ **Time Complexity:** `O(N*M)`  
✅ **Space Complexity:** `O(N*M)`, but can be optimized to `O(M)`

---

### **🚀 Final Thoughts**
This method ensures **efficient wildcard matching** with an optimal approach.  

Great! Let's go through **another example** **step by step** so that you fully understand it. 😊  

---

## **🔹 Example 2**
### **📌 Input**
```cpp
s = "abceb";
p = "*a*b";
```
### **📌 Output**
```cpp
true
```
✅ `"abceb"` **matches** `"*a*b"`  

---

### **Step 1: Create a DP Table**
We create a **DP table `dp[i][j]`**, where:
- `i` → Represents the **first `i` characters** of `s`
- `j` → Represents the **first `j` characters** of `p`
- `dp[i][j] = true` means that **the first `i` characters of `s` match the first `j` characters of `p`**  

💡 **We create a (6 x 6) table** because:
- `s = "abceb"` (5 characters + 1 extra row)
- `p = "*a*b"` (4 characters + 1 extra column)

---

### **Step 2: Initialize Base Cases**
✅ **If both `s` and `p` are empty, they match:**  
```cpp
dp[0][0] = true;
```

✅ **If `p` starts with `*`, it can match an empty string:**  
```cpp
for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
    dp[0][j + 1] = true;
}
```
Since `p` starts with `*`, we set:
```cpp
dp[0][1] = true;
```

---

### **Step 3: Fill the DP Table**
We now **iterate over each character** of `s` and `p`:

#### **🔹 Case 1: If `p[j-1] == '*'`**
✅ We have **2 choices**:
1️⃣ Ignore `*` (treat it as an empty sequence) → `dp[i][j] = dp[i][j-1]`  
2️⃣ Match `*` with a character from `s` → `dp[i][j] = dp[i-1][j]`

#### **🔹 Case 2: If `p[j-1] == '?'` or `s[i-1] == p[j-1]`**
✅ **They match**, so we take the diagonal value:
```cpp
dp[i][j] = dp[i-1][j-1];
```

---

### **Step 4: Fill the Table Step-by-Step**
| `s` \ `p` | ` ` | `*` | `a` | `*` | `b` |
|-----------|----|----|----|----|----|
| **` `**    | ✅ | ✅ | ❌ | ❌ | ❌ |
| **`a`**    | ❌ | ✅ | ✅ | ✅ | ❌ |
| **`b`**    | ❌ | ✅ | ❌ | ✅ | ✅ |
| **`c`**    | ❌ | ✅ | ❌ | ✅ | ❌ |
| **`e`**    | ❌ | ✅ | ❌ | ✅ | ❌ |
| **`b`**    | ❌ | ✅ | ❌ | ✅ | ✅ |

✅ `dp[5][4] = true`, so **the pattern matches the string!**

---

### **Step 5: Return the Final Answer**
```cpp
return dp[s.size()][p.size()];  // returns true
```

---

## **🎯 Summary**
1️⃣ **We create a DP table `dp[i][j]`**, where `i` and `j` represent the first `i` characters of `s` and `j` characters of `p`.  
2️⃣ **Base case:** An empty pattern matches an empty string (`dp[0][0] = true`).  
3️⃣ **If `p[j-1] == '*'`, we have 2 choices:**
   - Ignore `*`
   - Match `*` with one or more characters.  
4️⃣ **If `p[j-1] == '?'` or `s[i-1] == p[j-1]`, take the diagonal value (`dp[i-1][j-1]`).**  
5️⃣ **Return `dp[s.size()][p.size()]` as the final answer.**

✅ **Time Complexity:** `O(N*M)`  
✅ **Space Complexity:** `O(N*M)`, but can be optimized to `O(M)`

---

### **🚀 Final Thoughts**
This method ensures **efficient wildcard matching** with an optimal approach.  

**Do you want to try another example together?** 😊

**Do you want to try another example together?** 😊
