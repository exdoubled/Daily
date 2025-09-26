#include <iostream>
#include <vector>

using namespace std;

long long countSubrrays(vector<int>& nums, int k){
    long long ans = 0;
    int n = (int) nums.size();
    int maxNum = INT32_MIN;
    for(int i = 0; i < n; ++i) maxNum = maxNum >= nums[i] ? maxNum : nums[i];
    vector<int> sumPos;
    for(int i = 0; i < n; ++i){
        if(nums[i] == maxNum) sumPos.push_back(i);
    }
    int cntN = (int)sumPos.size();
    if(cntN < k) return 0;
    ans = (long long)(n - sumPos[k-1]) * (long long)(sumPos[0] + 1);
    for(int i = 1; i < cntN-k+1; ++i){
        ans += (n-sumPos[i+k-1]) * (sumPos[i]-sumPos[i-1]);
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0 ; i < n; ++i) cin >> v[i];
    cout << countSubrrays(v,k);
    return 0;
}
