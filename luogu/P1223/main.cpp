#include <iostream>
#include <vector>
#include <algorithm>

#include <iomanip>

using namespace std;

struct Node{
    int pos{};
    int val{};
};

bool cmp(const Node& a, const Node& b){
    return a.val < b.val;
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].val;
        v[i].pos = i + 1;
    }
    sort(v.begin(), v.end(), cmp);
    double res = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < i; ++j){
            res += v[j].val;
        }
    }
    res /= n;
    for (int i = 0; i < n; ++i) cout << v[i].pos << ' ';
    cout << endl;
    cout << fixed << setprecision(2) << res;
    return 0;
}
