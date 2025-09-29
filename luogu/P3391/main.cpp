#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    rope<int> s,rs;
    for (int i = 1; i <= n; ++i ) {
        s.push_back(i);
        rs.push_front(i);
    }
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        --l;
        rope<int> A = s.substr(0, l);
        rope<int> B = s.substr(l, r-l);
        rope<int> C = s.substr(r, n-r);
        rope<int> rA = rs.substr(n - l, l);
        rope<int> rB = rs.substr(n - r, r - l);
        rope<int> rC = rs.substr(0, n - r);
        s = A + rB + C;
        rs = rC + B + rA;
    }
    for (int i : s) cout << i << " ";
    return 0;
}