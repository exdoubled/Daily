#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& nums, int time1, int time2, int size, int& ans, int cur){
    int sum = (time1 > time2 ? time1 : time2);
    if(size == nums.size()){
        ans = ans > sum ? sum : ans;
    }
    if(sum >= ans){
        return;
    }
    dfs(nums, time1 + nums[cur], time2, size+1, ans, cur+1);
    dfs(nums, time1, time2 + nums[cur], size+1, ans, cur+1);
}

int main() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int ans1, ans2, ans3, ans4;
    ans1 = ans2 = ans3 = ans4 = INT32_MAX;
    vector<int> v1(s1);
    for(int i = 0; i < s1; ++i) cin >> v1[i];
    dfs(v1, 0, 0, 0, ans1, 0);

    vector<int> v2(s2);
    for(int i = 0; i < s2; ++i) cin >> v2[i];
    dfs(v2, 0, 0, 0, ans2, 0);

    vector<int> v3(s3);
    for(int i = 0; i < s3; ++i) cin >> v3[i];
    dfs(v3, 0, 0, 0, ans3, 0);

    vector<int> v4(s4);
    for(int i = 0; i < s4; ++i) cin >> v4[i];
    dfs(v4, 0, 0, 0, ans4, 0);

    int ans = ans1 + ans2 + ans3 + ans4;
    cout << ans;
    return 0;
}
