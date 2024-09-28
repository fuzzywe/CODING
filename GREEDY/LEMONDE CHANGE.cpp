Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Function to find whether each customer can 
// be provided with correct change
bool lemonadeChange(vector<int>& bills) {
    
    // Initialize a counter
    // for $5 bills
    int five = 0; 
    
    // Initialize a counter
    // for $10 bills
    int ten = 0;   
    
    // Iterate through each customer's bill
    for(int i = 0; i < bills.size(); i++){
        
        // If the customer's
        // bill is $5
        if(bills[i] == 5){
            
            // Increment the
            // count of $5 bills
            five++;  
        }
        
        // If the customer's
        // bill is $10
        else if(bills[i] == 10){
            
            // Check if there are $5
            // bills available to give change
            if(five){
                 // Use one $5 bill
                 // to give change
                five--; 
                // Receive one $10 bill
                ten++;   
            }
            
            // If no $5 bill
            // available, return false
            else return false;  
        }
        
        // If the customer's
        // bill is $20
        else {
            // Check if there are both
            // $5 and $10 bills
            // available to give change
            if(five && ten){
                 // Use one $5 bill
                five--; 
                // Use one $10 bill
                ten--;   
            }
            // If there are not enough $10 bills,
            // check if there are at least
            // three $5 bills available
            else if (five >= 3){
                // Use three $5 bills
                // to give change
                five -= 3;  
            }
            // If unable to give
            // change, return false
            else return false;  
        }
    }
    
    // Return true if all customers
    // are served with correct change
    return true;  
}


int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queues of customers: ";
    for(int bill : bills){
        cout << bill << " ";
    }
    cout << endl;
    bool ans = lemonadeChange(bills);
    if(ans)
        cout << "It is possible to provide change for all customers." << endl;
    else
        cout << "It is not possible to provide change for all customers." << endl;
    return 0;
}
                            
                        
Output Queues of customers: 5 5 5 10 20

It is possible to provide change for all customers.

Complexity Analysis

Time Complexity: O(N) where N is the number of people in queue/ bills we will deal with. We iterate through each customer’s bills exactly once. The loop runs for N iterations and at each iteration the operations performed are constant time.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.