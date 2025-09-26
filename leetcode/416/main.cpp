#include <iostream>
#include <vector>
#include <algorithm>


// 时间复杂度过高

using namespace std;

int getSum(vector<int>& nums){
    int ans = 0;
    for(auto num : nums) ans += num;
    return ans;
}

void dfs(vector<int>& nums,int cur, int pathSum, bool& key, int& sum){
    if(pathSum == sum - pathSum){
        key = true;
        return;
    }
    if(key) return;
    if(cur == nums.size() - 1) return;
    for(int i = cur+1; i < nums.size(); ++i){
        pathSum += nums[cur];
        dfs(nums, i, pathSum, key, sum);
        pathSum -= nums[cur];
        dfs(nums, i, pathSum, key, sum);
    }
}

bool canPartition(vector<int>& nums){
    sort(nums.begin(), nums.end());
    int sum = getSum(nums);
    bool key = false;
    dfs(nums, 0, 0, key, sum);
    return key;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    cout << canPartition(nums);
    return 0;
}
