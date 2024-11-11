Program to find slope of a line
Last Updated : 17 Feb, 2023
Given two coordinates, find the slope of a straight line.

Examples: 

Input  : x1 = 4, y1 = 2, 
         x2 = 2, y2 = 5 
Output : Slope is -1.5
Approach: To calculate the slope of a line you need only two points from that line, (x1, y1) and (x2, y2). The equation used to calculate the slope from two points is: 

```cpp
// C++ program for slope of line 
#include <bits/stdc++.h> 
using namespace std; 

// function to find the slope of a straight line 
float slope(float x1, float y1, float x2, float y2) 
{ 
	if (x2 - x1 != 0) 
		return (y2 - y1) / (x2 - x1); 
	return INT_MAX; 
} 

// driver code to check the above function 
int main() 
{ 
	float x1 = 4, y1 = 2; 
	float x2 = 2, y2 = 5; 
	cout << "Slope is: " << slope(x1, y1, x2, y2); 
	return 0; 
}
```
