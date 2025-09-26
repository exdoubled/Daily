#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> ans;

bool key(vector<int>& a, int b){
    return a.empty() || (b % a.back() == 0);
}

void dfs(vector<int>& nums, int cur, vector<int>& temp, vector<int>& memo) {
    int n = nums.size();
    if (temp.size() > ans.size()) {
        ans = temp;
    }
    vector<int> indices;
    for (int i = cur; i < n; ++i) {
        indices.push_back(i);
    }
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return memo[a] > memo[b];
    });

    for (int idx : indices) {
        int i = idx;
        if (temp.size() + memo[i] <= ans.size()) continue;
        if (i > cur && nums[i] == nums[i-1]) continue;
        if (key(temp, nums[i])) {
            temp.push_back(nums[i]);
            dfs(nums, i + 1, temp, memo);
            temp.pop_back();
        }
    }
}

vector<int> largestDivisibleSubset(vector<int>& nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<int> memo(n, 1);
    for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
            if (nums[j] % nums[i] == 0) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }
    vector<int> temp;
    dfs(nums, 0, temp, memo);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0 ; i < n; ++i) cin >> v[i];
    vector<int> res = largestDivisibleSubset(v);
    for(auto i : res){
        cout << i << " ";
    }
    return 0;
}
