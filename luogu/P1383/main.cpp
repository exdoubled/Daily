#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;

const int N = 1e5+10;

int main() {
    int n;
    cin >> n;
    rope<char> now;
    vector<rope<char> > r(N);
    int cnt = 0;
    while (n--) {
        string op;
        cin >> op;
        if (op == "T") {
            char x;
            cin >> x;
            now.push_back(x);
            r[++cnt] = now;
        } else if (op == "U") {
            int k;
            cin >> k;
            now = r[cnt - k];
            r[++cnt] = now;
        } else if (op == "Q") {
            int k;
            cin >> k;
            cout << now[k - 1] << endl;
        }
    }
    return 0;
}