#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int low = nums[0] - k;
    int n = nums.size();
    int res = 1;
    for (int i = 1; i < n; ++i) {
        if (nums[i] + k < low + 1)
            continue;
        ++res;
        low = max(low+1, nums[i] - k);
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}