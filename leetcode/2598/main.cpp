#include <iostream>
#include <vector>

using namespace std;

int findSmallestInteger(vector<int> &nums, int value) {
    int n = nums.size();
    int min = INT_MAX;
    vector<int> cm(value, 0);
    for (int i = 0; i < n; ++i) {
        min = min < nums[i] ? min : nums[i];
        int idx = ((nums[i] % value) + value) % value;
        cm[idx]++;
    }

    int mex = 0;
    while (cm[mex % value] > 0) {
        cm[mex % value]--;
        mex++;
    }
    return mex;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}