#include <iostream>
#include <vector>

using namespace std;

bool limit(int m, int n, int i, int j){
    return i >= 0 && i <= n && j >= 0 && j <= m;
}

bool horseLimit(vector<vector<int>>& horse, int x, int y){
    for (auto & k : horse) {
        if(k[0] == x && k[1] == y) return true;
    }
    return false;
}

int x[8] = {-2, -2, 2,2,-1, -1, 1, 1};
int y[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    int m, n, i, j;
    cin >> n >> m >> i >> j;

    vector<vector<int>> cant;
    for(int k = 0; k < 8; ++k){
        if(limit(m, n, i+x[k], j+y[k])){
            vector<int> temp(2);
            temp[0] = i+x[k];
            temp[1] = j+y[k];
            cant.push_back(temp);
        }
    }
    cant.push_back({i, j});

    vector<vector<long long>> dp(n+1, vector<long long>(m+1));
    bool key1 = true;
    for(int k = 0; k < n+1; ++k) {
        if(horseLimit(cant, k, 0)) key1 = false;
        if(key1) dp[k][0] = 1;
        else dp[k][0] = 0;
    }
    bool key2 = true;
    for(int k = 0; k < m+1; ++k) {
        if(horseLimit(cant, 0, k)) key2 = false;
        if(key2) dp[0][k] = 1;
        else dp[0][k] = 0;
    }

    for(int k1 = 1; k1 < n+1; ++k1){
        for(int k2 = 1; k2 < m+1; ++k2){
            if(horseLimit(cant, k1, k2)){
                dp[k1][k2] = 0;
            } else{
                dp[k1][k2] = dp[k1-1][k2] + dp[k1][k2-1];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
