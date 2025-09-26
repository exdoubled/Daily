#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // 用于accumulate函数

using namespace std;

void dfs(vector<int>& nums, int i, bool& key, int currentSum, int sum) {
    if (key || currentSum*2 > sum) return;
    if (currentSum*2 == sum) {
        key = true;
        return;
    }
    if (i == nums.size()) return;
    int j = i;
    while (j < nums.size() && nums[j] == nums[i]) j++;
    int count = j - i;
    dfs(nums, j, key, currentSum, sum);
    for (int k = 1; k <= count; ++k) {
        int add = nums[i] * k;
        if (currentSum + add > sum) break;
        dfs(nums, j, key, currentSum + add, sum);
        if (key) return;
    }
}

bool canPartition(vector<int>& nums) {
    int  sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    sort(nums.begin(), nums.end(), greater<int>());
    bool key = false;
    dfs(nums, 0, key, 0, sum);
    return key;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << canPartition(nums);
    return 0;
}