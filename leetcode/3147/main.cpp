#include <iostream>
#include <vector>

using namespace std;

int maximumEnergy(vector<int> &energy, int k) {
    int n = (int)energy.size();
    vector<int> ans(k, INT_MIN);
    for (int i = 0; i < k; ++i) {
        int curr = 0;
        for (int j = n - 1 - i; j >= 0; j -= k) {
            curr += energy[j];
            ans[i] = max(ans[i], curr);
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < k; ++i) {
        res = max(res, ans[i]);
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> energy(n);
    for (int i = 0; i < n; ++i) cin >> energy[i];
    cout << maximumEnergy(energy, k) << endl;
    return 0;
}