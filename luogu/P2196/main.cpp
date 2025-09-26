#include <iostream>
#include <vector>

using namespace std;

void road(int x, vector<int>& path){
    if(path[x]) road(path[x],path);
    cout << x << " ";
}

int main() {
    int n;
    cin >> n;
    vector<int> landmine(n+1, 0);
    vector<vector<int>> assess(n+1, vector<int>(n+1,0));
    for(int i = 1; i <= n; ++i) cin >> landmine[i];
    for(int i = 1; i <= n; ++i){
        for(int j = i; j < n+1; ++j){
            if(i == j) {
                assess[i][j] = 1;
                continue;
            }
            cin >> assess[i][j];
            assess[j][i] = assess[i][j];
        }
    }

    vector<int> path(n+1,0);
    vector<int> dp(n+1,0);
    int ans;
    int pos;

    for(int i = 1; i <= n; ++i){
        dp[i] = landmine[i];
        for(int j = i-1; j > 0; --j){
            if(assess[j][i] && dp[i] < dp[j]+landmine[i]){
                dp[i] = dp[j] + landmine[i];
                path[i] = j;
            }
        }
        if(ans < dp[i]){
            ans = dp[i];
            pos = i;
        }
    }
    road(pos,path);
    cout << endl;
    cout << ans;

    return 0;
}
