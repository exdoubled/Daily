#include <iostream>
#include <vector>

using namespace std;

void reduce(vector<int>& nums, int from, int to){
    for(int i = from; i <= to; i++){
        nums[i]--;
    }
}

void dfs(vector<int>& nums, int start, int& ans){
    int p = start;
    while ((nums[p+1] >= nums[p]) || (nums[p+1] < nums[p] && nums[p+1] >= nums[start-1])){
        if(start == 0 && p == nums.size()-1 && nums[start] == 0) break;
        while(nums[p] == start) p++;
        if(nums[p+1] > nums[p]) dfs(nums, p+1, ans);
        else{// 出现nums[p+1] < nums[p]
            reduce(nums, start, p);
            ans++;
        }
    }
}

int main() {
    int n;
    int ans = 0;
    cin >> n;
    vector<int> v(n + 2);
    v[n+1] = v[0] = INT32_MIN;
    for(int i = 1; i <= n; ++i) cin >> v[i];

    dfs(v, 1, ans);
    cout << ans;
    return 0;
}
