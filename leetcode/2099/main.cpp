#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first > p2.first;
}

bool restore(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<pair<int, int>> pairs;
    int n = (int)nums.size();
    pairs.reserve(n);
    for(int i = 0; i < n; ++i) pairs.emplace_back(nums[i], i);
    sort(pairs.begin(), pairs.end(), compare);
    pairs.resize(k);
    sort(pairs.begin(), pairs.end(), restore);
    vector<int> ans;
    ans.reserve(k);
    for(const auto& p : pairs) ans.push_back(p.first);
    return ans;
}

int main() {
    vector<int> nums = {3, 1, 2, 4};
    int k = 2;
    vector<int> result = maxSubsequence(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}