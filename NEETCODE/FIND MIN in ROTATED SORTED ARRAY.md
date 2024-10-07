dry run yourself: Take left=1 & right=INT_MAX

[ left + right ] itself will goes beyond integer range.

left + (right - left) / 2 = will always be in integer range.




 none of this makes sense. left + (right - left) // 2 != left + right // 2 theyre completely different numbers


One advantage of doing this instead is so you generally avoid integer overflow issues.


Using mid = left + (right - left) / 2 instead of mid = (left + right) / 2 prevents integer overflow. This is because adding two large numbers (left and right) can exceed the maximum value an integer can hold, causing an overflow. The alternative formula avoids this by ensuring the calculation stays within safe limits.


suppose the start and end both are (2^31)-1(which us the range of integer), if we add them it goes out of the integers range , thats why we use left +(right-left)/2;

