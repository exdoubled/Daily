#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (!q.empty() && q.back() == i-k) {
            q.pop_back();
        }
        while (!q.empty() && nums[q.front()] <= nums[i]) {
            q.pop_front();
        }
        q.push_front(i);
        if (i >= k - 1) {
            ans.push_back(nums[q.back()]);
        }
    }
    return ans;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}