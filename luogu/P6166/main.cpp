#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    rope<char> now;
    vector<rope<char> > r(n+5);
    int cnt = 0;
    while (n--) {
        string op;
        cin >> op;
        if (op == "T") {
            char x;
            cin >> x;
            now.push_back(x);
            r[cnt++] = now;
        } else if (op == "U") {
            int k;
            cin >> k;
            int idx = cnt - k - 1;
            if (idx < 0) now.clear();
            else now = r[idx];
            r[cnt++] = now;
        } else if (op == "P") {
            int k;
            cin >> k;
            if (k < now.size()) cout << now[k] << endl;
        }
    }
    return 0;
}