#include <bits/stdc++.h>

using namespace std;



int triangleNumber(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    int n = nums.size();
    for (int k = n-1; k >= 2; --k) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                ans += (j - i);
                --j;
            } else ++i;
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}