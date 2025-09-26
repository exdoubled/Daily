#include <iostream>
#include <vector>

using namespace std;

int subsetXORSum(vector<int>& nums){
    int n = (int)nums.size();
    int limit = 1 << n; // 二进制数位数
    vector<vector<int> > res(limit);
    for(int i = 0; i < limit; ++i){
        for(int j = 0; j < n; ++j){
            if((i >> j) & 1){
                res[i].push_back(nums[j]);
            }
        }
    }
    int ans = 0;
    int p = (int)res.size();
    for(int i = 0; i < p; ++i){
        int temp = 0;
        int q = (int)res[i].size();
        for(int j = 0; j < q; ++j){
            if(res[i].empty()) ans += 0;
            temp ^= res[i][j];
        }
        ans += temp;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
