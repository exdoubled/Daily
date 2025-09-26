#include <iostream>
#include <vector>

using namespace std;

// 本题数据加强
// 解法从O(n^3)改为O(n)

long long maximumTripletValue(vector<int>& nums){
    int n = (int)nums.size();
    if (n < 3) return 0;

    vector<long long> max_k(n, 0);
    int current_max = 0;
    for (int j = n - 2; j >= 0; --j) {
        current_max = max(current_max, nums[j + 1]);
        max_k[j] = current_max;
    }

    vector<long long> max_i(n, 0);
    int current_max_i = nums[0];
    for (int j = 1; j < n; ++j) {
        max_i[j] = current_max_i;
        if (nums[j] > current_max_i) {
            current_max_i = nums[j];
        }
    }

    long long ans = 0;
    for (int j = 1; j < n - 1; ++j) { // j至少为1，且k至少为j+1，所以j的范围到n-2即可
        long long diff = max_i[j] - nums[j];
        if (diff > 0) {
            long long product = diff * max_k[j];
            if (product > ans) {
                ans = product;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    cout << maximumTripletValue(v);

    return 0;
}
