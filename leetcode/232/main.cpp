#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> *s1, *s2;
public:
    MyQueue() {
        s1 = new stack<int>();
        s2 = new stack<int>();
    }

    void push(int x) {
        s1->push(x);
    }

    int pop() {
        peek();
        int res = s2->top();
        s2->pop();
        return res;
    }

    int peek() {
        if (s2->empty()) {
            while (!s1->empty()) {
                s2->push(s1->top());
                s1->pop();
            }
        }
        return s2->top();
    }

    bool empty() {
        return s1->empty() && s2->empty();
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}