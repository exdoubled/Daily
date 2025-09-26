#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> dp(m+1);
    dp[0] = 1;

    vector<int> v(n);
    v[0] = 1;
    for(int i = 0; i < n; ++i) cin >> v[i];

    for(int i = 0; i < n; ++i){
        for(int j = m; j >= v[i]; --j){
            dp[j] += dp[j-v[i]];
        }
    }
    cout << dp[m];
    return 0;
}
