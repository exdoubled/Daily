#include <iostream>
#include <vector>

using namespace std;

bool key(vector<int>& nums, int k, int i, int j){
    bool key1 = false;
    bool key2 = false;
    if(nums[i] == nums[j]) key1 = true;
    if(i*j % k == 0) key2 = true;
    return key1 && key2;
}

int countPairs(vector<int>& nums, int k){
    int n = (int)nums.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(key(nums, k, i, j)) ans++;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    cout << countPairs(nums, k);
    return 0;
}
