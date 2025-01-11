```cpp

// 1. Implementation of Stack in C++
#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;
public:
    void push(int value) {
        elements.push_back(value);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_back();
        } else {
            cout << "Stack is empty, cannot pop." << endl;
        }
    }

    int top() {
        if (!elements.empty()) {
            return elements.back();
        } else {
            cout << "Stack is empty." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return elements.empty();
    }
};

// 2. Implementation of Queue in C++
#include <queue>
class Queue {
private:
    queue<int> elements;
public:
    void enqueue(int value) {
        elements.push(value);
    }

    void dequeue() {
        if (!elements.empty()) {
            elements.pop();
        } else {
            cout << "Queue is empty, cannot dequeue." << endl;
        }
    }

    int front() {
        if (!elements.empty()) {
            return elements.front();
        } else {
            cout << "Queue is empty." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return elements.empty();
    }
};

// 3. Implementation of Shopping Cart in C++
#include <map>
#include <string>
class ShoppingCart {
private:
    map<string, int> cart; // Stores item name and quantity
public:
    void addItem(const string& item, int quantity) {
        cart[item] += quantity;
        cout << quantity << " " << item << "(s) added to the cart." << endl;
    }

    void removeItem(const string& item) {
        if (cart.find(item) != cart.end()) {
            cart.erase(item);
            cout << item << " removed from the cart." << endl;
        } else {
            cout << "Item not found in cart." << endl;
        }
    }

    void displayCart() {
        if (cart.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Items in your cart:" << endl;
        for (const auto& item : cart) {
            cout << item.first << " - " << item.second << endl;
        }
    }
};

// Main function to demonstrate the usage
int main() {
    // Stack Demonstration
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top element of stack: " << s.top() << endl;
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;

    // Queue Demonstration
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << "Front element of queue: " << q.front() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.front() << endl;

    // Shopping Cart Demonstration
    ShoppingCart cart;
    cart.addItem("Apple", 3);
    cart.addItem("Banana", 2);
    cart.displayCart();
    cart.removeItem("Apple");
    cart.displayCart();

    return 0;
}

```
