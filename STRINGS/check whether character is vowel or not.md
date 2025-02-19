```cpp

#include<iostream>
using namespace std;

// single function for both uppercase and lowercase
bool isVowel(int c){
    // converts to uppercase if it wasn't already
    c = toupper(c);
    
    // returns true if char matches any of below
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main() {
    char c;
    
    cout << "Enter an alphabet: "; cin >> c;

    // show error message if c is not an alphabet
    if (!isalpha(c))
      printf("Non alphabet");
      
    else if (isVowel(c))
        cout << c << " is a vowel";
        
    else
        cout << c << " is a consonant";

    return 0;
}
Output
Enter an alphabet: e
e is a vowel
								
				
				
				

				

																
															
															



```


---

// C++ Program to check whether alphabet is vowel or consonant
#include<iostream>
using namespace std;

// main function
int main()
{
    char c;

    c='U';
        
    //checking for vowels	
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
    c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
    {
        cout << c << " is a vowel";  //condition true input is vowel
    }
    else
    {
        cout << c << " is a consonant";  //condition false input is consonant
    }

    return 0;
}



					
			
						
				
									
```
