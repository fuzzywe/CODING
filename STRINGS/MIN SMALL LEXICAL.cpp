#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum occurring character in
// an input string which is lexicographically first
char getMinOccurringChar(char str[]) 
{
    // Frequency array for lowercase characters (a-z)
    int freq[26] = {0};

    // Length of the input string
    int len = strlen(str);

    // Populate the frequency array with counts of each character
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') { // only consider lowercase alphabet
            freq[str[i] - 'a']++;
        }
    }

    // Initialize the minimum frequency and the result character
    int minFreq = INT_MAX;
    char result = '\0';

    // Find the lexicographically smallest character with the minimum frequency
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0 && freq[i] < minFreq) {
            minFreq = freq[i];
            result = (char)(i + 'a');
        }
    }

    // Return the minimum occurring character
    return result;
}

// Driver Code
int main()
{
    char str[] = "sample program";
    cout << "Minimum occurring character = "
         << getMinOccurringChar(str) << endl;
    return 0;
}
