621. Task Scheduler
Medium
Topics
Companies
Hint
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

1. Using priority queue

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int>mp(26,0);

        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
        }   
        for(int i=0;i<26;++i){
            if(mp[i]) 
            pq.push(mp[i]);
        }

        int time=0; // stores the total time taken 
        while(!pq.empty()){
            vector<int>remain;
            int cycle=n+1;  // n+1 is the CPU cycle length, if n is the cooldown period then after a task A there will be n more tasks. Hence n+1.

            while(cycle and !pq.empty()){
                int max_freq=pq.top(); // the task at the top should be first assigned the CPU as it has highest frequency
                pq.pop();
                if(max_freq>1){ // task with more than one occurrence, the next occurrence will be done in the next cycle 
                    remain.push_back(max_freq-1); // add it to remaining task list
                }
                ++time; 
                --cycle; 
            }

            for(int count:remain){
                pq.push(count); 
            }
            if(pq.empty())break; // if the priority queue is empty than all tasks are completed and we don't need to include the idle time
            time+=cycle; // this counts the idle time 
        }
        return time;
    }

```

2. Using formula
```cpp
class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        int max_freq=0, count_maxfreq=0, sz=tasks.size();
        for(char i:tasks){
            mp[i-'A']++;  // count the number of times a task needs to be done
            if(mp[i-'A']>max_freq){
                max_freq=mp[i-'A']; // find maximum frequency 
            }
        }   
        for(int i=0;i<26;i++){
            if(mp[i]==max_freq) count_maxfreq++; // number of tasks having maximum frequency
        }
        int time= (max_freq-1)*(n+1)+count_maxfreq; // total time taken to complete all tasks
        return max(time,sz);
    }
};
```

Sure! Let’s do a complete line-by-line explanation and dry run of the code you provided. This will cover every line, every loop iteration, and the logic step-by-step.

### Problem Recap:
You are given a list of tasks (denoted by characters) and a cooling time `n`. The goal is to determine the minimum number of CPU cycles required to complete all tasks, while respecting the rule that there must be at least `n` intervals between two executions of the same task (unless other tasks are performed in the meantime).

Example:
- Input: `tasks = ['A', 'A', 'A', 'B', 'B', 'B']`, `n = 2`
- Output: The least amount of time (CPU cycles) needed to complete all tasks.

---

### Code:

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> mp(26, 0);

        for (char i : tasks) {
            mp[i - 'A']++;  // count the number of times a task needs to be done
        }

        for (int i = 0; i < 26; ++i) {
            if (mp[i])
                pq.push(mp[i]);
        }

        int time = 0;  // stores the total time taken
        while (!pq.empty()) {
            vector<int> remain;
            int cycle = n + 1;  // CPU cycle length: current task + n other tasks or idle slots

            while (cycle && !pq.empty()) {
                int max_freq = pq.top();  // task with the highest frequency
                pq.pop();
                if (max_freq > 1) {  // if task has remaining occurrences
                    remain.push_back(max_freq - 1);  // add it to remaining task list
                }
                ++time;  // increase total time
                --cycle;  // one cycle is complete
            }

            for (int count : remain) {
                pq.push(count);  // reinsert remaining tasks with reduced frequencies
            }

            if (!pq.empty()) {
                time += cycle;  // add idle time if there are remaining tasks but cycle ended
            }
        }

        return time;  // return the total time taken
    }
};
```

---

### **Line-by-Line Explanation with Dry Run:**

#### **Input:**
- `tasks = ['A', 'A', 'A', 'B', 'B', 'B']`
- `n = 2`

---

#### Step 1: Initializing Priority Queue and Frequency Map

```cpp
priority_queue<int> pq;
vector<int> mp(26, 0);
```
- We initialize `pq`, a max-heap (priority queue), which will store task frequencies in descending order.
- We also initialize `mp` as a vector of size 26 (for 26 letters of the alphabet) to count how many times each task appears.

#### Dry Run:
- After initialization:
  - `pq = []`
  - `mp = [0, 0, 0, ..., 0]` (26 zeros)

---

#### Step 2: Count Frequencies of Each Task

```cpp
for (char i : tasks) {
    mp[i - 'A']++;
}
```
- Loop through the `tasks` vector to count the occurrences of each task and update the `mp` array. The tasks 'A' and 'B' both appear 3 times.

#### Dry Run:
- After processing:
  - `tasks = ['A', 'A', 'A', 'B', 'B', 'B']`
  - For 'A' -> `mp['A' - 'A'] = mp[0] = 3`
  - For 'B' -> `mp['B' - 'A'] = mp[1] = 3`
  - `mp = [3, 3, 0, 0, 0, ..., 0]`

---

#### Step 3: Push Non-zero Frequencies to Priority Queue

```cpp
for (int i = 0; i < 26; ++i) {
    if (mp[i])
        pq.push(mp[i]);
}
```
- Loop through the `mp` vector. If a frequency is non-zero, push it into the priority queue (`pq`). The queue automatically sorts the highest frequency on top.

#### Dry Run:
- After processing:
  - `mp[0] = 3` and `mp[1] = 3` are non-zero, so both are pushed to `pq`.
  - `pq = [3, 3]`

---

#### Step 4: Initialize Total Time

```cpp
int time = 0;  // stores the total time taken
```
- We initialize `time` to 0. This will track the total CPU cycles required.

---

#### Step 5: Main Loop to Process Tasks in Cycles

```cpp
while (!pq.empty()) {
    vector<int> remain;
    int cycle = n + 1;  // n+1 is the CPU cycle length (current task + n other tasks or idle)
```
- The outer loop runs as long as there are tasks left in the `pq`.
- We initialize `remain` to store tasks that still need processing after the current cycle.
- We initialize `cycle = n + 1`, which is the CPU cycle length (the current task + `n` cooling periods or other tasks).

#### Dry Run (Initial Cycle Setup):
- `time = 0`
- `pq = [3, 3]`
- `remain = []`
- `cycle = 2 + 1 = 3`

---

#### Step 6: Inner Loop to Process Tasks in the Current Cycle

```cpp
while (cycle && !pq.empty()) {
    int max_freq = pq.top();  // the task with the highest frequency
    pq.pop();
    if (max_freq > 1) {
        remain.push_back(max_freq - 1);  // add to remaining tasks with reduced frequency
    }
    ++time;  // increment time after processing one task
    --cycle;  // one cycle step is done
}
```
- Inside the cycle, we pop the most frequent task (`max_freq`) from the queue and process it.
- If the task still has remaining occurrences (`max_freq > 1`), we reduce its frequency and push it into the `remain` vector for future cycles.
- Increment `time` to account for the processing, and decrement `cycle` as one task has been processed.

#### Dry Run (First Cycle):
1. Pop `A` (frequency 3) from `pq`, so `pq = [3]`.
   - Decrease frequency of `A` to 2 and add it to `remain`.
   - `remain = [2]`
   - `time = 1`, `cycle = 2`

2. Pop `B` (frequency 3) from `pq`, so `pq = []`.
   - Decrease frequency of `B` to 2 and add it to `remain`.
   - `remain = [2, 2]`
   - `time = 2`, `cycle = 1`

3. The cycle is not yet complete, but `pq` is empty. So we increment `time` for the idle time.
   - `time = 3`, `cycle = 0`

---

#### Step 7: Push Remaining Tasks Back to Priority Queue

```cpp
for (int count : remain) {
    pq.push(count);  // reinsert remaining tasks into the queue
}
```
- After each cycle, reinsert the tasks from `remain` back into the priority queue.

#### Dry Run (After First Cycle):
- Push `remain = [2, 2]` back to `pq`, so `pq = [2, 2]`.

---

#### Step 8: Handle Idle Time (If Any)

```cpp
if (!pq.empty()) {
    time += cycle;  // add idle time if there are remaining tasks but cycle ended
}
```
- If there are still tasks left to process but the current cycle ended (i.e., `cycle > 0`), add the remaining idle time to `time`.
- In this case, we already added idle time in the previous step, so no extra time is added here.

---

#### Step 9: Repeat Steps for Next Cycles

The process repeats until all tasks have been processed. We continue processing tasks in cycles, pushing remaining tasks back into the priority queue until it's empty.

#### Dry Run (Second Cycle):
1. Initialize `remain = []` and `cycle = 3`.
2. Pop `A` (frequency 2), so `pq = [2]`.
   - Decrease frequency of `A` to 1 and add to `remain`.
   - `remain = [1]`, `time = 4`, `cycle = 2`

3. Pop `B` (frequency 2), so `pq = []`.
   - Decrease frequency of `B` to 1 and add to `remain`.
   - `remain = [1, 1]`, `time = 5`, `cycle = 1`

4. No more tasks in `pq`, so we account for idle time:
   - `time = 6`

5. Push `remain = [1, 1]` back to `pq`, so `pq = [1, 1]`.

---

#### Dry Run (Third Cycle):
1. Initialize `remain = []` and `cycle = 3`.
2. Pop `A` (frequency 1), so `pq = [1]`.
   - No need to add

 `A` to `remain` because it's completed.
   - `time = 7`, `cycle = 2`

3. Pop `B` (frequency 1), so `pq = []`.
   - No need to add `B` to `remain`.
   - `time = 8`, `cycle = 1`

4. No more tasks and no idle time needed.

---

### Final Output:

After all cycles are complete, the total time taken is:

- **Result = `8`**

So the CPU needs **8 cycles** to complete all tasks with the given cooling time `n = 2`.

