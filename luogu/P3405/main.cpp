#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, int> h;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        string prefix = a.substr(0, 2);
        if (prefix != b) {
            ans += h[prefix + b];
        }
        h[b + prefix]++;
    }
    cout << ans;
    return 0;
}