#include <iostream>
#include <vector>

using namespace std;

void dfs(int cur, vector<int> states[], vector<vector<int>>& dp, int n, vector<int>& moneys, vector<int>& values){
    for(auto next : states[cur]){
        for(int i = 0; i <= n-moneys[next]; ++i){
            dp[next][i] = dp[cur][i] + values[next];
        }
        dfs(next, states, dp, n, moneys, values);
        for(int i = moneys[next]; i <= n; ++i){
            dp[cur][i] = max(dp[cur][i], dp[next][i-moneys[next]]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    vector<int> moneys(n+1), values(n+1), states[n+1];
    for(int i = 1, state; i <= m; ++i){
        cin >> moneys[i] >> values[i] >> state;
        values[i] *= moneys[i];
        states[state].push_back(i);
    }
    dfs(0, states, dp, n, moneys, values);
    cout << dp[0][n];
    return 0;
}
