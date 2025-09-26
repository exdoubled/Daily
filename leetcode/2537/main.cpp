#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countGood(vector<int>& nums, int k){
    long long ans = 0;
    unordered_map<int, int> path;
    int cnt = 0;
    int n = (int)nums.size();
    int l = 0, r = 0;
    // 左闭右开区间
    while(true){
        if(r == n && cnt < k) break;
        if(cnt < k){
            path[nums[r]] = path.find(nums[r]) == path.end() ? 1 : path[nums[r]]+1;
            cnt += path[nums[r]] - 1;
            r++;
        } else {
            ans += n - r + 1;
            cnt -= path[nums[l]] - 1;
            if(path[nums[l]] == 1){
                path.erase(nums[l]);
            } else{
                path[nums[l]]--;
            }
            l++;
        }
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i  < n; ++i) cin >> nums[i];
    cout << countGood(nums, k);
    return 0;
}
