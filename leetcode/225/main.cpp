#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> *q;
    int tops = 0;
public:
    MyStack() {
        q = new queue<int>();
    }

    void push(int x) {
        q->push(x);
        tops = x;
    }

    int pop() {
        int size = q->size();
        for (int i = 0; i < size - 1; i++) {
            tops = q->front();
            q->pop();
            q->push(tops);
        }
        int res = q->front();
        q->pop();
        return res;
    }

    int top() {
        return tops;
    }

    bool empty() {
        return q->empty();
    }
};


int main() {
    return 0;
}