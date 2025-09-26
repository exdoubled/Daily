#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (auto& j : ans) {
            if (j.back() == v[i] - 1) {
                j.push_back(v[i]);
                found = true;
                break;
            } else if (j.front() == v[i] + 1) {
                j.insert(j.begin(), v[i]);
                found = true;
                break;
            }
        }
        if (!found) {
            ans.push_back({v[i]});
        }
    }

    sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
        return a.size() < b.size();
    });
    cout << ans[0].size() << endl;
    return 0;
}