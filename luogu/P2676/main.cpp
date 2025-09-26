#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = n-1; i >= 0; --i){
        if(k < 0) break;
        k -= v[i];
        ans++;
    }
    cout << ans;
}
