#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long dp(vector<int>& nums, int target){
    int n = (int)nums.size();
    int l = 0,r = n-1;
    long long ans = 0;
    while(1){
        while(l < r && nums[l]+nums[r] > target) r--;
        if(r<=l) break;
        ans += r-l;
        l++;
    }
    return ans;
}


long long countFairPair(vector<int>& nums, int lower, int upper){
    sort(nums.begin(), nums.end());
    return dp(nums, upper) - dp(nums,lower-1);
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << countFairPair(v, l, r);
    return 0;
}
