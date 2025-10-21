#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int maxFrequency(vector<int> &nums, int k, int numOperations) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    unordered_map<int, int> counter;
    counter.reserve(nums.size() * 2);
    for (int v : nums) ++counter[v];

    int n = nums.size();
    int L = 0, R = 0;
    int ans = 0;
    int minVal = nums.front();
    int maxVal = nums.back();

    for (long long num = minVal; num <= maxVal; ++num) {
        while (L < n && nums[L] < num - k) ++L;
        while (R < n && nums[R] <= num + k) ++R;

        int inRange = R - L;
        int cntNum = 0;
        auto it = counter.find(num);
        if (it != counter.end()) cntNum = it->second;

        int canChange = min(numOperations, inRange - cntNum);
        ans = max(ans, cntNum + canChange);
    }

    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}