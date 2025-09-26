#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    string A, B;
    for(auto a0 : a) A.push_back(a0 + '0');
    for(auto b0 : b) B.push_back(b0 + '0');
    return A < B;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void print(vector<int>& nums){
    int n = (int)nums.size();
    for(int i = 0; i < n; ++i){
        cout << "    " << nums[i];
    }
    cout << endl;
}

void dfs(vector<int>& nums, int cur, vector<vector<int>>& ans){
    if(cur == nums.size()-1) ans.push_back(nums);
    else{
        for(int i = cur; i < nums.size(); ++i){
            swap(nums[i], nums[cur]);
            dfs(nums,cur+1, ans);
            swap(nums[i], nums[cur]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i){
        nums[i] = i+1;
    }
    dfs(nums,0,ans);
    sort(ans.begin(), ans.end(), cmp);
    for(auto key : ans) print(key);
    return 0;
}
