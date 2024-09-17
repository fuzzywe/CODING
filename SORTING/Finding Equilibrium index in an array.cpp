Example 1:
Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4

Example 2:
Input: nums = [1,-1,4]
Output: 2
Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
The sum of the numbers after index 2 is: 0


  #include <iostream>
using namespace std;
int findEquilibriumIdx(int nums[], int n) {
  int leftSum, rightSum;
 
  for (int i = 0; i < n; i++) {
    leftSum = 0;
    for (int j = 0; j < i; j++) {
      leftSum += nums[j];
    }
    rightSum = 0;
    for (int j = i + 1; j < n; j++) {
      rightSum += nums[j];
    }
    if (leftSum == rightSum) {
      return i;
    }
  }
  return -1;
}
int main() {
  int n = 5;
  int arr[] = { 2, 3, -1, 8, 4 };
  int equilibriumidx = findEquilibriumIdx(arr, n);
  cout << equilibriumidx << endl;
  return 0;
}
Output: 3

Time Complexity: O(N^2)

Space Complexity: O(1)

#include <iostream>
 
using namespace std;
int findEquilibriumIdx(int nums[], int n) {
  int totalSum = 0;
  for (int i = 0; i < n; i++) {
    totalSum += nums[i];
  }
  int leftSum = 0, rightSum = totalSum;
  for (int i = 0; i < n; i++) {
    rightSum -= nums[i];
    if (leftSum == rightSum) {
      return i;
    }
    leftSum += nums[i];
  }
  return -1;
}
int main() {
  int n = 5;
  int arr[] = {2, 3, -1, 8, 4};
  int equilibriumidx = findEquilibriumIdx(arr, n);
  cout << equilibriumidx << endl;
  return 0;
}
Output: 3

Time Complexity: O(N)

Space Complexity: O(1)
