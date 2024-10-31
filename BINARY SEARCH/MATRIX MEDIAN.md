https://www.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix



Median of Row Wise Sorted Matrix


73

6
Problem Statement: Given a row-wise sorted matrix of size MXN, where M is no. of rows and N is no. of columns, find the median in the given matrix.

Note: MXN is odd.

Examples
Example 1:
Input Format:M = 3, N = 3, matrix[][] =

                    1 4 9 
                    2 5 6
                    3 8 7
                    
Result: 5
Explanation:  If we find the linear sorted array, the array becomes 1 2 3 4 5 6 7 8 9. So, median = 5
Example 2:
Input Format:M = 3, N = 3, matrix[][] =

                    1 3 8 
                    2 3 4
                    1 2 5
                    
Result: 3
Explanation:  If we find the linear sorted array, the array becomes 1 1 2 2 3 3 4 5 7 8. So, median = 3


BRUTE FORCE 


```cpp
vector<int> v;
        int n= R*C;
        for(int i= 0; i<R;i++){
           for(int j=0;j<C; j++){
               v.push_back(matrix[i][j]);
           } 
        }
        sort(v.begin(), v.end());
        return v[n/2];
    }

```

---

OPTIMAL 

```cpp

class Solution {
public:
    int upperBound(vector<int> mat, int num) {
        int n = mat.size();
        int low = 0;
        int high = n - 1;
        int cnt = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mat[mid] > num) {
                cnt = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return cnt;
    }

    int NoOfSmallerNum(vector<vector<int>> &mat, int num) {
        int n = mat.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(mat[i], num);
        }
        return cnt;
    }

    int median(vector<vector<int>> &mat, int R, int C) {
        int low = INT_MAX;
        int high = INT_MIN;

        for (int i = 0; i < R; i++) {
            if (mat[i][0] < low) {
                low = mat[i][0];
            }
            if (mat[i][C - 1] > high) {
                high = mat[i][C - 1];
            }
        }

        int req = (R * C) / 2;

        int ans = -1; 
        while (low <= high) {
            int mid = low + (high - low) / 2;

            int smallernum = NoOfSmallerNum(mat, mid);

            if (smallernum > req) {
                ans = mid; 
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
};

```
