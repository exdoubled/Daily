#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<unsigned long long> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> pos(n + 1, 0);
    vector<int> st;
    st.reserve(n);
    for (int i = n; i >= 1; --i) {
        while (!st.empty() && a[st.back()] < a[i]) st.pop_back();
        pos[i] = st.empty() ? 0 : st.back();
        st.push_back(i);
    }

    int m = n - k + 1;
    vector<int> diff(m + 3, 0);
    for (int i = 1; i <= n; ++i) {
        if (pos[i] == 0) continue;
        int L = max(1, max(i - k + 1, pos[i] - k + 1));
        int R = min(i, m);
        if (L <= R) {
            diff[L] -= 1;
            diff[R + 1] += 1;
        }
    }

    int cur = 0;
    for (int l = 1; l <= m; ++l) {
        cur += diff[l];
        cout << (k + cur) << '\n';
    }
    return 0;
}
