#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> dp(n+1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i/2; ++j){
            dp[i] += dp[j];
        }
        dp[i]++;
    }
    cout << dp[n];
    return 0;
}
