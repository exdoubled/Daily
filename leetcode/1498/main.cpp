#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define mod 100000007

using namespace std;

int numSubseq(vector<int>& nums, int target){
    sort(nums.begin(),nums.end());
    int n = (int)nums.size();
    int ans = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(nums[j]+nums[i] <= target) ans = (ans + ((int)pow(2,j-i+1) % mod)) % mod;
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
