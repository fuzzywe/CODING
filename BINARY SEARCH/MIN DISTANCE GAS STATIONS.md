https://www.geeksforgeeks.org/problems/minimize-max-distance-to-gas-station/1

https://www.naukri.com/code360/problems/minimise-max-distance_7541449

Minimise Maximum Distance between Gas Stations

Example 1:
Input Format:
 N = 5, arr[] = {1,2,3,4,5}, k = 4
Result:
 0.5
Explanation:
 One of the possible ways to place 4 gas stations is {1,1.5,2,2.5,3,3.5,4,4.5,5}. Thus the maximum difference between adjacent gas stations is 0.5. Hence, the value of ‘dist’ is 0.5. It can be shown that there is no possible way to add 4 gas stations in such a way that the value of ‘dist’ is lower than this. 
Example 2:
Input Format:
 N = 10, arr[] = {1,2,3,4,5,6,7,8,9,10}, k = 1
Result:
 1
Explanation:
 One of the possible ways to place 1 gas station is {1,1.5,2,3,4,5,6,7,8,9,10}. Thus the maximum difference between adjacent gas stations is still 1. Hence, the value of ‘dist’ is 1. It can be shown that there is no possible way to add 1 gas station in such a way that the value of ‘dist’ is lower than this. 

Let’s understand how to place the new gas stations so that the maximum distance between two consecutive gas stations is reduced. 

Let’s consider a small example like this: given gas stations = {1, 7} and k = 2. 

Observation: A possible arrangement for placing 2 gas stations is as follows: {1, 7, 8, 9}. In this arrangement, the new gas stations are positioned after the last existing one. Prior to adding the new stations, the maximum distance between stations was 6 (i.e. the distance between 1 and 7). Even after placing the 2 new stations, the maximum distance remains unchanged at 6.

Conclusions:

From the above observation, we can conclude that placing new gas stations before the first existing station or after the 

last existing station will make no difference to the maximum distance between two consecutive stations.
 
So, in order to minimize the maximum distance we have to place the new gas stations in between the existing stations.
 
How to place the gas stations in between so that the maximum distance is minimized:

Until now we have figured out that we have to place the gas stations in between the existing ones. 
 
 But we have to place them in such a way that the maximum distance between two consecutive stations is the minimum possible.
 
Let’s understand this considering the previous example. Given gas stations = {1, 7} and k = 2.

If we place the gas stations as follows: {1, 2, 6, 7}, the maximum distance will be 4(i.e. 6-2 = 4).
 
 But if we place them like this: {1, 3, 5, 7}, the maximum distance boils down to 2. It can be proved that we cannot make the maximum distance lesser than 2.
 
To minimize the maximum distance between gas stations, we need to insert new stations with equal spacing. 
 
 If we have to add 'k' gas stations within a section of length 'section_length', each station should be placed at a distance of
(section_length / (k + 1)) from one another.
 
This way, we maintain a uniform spacing between consecutive gas stations.

For example, the gas stations are = {1, 7} and k = 2. Here, the ‘dist’ is = (7-1) = 6. 

So, the space between two gas stations will be dis / (k+1) = 6 / (2+1) = 2. The placements will be as follows: {1, 3, 5, 7}.

BRUTE FORCE
  
Naive Approach: 
We are given n gas stations. Between them, there are n-1 sections where we may insert the new stations to reduce the distance. 

So, we will create an array of size n-1 and each of its indexes will represent the respective sections between the given gas stations. 

In each iteration, we will identify the index 'i' where the distance (arr[i+1] - arr[i]) is the maximum. Then, 
 
 we will insert new stations into that section to reduce that maximum distance. The number of stations inserted in each section

will be tracked using the previously declared array of size n-1.

Finally, after placing all the stations we will find the maximum distance between two consecutive stations. 
 
 To calculate the distance using the previously discussed formula, we will just do as follows for each section:

distance = section_length / (number_of_stations_ inserted+1)

Among all the values of ‘distance’, the maximum one will be our answer.

Algorithm:
First, we will declare an array ‘howMany[]’ of size n-1, to keep track of the number of placed gas stations.
 
Next, using a loop we will pick k gas stations one at a time.
 
Then, using another loop, we will find the index 'i' 
 
 where the distance (arr[i+1] - arr[i]) is the maximum and insert the current gas station between arr[i] and arr[i+1] (i.e. howMany[i]++).

Finally, after placing all the new stations, we will find the distance between two consecutive gas stations. For a particular section,
 
distance = section_length / (number_of_stations_ inserted+1)
 
    = (arr[i+1]-arr[i]) / (howMany[i]+1)
 
Among all the distances, the maximum one will be the answer.
```cpp

#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength =
            diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

```
Time Complexity: O(k*n) + O(n), n = size of the given array, k = no. of gas stations to be placed.
Reason: O(k*n) to insert k gas stations between the existing stations with maximum distance. Another O(n) for finding the answer i.e. the maximum distance.

Space Complexity: O(n-1) as we are using an array to keep track of placed gas stations.
Let's go step-by-step and perform a **dry run** of the given code, explaining what each line is doing.

### Input:
```cpp
vector<int> arr = {1, 2, 3, 4, 5};
int k = 4;
```
The goal is to insert 4 gas stations in such a way that the maximum distance between any two consecutive stations is minimized.

### Step-by-Step Breakdown:

---

#### Line-by-Line Walkthrough of the Code:

1. **Function Signature:**
   ```cpp
   long double minimiseMaxDistance(vector<int> &arr, int k)
   ```
   - This function will return a floating-point value (long double), representing the minimized maximum distance after placing the gas stations.
   - `arr` contains positions of existing stations or points, and `k` is the number of gas stations to be placed.

2. **Get the size of the array:**
   ```cpp
   int n = arr.size();
   ```
   - `n` is the number of elements in the `arr` vector. In this case, `n = 5` because there are 5 positions in the array.

3. **Initialize a vector to keep track of how many gas stations are placed between consecutive points:**
   ```cpp
   vector<int> howMany(n - 1, 0); howMany = {0, 0, 0, 0};

   ```
   - This vector will store how many gas stations are inserted between every pair of consecutive points in `arr`. Since there are `n-1` gaps between `n` points, the size of `howMany[]` is `4` (for a total of `4` gaps between points).
   - Initially, all values are `0`, meaning no gas stations are placed yet.

4. **Outer loop to place `k` gas stations:**
   ```cpp
   for (int gasStations = 1; gasStations <= k; gasStations++) {
   ```
   - This loop will run `k` times to place `k` gas stations. For each iteration, we find the section (gap between consecutive points) with the maximum distance and place a gas station there.

---

#### **Placing Gas Stations:**

5. **Variables to track the maximum section and its index:**
   ```cpp
   long double maxSection = -1;
   int maxInd = -1;
   ```
   - `maxSection` holds the value of the longest section (the largest gap) between two points for the current iteration.
   - `maxInd` holds the index of that section.

6. **Find the maximum section in the current configuration:**
   ```cpp
   for (int i = 0; i < n - 1; i++) {
       long double diff = arr[i + 1] - arr[i];
       long double sectionLength = diff / (long double)(howMany[i] + 1);
       if (sectionLength > maxSection) {
           maxSection = sectionLength;
           maxInd = i;
       }
   }
   ```
   - Loop through all the sections (gaps between consecutive points).
   - `diff = arr[i + 1] - arr[i]` is the length of the section between points `i` and `i+1`.
   - `sectionLength = diff / (howMany[i] + 1)` is the effective length of this section after dividing it by the number of gas stations already placed there (`howMany[i] + 1`).
   - If `sectionLength` is the largest we've seen so far, update `maxSection` and `maxInd` with the current section's details.
diff is the distance between two consecutive locations in the arr vector. For example, if the locations are at arr[i] and arr[i+1], diff would be arr[i+1] - arr[i].

howMany[i] keeps track of how many gas stations have been placed between the two consecutive locations arr[i] and arr[i+1]. Initially, it is set to 0 (no stations placed).

howMany[i] + 1 is the number of "sections" between two consecutive locations after placing the gas stations. This includes the original section plus any additional sections formed by the gas stations placed in between.

The division diff / (howMany[i] + 1) splits the total distance between arr[i] and arr[i+1] into equal-sized "sections" based on how many gas stations have been placed between them. Each section would be of equal length, which is what sectionLength represents.

Example:
Suppose we have two locations at arr[i] = 1 and arr[i+1] = 5. The distance diff = arr[i+1] - arr[i] = 5 - 1 = 4.

If no gas stations have been placed between them (howMany[i] = 0), the section length is the full distance between the two points: sectionLength = 4 / (0 + 1) = 4.

If one gas station is placed between them (howMany[i] = 1), the total distance is divided into 2 sections, and the length of each section becomes sectionLength = 4 / (1 + 1) = 2.

If two gas stations are placed (howMany[i] = 2), the distance is divided into 3 sections, so sectionLength = 4 / (2 + 1) = 1.33.

This formula helps determine the maximum length of each section after placing gas stations to ensure that the sections are as evenly distributed as possible.

7. **Place a gas station in the largest section:**
   ```cpp
   howMany[maxInd]++;
   ```
   - Increment the count of gas stations in the section with the largest `sectionLength` found in the previous step.

---

#### **After Placing All Gas Stations:**

8. **Calculate the maximum distance between consecutive gas stations:**
   ```cpp
   long double maxAns = -1;
   for (int i = 0; i < n - 1; i++) {
       long double diff = arr[i + 1] - arr[i];
       long double sectionLength = diff / (long double)(howMany[i] + 1);
       maxAns = max(maxAns, sectionLength);
   }
   ```
   - After placing all `k` gas stations, find the maximum distance between any two consecutive gas stations.
   - Again, compute the effective section length (`sectionLength`) for each section.
   - Track the largest section and store it in `maxAns`.

9. **Return the minimized maximum distance:**
   ```cpp
   return maxAns;
   ```

---

#### **In the `main()` Function:**

1. **Initialize the array and number of gas stations:**
   ```cpp
   vector<int> arr = {1, 2, 3, 4, 5};
   int k = 4;
   ```

2. **Call the function:**
   ```cpp
   long double ans = minimiseMaxDistance(arr, k);
   ```

3. **Print the result:**
   ```cpp
   cout << "The answer is: " << ans << "\n";
   ```

---

### Dry Run for Input `{1, 2, 3, 4, 5}` and `k = 4`:

1. **Initial State:**
   - `arr = {1, 2, 3, 4, 5}`
   - `k = 4`
   - `howMany[] = {0, 0, 0, 0}` (no stations placed yet).

---

2. **First Iteration (`gasStations = 1`):**
   - Compute distances between points: `{1, 1, 1, 1}`
   - All sections have equal length (`1.0`), so place a gas station in the first gap.
   - `howMany[] = {1, 0, 0, 0}`.

---

3. **Second Iteration (`gasStations = 2`):**
   - Distances now are `{0.5, 1, 1, 1}`
   - The largest section is the second one (`1.0`), so place a gas station there.
   - `howMany[] = {1, 1, 0, 0}`.

---

4. **Third Iteration (`gasStations = 3`):**
   - Distances now are `{0.5, 0.5, 1, 1}`
   - The largest section is the third one (`1.0`), so place a gas station there.
   - `howMany[] = {1, 1, 1, 0}`.

---

5. **Fourth Iteration (`gasStations = 4`):**
   - Distances now are `{0.5, 0.5, 0.5, 1}`
   - The largest section is the fourth one (`1.0`), so place a gas station there.
   - `howMany[] = {1, 1, 1, 1}`.

---

6. **Final Calculation:**
   - After placing all gas stations, the maximum distance between stations is `0.5`.

### Final Answer:
```cpp
The answer is: 0.5
```

This means after placing 4 gas stations, the maximum possible distance between consecutive stations is minimized to `0.5`.

  
Optimal Approach(Using Binary Search): 
We are going to use the Binary Search algorithm to optimize the approach.

The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

Observations:

Minimum possible answer: We will get the minimum answer when we place all the gas stations in a single location. Now, in this case, the maximum distance will be 0.
Maximum possible answer: We will not place stations before the first or after the last station rather we will place stations in between the existing stations. So, the maximum possible answer is the maximum distance between two consecutive existing stations.
From the observations, it is clear that our answer lies in the range [0, max(dist)].

Upon closer observation, we can recognize that our answer space is actually sorted. Additionally, we can identify a pattern that allows us to divide this space into two halves: one consisting of potential answers and the other of non-viable options. So, we will apply binary search on the answer space.

Changes in the binary search algorithm to apply it to the decimal answer space:

The traditional binary search algorithm used for integer answer space won't be effective in this case. As our answer space consists of decimal numbers, we need to adjust some conditions to tailor the algorithm to this specific context. The changes are the following:

while(low <= high): The condition 'while(low <= high)' inside the 'while' loop won't work for decimal answers, and using it might lead to a TLE error. To avoid this, we can modify the condition to 'while(high - low > 10^(-6))'. This means we will only check numbers up to the 6th decimal place. Any differences beyond this decimal precision won't be considered, as the question explicitly accepts answers within 10^-6 of the actual answer.
low = mid+1: We have used this operation to eliminate the left half. But if we apply the same here, we might ignore several decimal numbers and possibly our actual answer. So, we will use this: low = mid.
high = mid-1: Similarly, We have used this operation to eliminate the right half. But if we apply the same here, we might ignore several decimal numbers and possibly the actual answer. So, we will use this: high = mid.
We are applying binary search on the answer i.e. the possible values of distances. So, we have to figure out a way to check the number of gas stations we can place for a particular value of distance.

How to check the number of gas stations we can place with a particular distance ‘dist’: 

In order to find out the number of gas stations we will use the following function:

numberOfGasStationsRequired(dist, arr[]): 

We will use a loop(say i) that will run from 1 to n.
For each section between i and i-1, we will do the following:
No. of stations = (arr[i]-arr[i-1]) / dist
Let's keep in mind a crucial edge case: if the section_length (arr[i] - arr[i-1]) is completely divisible by 'dist', the actual number of stations required will be one less than what we calculate.
if (arr[i]-arr[i-1] == (No. of stations*dist): No. of stations -= 1.
Now, we will add the no. of stations regarding all the sections and the total will be the answer.
Algorithm:
First, we will find the maximum distance between two consecutive gas stations i.e. max(dist).
Place the 2 pointers i.e. low and high: Initially, we will place the pointers. The pointer low will point to 0 and the high will point to max(dist).
Now, we will use the ‘while’ loop like this: while(high - low > 10^(-6)).
Calculate the ‘mid’: Now, inside the loop, we will calculate the value of ‘mid’ using the following formula:
mid = (low+high) / 2.0
Eliminate the halves based on the number of stations returned by numberOfGasStationsRequired():
We will pass the potential value of ‘dist’, represented by the variable 'mid', to the ‘numberOfGasStationsRequired()' function. This function will return the number of gas stations we can place.
If result > k: On satisfying this condition, we can conclude that the number ‘mid’ is smaller than our answer. So, we will eliminate the left half and consider the right half(i.e. low = mid).
Otherwise, the value mid is one of the possible answers. But we want the minimum value. So, we will eliminate the right half and consider the left half(i.e. high = mid).
Finally, outside the loop, we can return either low or high as their difference is beyond 10^(-6). They both can be the possible answer. Here, we have returned the ‘high’.
```cpp


class Solution {
  public:
  int gaskdist(vector<int>&stations,long double dist)
  {int cnt =0;
  
      for (int i =1;i<stations.size();i++)
      {
          int diff = ((stations[i] - stations[i-1])/dist);
          if((stations[i]-stations[i-1])/dist == (dist*diff))
          {
              diff--;
          }cnt += diff;
      }return cnt;
      
  }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        long double low =0;
        long double high =0;
        long double diff = 1e-6;
        
        for(int i =1;i<stations.size();i++)
        {
            high = max(high,(long double)(stations[i] -stations[i-1]));
        }
        while(high - low > diff){
            long double mid = (long double)(high+low)/(2.0);
            int gastations = gaskdist(stations,mid);
            if(gastations>k) low = mid;
            else high= mid;
        }return round(high*100.0)/100.0;
    }
};


```

---

or  

---

 ```cpp 
 
#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

```
Time Complexity: O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.
Reason: We are applying binary search on the answer space. For every possible answer, we are calling the function numberOfGasStationsRequired() that takes O(n) time complexity. And another O(n) for finding the maximum distance initially.

Space Complexity: O(1) as we are using no extra space to solve this problem.

 Input:

cpp
Copy code
arr = {1, 2, 3, 4, 5};
k = 4;
Initial Setup:

low = 0, high = 1.0 (the maximum distance between consecutive points).
Binary search will now be applied between low = 0 and high = 1.
Binary Search Iteration 1:

Compute mid = (0 + 1) / 2 = 0.5.
Call numberOfGasStationsRequired(0.5, arr):
Distances: {1, 1, 1, 1}
Required gas stations for each distance: 1 (between each pair).
Total gas stations required: 4.
Since cnt == k, reduce high = mid = 0.5.
Binary Search Iteration 2:

Compute mid = (0 + 0.5) / 2 = 0.25.
Call numberOfGasStationsRequired(0.25, arr):
Required gas stations: more than 4 (more gas stations needed for smaller distances).
Since cnt > k, increase low = mid = 0.25.
Continue Binary Search:

The binary search continues, halving the search space until the difference between low and high is small enough
