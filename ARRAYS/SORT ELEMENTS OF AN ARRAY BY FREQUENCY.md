https://takeuforward.org/data-structure/sort-elements-of-an-array-by-frequency/


https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card




```cpp

char getMaxOccuringChar(string str)
    {
        unordered_map<char,int>mp;
        for(char x: str){
            mp[x]++;
        }
        
        int maxFreq = 0;
        char maxFreqChar = '\0';
        
        for(const auto& entry : mp){
            if(entry.second > maxFreq || (entry.second == maxFreq and entry.first < maxFreqChar)){
                maxFreq = entry.second;
                maxFreqChar = entry.first;
            }
        }
        
        return maxFreqChar;
        
    }

```
