#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trap(vector<int> &height) {
    stack<int> s;   // 栈中存下标
    int cnt = 0;
    for (int i = 0; i < height.size(); ++i) {
        while (!s.empty() && height[s.top()] < height[i]) {
            int low = height[s.top()];
            s.pop();
            if (s.empty()) break;
            int high = min(height[s.top()], height[i]);
            cnt += (i - s.top()- 1) * (high - low);
        }
        s.push(i);
    }
    return cnt;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

