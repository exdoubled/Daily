#include <iostream>
#include <vector>

using namespace std;

vector<int> buildArray(vector<int>& nums){
    for(auto &num : nums){
        num = num + ((nums[num] & 0xFFFF) << 16);
    }
    for(auto &num : nums){
        num = num >> 16;
    }
    return nums;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    nums = buildArray(nums);
    for(auto num : nums) cout << num << " ";
    return 0;
}
