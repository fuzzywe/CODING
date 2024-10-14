https://leetcode.com/discuss/study-guide/1529866/solving-kth-kind-of-problems

List of Problems covered here : Last Update 14-04-2024
3116. Kth Smallest Amount With Single Denomination Combination
Hard
3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K Medium
Minimum Speed to Arrive on Time Medium
1986. Minimum Number of Work Sessions to Finish the Tasks
373. Find K Pairs with Smallest Sums Medium
378. Kth Smallest Element in a Sorted Matrix Medium
410. Split Array Largest Sum HARD
658. Find K Closest Elements Medium
668. Kth Smallest Number in Multiplication Table Hard
719. Find K-th Smallest Pair Distance Hard
786. K-th Smallest Prime Fraction Hard
878. Nth Magical Number HARD
875. Koko Eating Bananas Medium
1044. Longest Duplicate Substring HARD
1062. Longest Repeating Substring Medium
1231. Divide Chocolate HARD
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows Hard
1482 Minimum Number of Days to Make m Bouquets Medium
1918. Kth Smallest Subarray Sum Hard
2040. Kth Smallest Product of Two Sorted Arrays Hard
2141. Maximum Running Time of N Computers Hard
2187.Minimum Time to Complete Trips
2226. Maximum Candies Allocated to K Children
1970. Last Day Where You Can Still Cross
Minimize the Maximum Difference of Pairs


How to identify this kind of problem : Often it is mentioned in the problem itself like find the kth or nth of something. Another way to identify is problem asked for something largest or smallest, minimum of maximum or vice versa.


Often this problem can be solved used max-heap(for kth min problem) or min-heap(for k max problems).
But this technique involve maintaining heap with attributes to extra space and sometime due to large input one can get TLE with this approach.
Another way to solve this problem is Binary Search with Sliding Window technique which avoid maintaining priority queue and also faster.


Lets understand this with an example. Consider this problem.


378. Kth Smallest Element in a Sorted Matrix Medium


Priority Queue Approach:


Maintain a max heap.
Run nested loop for row and column.
If pq size < k , push
Otherwise if element is smaller than top, pop and push.
Return top element
Time Complexity = O(n^2 log k)
Space Complexity = O(k)


Binary Search Approach:
Note that row and column are all sorted.
That means matrix[0][0] is smallest and matrix[n-1][n-1] is largest.
These server as lower and upper bound of binary search, our answer lies somewhere in betweem.


        while(l < r){
            int mid = l + ((r-l)>>1);
            if(count(mid, matrix) >=k)
                r = mid;
            else
                l = mid +1;
        }
We are guessing an answer which is mid and then counting how many element are smaller than this guess in matrix.
Now the key point is how to count.
r = 0 to n , c = n-1, count 0.


Iterate for each row.
Inside the iterate loop, check keep decrement c until mat[r][c] > guess
When this while loop exit, that means those many c are smaller, add to count.
Why not reset c to n-1 before next iteration: because we know all column are also sorted.
      for(; r < n ; ++r){
            while(c >=0 and matrix[r][c] > t)
                --c;
            count += (c+1);// why +1 because 0-index will be 1 less.
        }
Time Complexity: remember binary search bound , so O( log (max-min) * n )
Why n for each bsearch ? because maximum number of column less than guess could be c


Step by Step exlnataion of Binary Search approach:


1	2	3
4	5	6
7	8	9
lo = 1 , hi = 9 and k=5
Iter 1: mid = 5 (guess)
count:


r=0 , c= 2, since mat[0][2] smaller while loop wont run and we add count += c+1 count =3 and by looking we know 3 elements are smaller then our guess of 5
r=1, c = 2, while loop stop at c=1 and we add c+1 and we see 4 & 5 are lesser than guess.
r=2, c= 1, loop exit at c=-1 and hence we add nothing c+1 =0 so total we have 5
Iter 2: since 5 >=k , hi =5 , now mid (guess) = 3
And we keep doing until lo < hi finally print answer as lo=5
The Template.


Look what problem is asking for and establish lower and upper bound for it.
Try to figure out count function.
Make a guess which is (lo + hi+1)/2.
See if this guess passes the count function , if yes then go in right half with low = mid as this is best answer if we cant find anything in right half. Otherwise go in left hard with right = mid -1, why mid-1 because we know mid already failed the test. This get reversed if problem is asking for minimum.
In the end return lo.
Point to remember:


If the problem is asking for maximum and the current guess passes the count function you have to look further in right half, here lo = mid , here mid is calculated as (lo + hi + 1)/2
If problem asking for minimum you have and current guess passes right = mid. Here mid is calculated as (lo + hi)/2
In all below HARD problem you can notice we will do just this 2 thing and problem is solved.
Building intution of what a count function wuld be require come practice but if you solved multiple problem you know what we are loooking for.


Time Complexity O(log(width_of_binary_search) * O(count))


668. Kth Smallest Number in Multiplication Table Hard
Exact same as above , some minor tweak on establishing lower/upper bound and what to start with in count function.


719. Find K-th Smallest Pair Distance Hard
Exact same procedure.
Sort the input and find the upper and lower bound, why sort because it asking for any pair, sort gives us bound since smaller distance can be 0
and maximum wuld be nums[n-1] - nums[0]
How to count: use sliding window
For each index see how much you can go on right side until the distance <= guess
count will be (r -l ), these many pairs.


Example:
[1,2,3,4,5] k =3
lo =0, hi = 5-1= 4 (distance)
Iter :1 Guess distance be as 2
Count how many pair has distance less than 2
Start with left = 1 and extend on right side (inner while loop of count function) so there are 2 pair [1,2] & [1,3] count =2
left = 2 we get [2,3] & [2,4] = 2 and total count = 4
left = 3 also 2 of them , count = 6
left = 4 1 pair of [4,5] count = 7
since count >= guess of 4 , hi = 4, lo =0


Similar repeat and we get l = 1 ([1,2] , [2,3], [3,4] , [4,5] ....) There are 4 pair with distance of 1 and we are asking k =3
1986. Minimum Number of Work Sessions to Finish the Tasks Medium


Establish Bound:
Worst case each task require a separate session , for example if we have 5 task and each is 10 and maxsessionTime is 10 , then we need 5 session , this worst case.
Best case is 1 session in which we can pack all the task.
Hence lo =1 and hi = tasks.size()


Now make a guess and see if its possible to pack all the tasks or not. A bit tricky to write this helper function.
Approach:
Create guess number of bucket.Initially each bucket is empty.
Fill a task in the bucket and increase the bucket capacity as now bucket is holding this task.
Try to fill another task.
If we are ablt o fill all the bucket , return true.
If not try to fill this task into another bucket.


	   class Solution {
    bool isPossible(int idx, int sessionTime, vector<int>&tasks, vector<int>& buckets){
        
        // All tasks are properly fit into given buckets
        if(idx== tasks.size())
            return true;
        
        // Lets fill the idx task into one of bucket if possible
        for(int i =0; i < buckets.size(); ++i){
            // see if bucket has capacity to hold this task ?
            if(buckets[i] + tasks[idx] <= sessionTime){
                buckets[i] += tasks[idx];
                bool ret = isPossible(idx+1, sessionTime, tasks, buckets);
                if(ret)
                    return ret;
                buckets[i] -= tasks[idx];
                // If we dont true and also this bucket is not used up
                // by other tasks , that means surely we are not going to get answer, so fail early and return false.
                if(buckets[i]==0)
                    return false;
            }
        }
        return false;
    }
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        sort(tasks.rbegin(), tasks.rend());
        int lo =1;
        int hi = tasks.size();
        while(lo < hi){
            int mid = (lo + hi)/2;
            vector<int> buckets(mid, 0);
            if(isPossible(0, sessionTime, tasks, buckets))
                hi = mid;
            else
                lo = mid +1;
        }
        return lo;
    }
};

1918. Kth Smallest Subarray Sum Hard
here we have find the subarray sum whose sum is kth smallest, note the subarray can be of size 1.
Step 1:
lower bound set as 0 (this is arbitarily chosen)
upper bound would sum of all element in array.
Our answer lies in between this.
Step 2:
Count routine: use sliding window, remember there are problem count how many subarray whose sum is give.


int count(int t, vector<int>& nums){
        int left = 0;
        int n = nums.size();
        int sum =0;
        int count =0;
        for(int right =0; right < n ; ++right){
            sum += nums[right];
            while(sum > t){
                sum -= nums[left++];
            }
            count += right - left +1; //This trick count all subarray between indcies , for example array is [1,2] we know there are 3 subarray [1] [2] [1,2]
                                      // first time right = 0, left =0 , count =1
                                      // 2nd time right =1 left =0 , count **+=** (1-0 +1) = 3
        }
        return count;
    }
1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows Hard
Similar process.
Step 1 : Establish bounds, here set lo =0 and hi = (rows * 5000 ) + 1; see the problem statements, each number in row can be maximum 5000, so upper bound would be this.


Step 2: How to count is the key here
Establish a guess (lo + hi ) /2.
Now for each row scan the column and recursively go to next higher row.
We have to do some clever pruning to bring down runtime.
Prune 1: if cumultaive sum > guess , no point going ahead return.
Prune 2: while processing column if sum is more than guess, so point going forwarding , break and return.
Prune 3: If subtree return 0 that also means no need to go further, break and return whatever acculuated.
Prune 4: we are basically counting , if count > k anytime , there isnt any need to go further , break and return
This is one key difference from earlier approach where we are doing full counting and here the moment we get count > k , break and return


    int count(int guess, vector<vector<int>>& mat, int r, int sum){
        if(sum > guess) // if the sum is greater than guess no point , prune and return 0
            return 0;
        if(r==m)
        {
            if(sum > guess)
                return 0;
            return 1;
        }
        int ret =0;
        for(int c =0; c < n ; ++c){
            if(sum + mat[r][c] > guess)
                break;
            int  y = count(guess, mat, r+1, sum+mat[r][c]);
            if(y==0)// if we get 0 from sub tree break 
                break;
            ret += y;
            if(ret>k) // if total count > k , no need break as we achieved what we are looking for hi=guess
                break;
        }
        return ret;
    }
658. Find K Closest Elements Medium
Since this is k-pairs problem , we should use heap way.
But another technique is to use binary search way.
First find the index closest to x.
Then create a window left = index -1 and right = index
expand the window which ever absolute value is lesser i.e. if abs(arr[left] -x <= abs(arr[right]-x)
expand left else expand right
element lies in [left+1, right-1] so until right -left -1 !=k
and then use elements from [left+1, right-1] in ans


vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left =0;
        int right = n-1;
        while(left < right){
            int mid = left + ((right-left)>>1);
            if(arr[mid]>=x)
                right = mid;
            else
                left = mid + 1;
        }
        left = left -1;
        right = left +1;
        while((right - left-1 ) != k){
            if(left <0)
            {
                right++;
                continue;
            }
            if(right==n){
                --left;
                continue;
            }
            if(abs(arr[left]-x) <= abs(arr[right]-x))
                --left;
            else
                ++right;
        }
        vector<int> res;
        for(int i = left+1 ;i <right; ++i)
            res.push_back(arr[i]);
        return res;
    }
373. Find K Pairs with Smallest Sums Medium
Although it is possible to solve this using binary search approach but since we have to find all k-pairs, in my experince it is better to use
priority queue approach here.
Put first k-element with nums1 and nums2 index min-heap.
while(k--)
pop out top element
this is surely an answer since its minimum ,
so add a new entry with nums2 index+1 if possible else skip.
Time complexity = K Log(K)
Space = O(K)
Binary Search Approach
Good Question: Since this is different from regular patter of finding 'kth' or maximum or minimum.
Example input from the question
nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Lets follow the template
Step 1: Establish bounds
What could be lower bound and upper bound ? lowest element of both array and highest element of both array.
lo = 3
hi = 17


Step 2: The count function would be given an sum value (guess ) how many sub array is less than this number.
This function can be simply implemented as O(n^2) but this can be optimized also.


Step 3: Make a guess and pass this guess in count function , see if get return >=k , if yes hi = mid else lo = mid +1
Why because if we found subarray >=k that means there exists a even smaller sum which cna give us >= k count. so lets see in left half.


Example Walk through
lo = 3, hi = 17 , mid = 10, Count function will give 4 >=3 , that means there can exists an even smaller sum
lo = 3 , hi = 10, mid = 6 , count will give 2 ( [1, 2], [1, 4] only ) , so we have to go right half
lo = 7 , hi = 10 , mid = 8, count will give 3 , this time go left as 3 >=k
lo = 7, hi = 8 , mid = 7, count will give 3 but after assign hi = mid loop will exit since 7 < 7
So now we know if sum <= 7 , we will get 3 sub array.


After that just run loop and loop until k sub array is reached.


Time complexity : O(log(N) * O(count_function) )
where N = max_sum - min_sum
Count_function time compelxity can be worst O(n^2) but we can again use binary search to make it even better like O( n. log n)


2040. Kth Smallest Product of Two Sorted Arrays Hard
Reference : vortubac solution https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/discuss/1527753/Binary-Search-and-Two-Pointers


Here array is sorted but is also can contain -ve values and we have to find kth minimum product.
Consider a simple case suppose
A= [-5] B=[10, 11]
And we have to find 1st minimum , all product are [-50, -55] , and we know 1st mimimum is -55 which smaller than -50. Had we reverse the array and then multiplied and pick the 1st minimum that correctly gives us -55.
That is the key idead of maintaining reverse of each array.
If you are asked to get 2nd minimum from producte of this 2 array [2,3,4,5] * [1] u pick 3
But if you are asked to pick 2nd minimum [-5, -4, -3, -2] * [-1] , we cant pick 4 as that is wrong anwer.had we reverse and then picked 2nd element from result , we get correct answer of 3. Thats why reverse !


So in order to deal with kth product when array is mix of positive and negative. We have to deal differently.
First bifurcate array into positive and negative sub array. So we get 4 new sub array.
Also for each array create a reverse array of them.


Step 1 : As always establish bounds, here [-1e9, 1e9]
Now when we get guess = (lo + hi)/ 2
If this guess is a +ve number:


Multiply -ve array of rev(A1) & -ve array of rev(A2) and counting how many <= guess
Multiply +ve array of A1 & +ve array of A2 and counting how many <= guess
-ve of A1 and +ve of A2 + +ve of A1 and -ve of A2 will also be <guess as they will -ve always.
If guess is < ve


Multiply +ve array of rev(A1) & -ve array of A2 and counting how many <= guess
Multiply -ve array of A1 & +ve array of rev(A2) and counting how many <= guess
class Solution {
    long long count(vector<int>& A, vector<int>& B, long long guess){
        int p1 = 0;
        int p2 = B.size()-1;
        long long cnt =0;
        while(p1 < A.size()){
            while(p2>=0 and (long long)A[p1]*B[p2] >guess)
                --p2;
            cnt += (p2+1);
            ++p1;
        }
        return cnt;
    }
public:
    long long kthSmallestProduct(vector<int>& n1, vector<int>& n2, long long k) {
        // @vortubac solution  seems simpler to understand
        // Bifurcate the array in only positive and only negative parts
        auto it = lower_bound(n1.begin(), n1.end(), 0); // finding iterator of 0 or positive  nunber
        vector<int> neg1 (begin(n1), it);
        vector<int> pos1 (it, end(n1));
        it = lower_bound(n2.begin(), n2.end(), 0); // finding iterator of 0 or positive  nunber
        vector<int> neg2 (begin(n2), it);
        vector<int> pos2 (it, end(n2));
        
        //  Also keep a reverse copy of each of the array
        // reason being if arrays are -ve kth element is actually n-k , to avoid that
        // reverse it and still work on k
        vector<int> neg1_r(rbegin(neg1), rend(neg1));
        vector<int> neg2_r(rbegin(neg2), rend(neg2));
        vector<int> pos1_r(rbegin(pos1), rend(pos1));
        vector<int> pos2_r(rbegin(pos2), rend(pos2));
        
        // Bound establishment
        long long lo = -10000000000;long long hi = 10000000000;
        while(lo<hi){
            long long guess = lo + ((hi-lo)>>1);
            long long cnt;
            if(guess >=0)
                /*
                - Multiply -ve array of A1 & -ve array of A2  and counting how many <= guess
                - Multiply +ve array of A1 & +ve array of A2  and counting how many <= guess
                - -ve of A1 and +ve of A2 + +ve of A1 and -ve of A2 will also be <guess as they will -ve always.
                */
                cnt = count(pos1, pos2, guess) + count(neg1_r, neg2_r, guess)
                                + neg1.size() * pos2.size() + neg2.size() * pos1.size();

            else
                cnt = count(pos1_r, neg2, guess) + count(neg1, pos2_r, guess);
            if(cnt >= k)
                hi = guess;
            else
                lo = guess +1;
                
        }
        return lo;
    }
};
786. K-th Smallest Prime Fraction Hard
This problem involved floating point and we know answer lies between 0 and 1.
Step 1: For these question set lower bound is 0 and upper bound is 1 and run loop until hi-lo > 1e-9 whatever fine precision is needed.
Step 2 : count routine and we also need to find the indices of answer to return.
Tip 1: to find whether x/y < guess , do x < y * guess
Tip 2: since we have to also store the number to return , check if new ratio is > old one if yes save that coz if have to return kth and this can be answer.


// Return count and pair of i,j index
    pair<int, pair<int, int>> count(double t, vector<int>& arr){
        int i =-1;
        int count = 0;
        int numer=-1;
        int denom=-1;
        for(int j = 1; j < n ; ++j){
            while(i<n-1 and i < j-1 and arr[i+1] < arr[j] * t)
                ++i;       
            count += i+1;
            // Now since we have to return the index also
            // store the greatest
            
            if(i >=0 and ((numer==-1) or arr[numer] * arr[j] < arr[denom] * arr[i]))
            {
                numer = i;
                denom = j;
            }
        }
        return make_pair(count, make_pair(numer, denom));
    }
1231. Divide Chocolate HARD


class Solution {
    int count(vector<int>& a, int k){
        int c =0;  // count
        int s =0;  // total sweetness
        for(int i : a){
             s += i;
            if(s>=k){
                ++c;
                s =0;
            }
           
        }
        return c;
    }
public:
    int maximizeSweetness(vector<int>& s, int k) {
        ++k;
        int lo = *min_element(s.begin(), s.end());
        int hi = accumulate(s.begin(), s.end(), 0);
        while(lo<hi){
            int mid =  (lo + hi +1 )/2;
            // now see how many pieces can be formed if i get this mid sweetness
            if(count(s, mid) >=k)
                lo = mid;
            else
                hi = mid-1;
        }
        return lo;
    }
};
410. Split Array Largest Sum HARD


Lower bound could be just 1 largest element and upper bound would be all element, answer would be somwhere in between.
Count will be all sub-array less than guess, if anytime we hit this condition break and count again.
For example suppose guess is 5 and elements of array are
1, 2, 3, 4, 5
We start summing from left 1+2 + 3 here 6 >5 so [1,2] will be 1 subarray whose sum is < 5
next subarray start with sum 3, again 3+4 > 7 so [3] , similarly [4] , [5].
So we have 4 of them [1, 2] [3] [4] [5]


class Solution {
    bool isPossible(vector<int>&a, int guess, int m){
        int sum =0;
        int count =1; //counting the last subarray
        for(int i : a){
            sum += i;
            if(sum > guess){ // largest subarray can be max sum 'guess'
                sum = i;
                ++count;
                if(count > m) // we want to divide in exact k part
                    return false;
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end()); // minimum ..subarray can be largest single element
        int right = accumulate(nums.begin(), nums.end(), 0); // or it can be everything ,answer lies in between
        while(left<right){
            int mid = left + ((right -left)>>1);
            if(isPossible(nums,mid, m))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
        
    }
};
878. Nth Magical Number HARD


In this problem we have to find the kth magical number which is divisbile by both a and b.
Suppose x = 25, n1 = 3, n2 = 4, then x/n1 = 8 (3, 6, 9, 12,15,18,21,24) and x/n2 = 6 (4, 8, 12,16,20,24), so there are total 8+6 = 14. But wait we have 12 and 24 double counted , how will you subtract both . Just take LCM of 3,4 and divide by x so 25/12 =2
So total 12 number.


set lower bound as min(a, b), higher bound is n* min(a, b)
and do binary search , note that here count function is constant time since all you have to do is mid/a + mid /b - mid / LCM(a,b)
LCM can be derived from GCD (gcc inbuilt function)


class Solution {
    const long mod =1e9+7;
public:
    int nthMagicalNumber(int n, int a, int b) {
        long lcm = (a*b) / __gcd(a, b);
        long lo = min(a, b);
        long hi = n* lo;
        long A = a;
        long B = b;
        while(lo<hi){
            // what is that number ?
            long mid = lo + ((hi-lo)>>1);
            int count = (mid/A) + (mid/B) - (mid/lcm); // key of the prolem
            if(count >= n)
                hi = mid;
            else
                lo = mid+1;
        }
        return (int)(lo%mod);
    }
};
1062. Longest Repeating Substring Medium


This problem can be thought of kth problem.
First lets investigate bounds.
lower bound = 0 , when no substring is repeated
higher bound = n-1, when string has same letter for example aaaaa , here string length is 5 but maximum length of repeated substring is aaaa which repeated twice.


Lets make a guess of substring size and then see whether any substring exists?
guess function here taken O(n^2) time because of substr function. Overall time complexity is O(n^2 log(n)).
This can be further optimized using Rolling Hash mechanism of substring, See next problem


class Solution {
    // Does any substring of size 'len' 
    bool count(string&s, int len){
        unordered_set<string> str;
        for(int i =0; i < s.size() - len +1; ++i){
            string k = s.substr(i, len);
            if(str.find(k)==str.end())
                str.insert(k);
            else
                return true;
        }
        return false;
    }
public:
    int longestRepeatingSubstring(string s) {
        int n = s.size();
        int lo = 0; // worst case is 0, there wont be any substring which get repeated.
        int hi = n-1;// best case is n-1 because if all chars are same n-1 size substring repated twice.
        while(lo<hi){
            int mid = lo + ((hi-lo +1)>>1);
            if(count(s, mid))
                lo = mid ;//  this is our current best lets try to find more;
            else
                hi = mid -1;
        }
        return lo;
    }
};
1044. Longest Duplicate Substring HARD


Exact same as above but since bounds are tight you have to use rolling hash way in count function.


class Solution {
    string getDupString(string& s , int l){
        int start = 0;
        // First calculate the hash starting from index 'start'
        // ax^2 + bx + c , we are starting from c
        long long pow =1;
        long long mod = 1e9+7;
        long long p = 31;
        long long chash =0;
        for(int i = l-1; i >=0; --i){
            chash = (chash + ((s[i]-'a' + 1) * pow))%mod;
            if(i>0)
                pow = (pow*p)%mod;
        }
        unordered_map<long long, vector<int>> m; // hash to set of all index start in 's'
        m[chash].push_back(0);
        ++start;
        while((start+l-1) < s.size()){
            long long remove = (pow * (s[start-1]-'a'+1))%mod;
            chash = (chash - remove + mod)%mod;
            chash = (chash * p)%mod;
            chash = (chash + ( (s[start+l-1]-'a' + 1) ))%mod;
            auto it = m.find(chash);
            if(it!=m.end())
            {
                // string starting a index start
                string start_sub = s.substr(start, l);
                for(int i : it->second){
                    string candidate = s.substr(i, l);
                    if(start_sub==candidate)
                        return candidate;
                }
            }
            m[chash].push_back(start);
            ++start;
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int l = 1;
        int h = s.size();
        string ans="";
        while(l<=h){
            int mid = l + ((h-l)>>1);
            string t = getDupString(s, mid);
            if(t!="")
            {
                ans = t;
                l = mid+1;
            }
            else
                h = mid-1;
        }
        return ans;
    }
};
2141. Maximum Running Time of N Computers Hard


Set bounds lo =0; high = sum of all battery capacity.
Make a guess of battery capacity.
See if all the battery operating at this 'guess' capacity , will we be able complete N computer ? If yes we need to try a better battery capapcity in right half.
Note : Since here we are using lo = mid , we have to use (lo + high + 1)/2 logic to escape from infinite loop.


class Solution {
    bool possible(long long b, int n, vector<int>& B){
        long long expected = b*n; // b battery and we have n computer
        long long actual =0;
        for(int& i  : B)
		  // We want to operate ech battery at 'b' capcity, so take minimum
		  // lets say a battery is 5 , and b value is 2, that means we want to take 2 
		  // another example is battery is 1 and b value is 2 , take 1 since 1 is max battery can offier.
            actual += min((long long)i, b);
        return actual >=expected;     
    }
public:
    long long maxRunTime(int n, vector<int>& B) {
        long long lo = 0;
        long long hi = 0;
        for(int& i : B)
            hi += i;
       
        while(lo < hi){
            long long guess =  lo + ((hi-lo+1)>>1);
            // Is it possible to run n computer with 'guess' battery value ?
            if(possible(guess,  n, B))
                lo = guess;
            else
                hi = guess -1;    
        }
        return lo;
    }
};
875. Koko Eating Bananas


Lower bound would be 1 and higher bound would be max element
Count how many hours it would take to all banana.
If it is possible i.e. <=h , then further hi = mid, means we can further reduce the search space otherwise lo =mid+1 and search in right half.
class Solution {
    bool count(vector<int>& p, int k, int h){
        int count = 0;
        for(int& i : p){
            count += i/k;
            if(i%k)
                ++count;
        }
        return count <=h ;
    }
public:
    int minEatingSpeed(vector<int>& p, int h) {
        //sort(p.begin(), p.end());
        int lo = 1;
        int hi = *max_element(p.begin(), p.end());
        while(lo < hi){
            int mid = lo +((hi-lo)>>1);
            if(count(p, mid, h))
                hi = mid;
            else
                lo = mid +1;
        }
        return lo;
    }
};
2187 : Minimum Time to Complete Trips
Same as earlier problem, just check the bound
lower bound given is 1 but what would be higher bound
totalTrips is 10^7 , slowest bus i.e. whose time is higest wil contribute least hi = max(time) * 10^7
maximum time is given also upper bound as 10^7 and hence hi = 10^14.
After that its straigh forward, just make sure to use long long


class Solution {
    long long count(long long guess, vector<int>& t ){
        long long  total = 0; 
        for(auto i : t){
            long long val = i;
            total += (guess / val) ;
        }
        return total;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long lo = 1;
        long long hi = 1e14;
     
        while(lo < hi){
            long long mid = lo + ((hi-lo)>>1);
            if(count(mid, time) < totalTrips)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
2226 Maximum Candies Allocated to K Children
lower bound would be 1
higher bound would be max element in piles.
Next make a guess and see if you can create piles >=k ?
How do you create piles, divide the piles candies by guess and thats all.


class Solution {
    bool isPossible(long long guess, vector<int>& candies, long long k){
        long long count =0;
        for(int i : candies)
        {
            count += (i/guess);
        }
        return count >=k;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if(sum < k)
            return 0;
        long long lo =1;
        long long hi = *max_element(candies.begin(), candies.end());
        while(lo < hi){
            long long mid = ((lo + hi +1) >>1);
            if(isPossible(mid, candies, k))
                lo = mid;
            else
                hi = mid -1;
        }
        return lo;
    }
};
Last Day Where You Can Still Cross
Best case we cross on last day i.e. m * n grid size
Worst case will be 0
Our answer would lie somewhere in between, so we can use binary search.
These will be our bound and our guess functions would be , all nodes before kth day , mark as water and then do BFS/DFS.
Time complexity of BFS would be n^2 and binary search would be log n^2 (assuming n* n grid size)


Minimize the Maximum Difference of Pairs


The Key idea is to binary search on the input limit i.e. 0 to 10** 9
We make a guess of maximum diff and see if we can find those many pair ?
If Yes that is one possible answer we try to minimimze this by searching on left half.
otherwise right half.


class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)
            return 0;
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1e9;
        auto isValid=[&](int threshold){
            int count =0;
            int i =0;
            while( i < nums.size()-1){
                if(nums[i+1]-nums[i] <= threshold){
                    i+=2;
                    count++;
                }
                else{
                    ++i;
                }
                if(count >=p)
                    return true;
            }
            return false;
        };
        while(l < r){
            int mid = l + ((r-l)>>1);
            if(isValid(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
3116. Kth Smallest Amount With Single Denomination Combination Hard
Lets solve for just 1 coins
Suppose we have coin =2 and we have to find 7th smalest amount.
For 1 coin its simple 2, 4, 6, 8, 10, 12, 14 , 14 is what we can make which is 7th multiple.


Now lets add another coin of 5 , now the 7th smallest amount which we can make would be , merge the multiple of 2 and 5 and find the 7th smallest
2: 2, 4, 6, 8, 10, 12, 14
5: 5, 10, 15
After merging and ascending : 2, 4, 5, 6, 8, 10, 12, 14
Note that 10 is common in both but we counted once (this is key to the problem to avoid counting again) , now the 7th largest is 12.
Notice that there can be maximum 15 coins
Inclusion-Exclusion Principle:


So what we will do is create power set of a set: Power set is all possible combination of elements , for example suppose we have 3 elements {1,2,3} , its power set would be {1}, {2}, {3} , {1, 2}, {2, 3} , {1, 3} , {1,2,3} and empty set.
The outer for loop is iterating all the power set 1, 10, 11, 100, 101, 110, 111 in binary.
Next you want to see which coins can be included in this power set.
For example suppose we say 11 , that we bit 0 and bit 1 is set , which means coin 0 and coin are participants of this subset.
So once you know who are participants of subset , take there LCM (which we are doing 1 by 1 meaning first take LCM of (1, coin[0]) , then remember this value and then take LCM of (LCM(1, coin[0]), coin[1])
Why we are doing LCM,
Lets understand with an example
Multiple of 3 : 3, 6, 9, 12
Multiple of 6 : 6, 12
As per below code for n =12,
When we have only coins 3, we count 4 [3, 4,6 12] . total = 4
When we have only coins 6, we count 2 [6, 12] . total = 6
As you see we have counted 6 and 12 twice
So how do we get rid of duplicates? here is where LCM helps
We we have two coins [3, 6] , we have LCM of these which would be 6 and 12 / 6 = 12 , even cardinality(count ) of set (check wikipedia page). so we subtract from answer and hence we get required answer of 4.


class Solution {
    bool guess(long long n, int k, vector<int>& coins){
        int m = coins.size();
        // (total power set  of m (3) , 1, 10, 11, 100, 101, 110, 111)
        // what all coins are selected
        int s = 1 << m;
        long long total  = 0;
        
        // iterate all the combination of coins
        for(int i = 1; i < s; ++i){
            long long l = 1;
            long long count = 0;
            for(int j =0 ; j < m ; ++j){
                // We are trying to find out what all numbers are to be used
                // in this combination
                // for example i =3 (11) , that means bit 0 and bit 1 
                // that means coin 0 and coin 1 to be used , check there lcm
                if( i & (1<<j)){
                    l = lcm (l, coins[j]);
                    count++; // count how many element in sub-set
                } 
            }
            // if the set contains even number of elements we have remove
            // else add  from inclusion/exclusion principle
            if(count & 1){
                total += (n / l);
            }
            else{
                total -= (n / l);
            }
        }
        return total >=k;
    }
public:
    long long findKthSmallest(vector<int>& coins, int k) {
       long long left = 1;
       long long right = 1e11;
       while( left < right ){
           long long mid  = left + ((right-left) >> 1);
           if(guess(mid, k, coins)){
            right = mid;
           }
           else{
            left = mid + 1;
           }
       }
       return left;
    }
};
3007. Maximum Number That Sum of the Prices Is Less Than or Equal to K Medium


Lets write decimal number from o to 7 in binary form an identify a pattern in each column.


2	1	0
0	0	0
0	0	1
0	1	0
0	1	1
1	0	0
1	0	1
1	1	0
1	1	1
Notice each column a pattern of 0 1 occurs , for ith column group size is 2^i and # of 0 and # 1 is 2^i-1 each.
Now there can be some left which are not integral multiple of their group size. For example if group size is 2(we are checking 1st column ) and number is 6 (110) , their is 1 complete group(0011) in column 1st column and then we have 001 left , out of this their is 1 set bit, how to determine this ?
As we know half bits in group is 0 and half is 1, and 0 bits comes first, we can do
(n % group) - (1LL<<(i-1)
Here n is 6 (but become we are counting from 0 , we should do n++) so now n is 7, group size is 4
7%4 = 3 and we have seen we have 3 bits left in 1st column 001.
Out of this 3 bits first half (1 << i-1) , where is columnm and its 2 so, we have 1 << 1 which is 2, and we can see first 2 are 0 in 001, remainder left is 1s, and thats how the above equation works.


class Solution {
    bool guess(long long n, long long k, int x){
        // how many bits this number would have ?
        long long bits = log2(n) + 1; // 8 is 4 bit number 
        long long count  = 0;
        n++;
        // Now we have to jump every x , 2x column 
        // and find out how many bits are set in that xth col
        for(long long i= x; i <= bits; i += x){
            long long group = 1LL << i;
            // half of them would be 1 i.e. 1 << (i-1)
            // this many integral and ech hai 2^i-1 1s
            count += (n / group ) * (1LL << (i-1)); 
            // remainder for example group is 4 size, half (2) of them would be 1
            // and we have just 1 remainder left 
            count += max(0LL, (n % group) - (1LL<<(i-1)));
        }
        return count <= k;
    }
public:
    long long findMaximumNumber(long long k, int x) {
        
        long long left = 1;
        long long right = 1e15;
        long long ans;
        while(left < right){
            long long mid = (left + right +1) >> 1;
            if(guess(mid, k, x)){
                left = mid;
            }
            else{
                right = mid -1;
            }
        }
        return left;
    }
};
1552. Magnetic Force Between Two Balls


class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int left =0;
        int right =  position[n-1];
        auto count = [&](const int guess){
            int curr =position[0];
            int ans = 1; //first ball we put at position[0]
            for(int i =1; i <n ; ++i){
                if(curr + guess <= position[i]){// we can place
                    ans++;
                    curr = position[i];
                }
            }
            return ans;
        };
        while(left <  right){
            int mid = left + ((right-left+1) >> 1); // this is the force
            if(count(mid) >=m) // can we fit all the m balls with this gapping 
            {
                left = mid;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
};
