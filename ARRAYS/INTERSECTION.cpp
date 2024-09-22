Intersection of two sorted arrays

Examples:

Example 1:
Input: 
A: [1 2 3 3 4 5 6]
, B: [3 3 5]
Output: 3,3,5
Explanation: We are given two arrays A and B. 
The elements present in both the arrays  
are 3,3 and 5.

Example 2:
Input: 
A: [1 2 3 3 4 5 6]
, B: [3 5]
Output: 3,5
Explanation: We are given two arrays A and B. 
The elements present in both the arrays are 3 and 5.
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Brute Force Approach:
For the brute force approach, we are given 2 arrays, we take an element from array A and search if it is present in array B on the condition that the same element in array B hasn’t been traversed before by any duplicate element in array A.

For Example:

A: [1 2 3 3 4 5 6] 
B: [3 3 5]
We first create a visited array for array B which is initialized with 0 indicating that initially none of the elements of array B are visited.
We start checking the first element from array A if it matches with any element of array B which is not yet visited. If they match, we mark the element in array B as visited, put the element in ans array, and move to the next element in array A.
If the element matches but is already being visited before, we do not add it to the ans array concluding that the element has been mapped to some other element previously.
After iterating the whole of Array A, we get the intersection of two arrays stored in the ans array.
For better understanding of intuition, please watch the video at the bottom of my page

Code:

C++
Java
#include<bits/stdc++.h>
using namespace std;

  vector<int> intersectionOfArrays(vector<int>A, vector<int>B){
    
  vector <int> ans;
  
  // to maintain visited
  vector <int> visited(B.size(), 0);  
  int i = 0, j = 0;
  
  for (i = 0; i < A.size(); i++) {
      
    for (j = 0; j < B.size(); j++) {

      if (A[i] == B[j] && visited[j] == 0) { 
      
        //if element matches and has not been matched with any other before
        ans.push_back(B[j]);
        visited[j] = 1;

        break;
      } 
      
      else if (B[j] > A[i]) break; 
      //because array is sorted , element will not be beyond this
    }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  vector < int > A {1,2,3,3,4,5,6,7};
  vector < int > B {3,3,4,4,5,8};

  vector<int> ans = intersectionOfArrays(A,B);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
Output:

3 3 4 5

Time Complexity: O(n1 x n2) ~ O(n^2) { There are nested loops where the outer one loops n1 times and the inner one loops n2 times, where n1 = A.size() and n2 = B.size() }.
Space Complexity: O(n) { Extra Space used for the visited and ans arrays }.

Solution 2: 2 Pointer approach

#include<bits/stdc++.h>
using namespace std;

  vector<int> intersectionOfArrays(vector<int>A, vector<int>B){
    
  // Declare ans array.
  vector <int> ans;

  int i = 0, j = 0; 

  // to traverse the arrays
  while (i < A.size() && j < B.size()) {
      
    //if current element in i is smaller
    if (A[i] < B[j]) { 
      i++;
    } else if (B[j] < A[i]) {
      j++;
    } else {
        
      //both elements are equal
      ans.push_back(A[i]); 
      i++;
      j++;
    }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  vector < int > A {1,2,3,3,4,5,6,7};
  vector < int > B {3,3,4,4,5,8};

  vector<int> ans = intersectionOfArrays(A,B);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}
Output:

3 3 4 5

Time Complexity: O(n) { Since the elements are compared within the single pass for both the arrays this approach would take a linear time and in the worst case O(n1+n2) where n1 = A.size() and n2 = B.size() }.

Space Complexity: O(1) { There is no extra space used in the two-pointers approach }.

