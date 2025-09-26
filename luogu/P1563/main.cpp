#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> map(n);
    for (int i = 0; i < n; ++i) {
        cin >> map[i].second >> map[i].first;
    }

    int cur = 0;

    for (int i = 0; i < m; ++i) {
        int dir, num;
        cin >> dir >> num;
        int step = num % n;
        if (step == 0) continue;

        if (dir ^ map[cur].second) {
            cur = (cur + step) % n;
        } else {
            cur = (cur - step + n) % n;
        }
    }

    cout << map[cur].first;

    return 0;
}