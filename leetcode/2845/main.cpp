#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    k = (k % modulo + modulo) % modulo;
    int n = nums.size();
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        A[i] = (nums[i] % modulo == k) ? 1 : 0;
    }

    unordered_map<int, int> prefix_count;
    prefix_count[0] = 1;
    int current_sum = 0;
    long long ans = 0;

    for (int a : A) {
        current_sum = (current_sum + a) % modulo;
        int target = (current_sum - k + modulo) % modulo;
        ans += prefix_count[target];
        prefix_count[current_sum]++;
    }

    return ans;
}

int main() {
    int n, modulo, k;
    cin >> n >> modulo >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    cout << countInterestingSubarrays(v, modulo, k);
    return 0;
}