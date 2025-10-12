#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    vector<int> s1; // 第一个更大（存索引）
    vector<int> s2; // 第二个更大（存索引）

    for (int i = 0; i < n; ++i) {
        while (!s2.empty() && nums[s2.back()] < nums[i]) {
            ans[s2.back()] = nums[i];
            s2.pop_back();
        }
        vector<int> tmp;
        while (!s1.empty() && nums[s1.back()] < nums[i]) {
            tmp.push_back(s1.back());
            s1.pop_back();
        }
        while (!tmp.empty()) {
            s2.push_back(tmp.back());
            tmp.pop_back();
        }
        s1.push_back(i);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}