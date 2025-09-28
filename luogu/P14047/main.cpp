#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int T,n;
    cin >> T;
    while (T-- > 0) {
        cin >> n;
        vector<int> v(n);
        ll total = 0;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            total += v[i];
        }
        ll ave = (ll)total / n;
        for (int i = 0; i < n; i++) {
            if (v[i] > ave) ans += v[i] - ave;
        }
        cout << ans << endl;
    }
    return 0;
}