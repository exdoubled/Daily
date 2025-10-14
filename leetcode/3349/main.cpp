#include <iostream>
#include <vector>

using namespace std;

bool hasIncreasingSubrrays(vector<int>& nums, int k) {
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i + k < n - 1; ++i) {
        if (nums[i] < nums[i+1] && nums[i+k] < nums[i+k+1]) {
            cnt++;
            if (cnt >= k-1) return true;
        } else {
            cnt = 0;
        }
    }
    if (k == 1 && n >= 2) return true;
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}