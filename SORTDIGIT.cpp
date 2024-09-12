Given a 10 digit number, sort the individual digits of the number.
#include <iostream>
#include <algorithm>  // for std::sort
#include <string>     // for std::to_string

int main() {
    long long num = 9876543210;  // 10-digit number
    string numStr = to_string(num);

    // Sort the digits in ascending order
    sort(numStr.begin(), numStr.end());

    // Convert back to number
    long long sortedNum = stoll(numStr);

    cout << "Sorted number: " << sortedNum << endl;
    return 0;
}
Explanation
Convert the number to a string using std::to_string().
Use std::sort() to sort the digits of the string.
Convert the sorted string back to a number using std::stoll().
Print the sorted number.
Time Complexity
Sorting a string of length 10 using std::sort() takes 

O(nlogn), where 

n is the number of digits (in this case 10).
So, the time complexity is 

O(10log10)=O(1), because the number of digits is constant.
Space Complexity
The space complexity is 

O(n), where 

n is the number of digits (10 in this case), so it is 

O(1) as well due to the constant number of digits.
Optimal Solution
The optimal solution leverages counting sort because we are only dealing with digits (0-9). Counting sort is linear for small integer ranges and works efficiently in this case.

Code
cpp
Copy code
#include <iostream>
#include <vector>

int main() {
    long long num = 9876543210;  // 10-digit number
    int count[10] = {0};  // To store count of digits from 0 to 9

    // Extract digits and count their frequency
    while (num > 0) {
        int digit = num % 10;
        count[digit]++;
        num /= 10;
    }

    // Reconstruct the number in sorted order
    long long sortedNum = 0;
    for (int i = 0; i <= 9; i++) {
        while (count[i] > 0) {
            sortedNum = sortedNum * 10 + i;
            count[i]--;
        }
    }

    std::cout << "Sorted number: " << sortedNum << std::endl;
    return 0;
}
Explanation
Create a count[10] array to store the frequency of each digit (0 to 9).
Extract digits from the number by repeatedly dividing by 10 and counting each digit.
Rebuild the sorted number by traversing the count array in increasing order and appending digits to the result.
Time Complexity
Extracting the digits takes 

n is the number of digits (10).
Constructing the sorted number also takes 

O(n).
Thus, the total time complexity is 

O(n), which in this case is 

O(10), i.e., constant time 

O(1).
Space Complexity
The space complexity is 

O(1) since we only use a fixed-size array of length 10.
Comparison
Brute Force: The time complexity is 

O(nlogn), and the space complexity is 

O(n).
Optimal: The time complexity is 

)
O(n), and the space complexity is 

O(1).
  We have the number 9876543210.
Extract the Digits:

First, we extract the digits from this number using modulus (%) and division (/).
Let's extract the digits one by one:

digit = 9876543210 % 10 = 0 (remainder when divided by 10)
number = 9876543210 / 10 = 987654321 (integer division)
Now the number is 987654321.

digit = 987654321 % 10 = 1
number = 987654321 / 10 = 98765432
Now the number is 98765432.

digit = 98765432 % 10 = 2
number = 98765432 / 10 = 9876543
Continue extracting until we get all digits:

yaml
Copy code
Digits extracted: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
Count the Frequency of Each Digit:

We will now count how many times each digit (from 0 to 9) appears in the number.
We use an array count[10] where each index corresponds to a digit (0 to 9), and we increment the count at that index when we encounter the corresponding digit.
Here's the frequency count for each digit:

Digit	Count
0	    1
1	    1
2	    1
3	    1
4    	1
5    	1
6    	1
7    	1
8    	1
9	    1
Since each digit appears exactly once, the count array looks like this:

css
Copy code
count[10] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
Rebuild the Number in Sorted Order:

Now, based on the counts, we rebuild the number by appending digits in ascending order.
We go through each digit from 0 to 9 and append it to the result as many times as its count.
Here’s the process:

For digit 0, count[0] = 1, so we append 0 once.
For digit 1, count[1] = 1, so we append 1 once.
For digit 2, count[2] = 1, so we append 2 once.
Continue this until 9:

java
Copy code
Sorted number (in digits): 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
So the final sorted number is:

bash
Copy code
Sorted number: 0123456789, which is 123456789.
