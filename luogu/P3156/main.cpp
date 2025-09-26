#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<int> w(m);
    for(int i = 0; i < m; ++i) cin >> w[i];
    for(int i = 0; i < m; ++i) cout << v[w[i]-1] << endl;
    return 0;
}
