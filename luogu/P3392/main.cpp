#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(vector<string>& map, int BBegin, int RBegin,  int& ans, vector<vector<bool>>& hasGone){
    if(BBegin >= RBegin || RBegin >= map.size()) return;
    if(hasGone[BBegin][RBegin]) return;
    int sum = 0;
    for(int i = 0; i < BBegin; ++i){
        for(auto c : map[i]){
            if(c != 'W') sum++;
        }
    }

    for(int i = BBegin; i < RBegin; ++i){
        for(auto c : map[i]){
            if(c != 'B') sum++;
        }
    }

    for(int i = RBegin; i < map.size(); ++i){
        for(auto c : map[i]){
            if(c != 'R') sum++;
        }
    }

    ans = ans <= sum ? ans : sum;
    hasGone[BBegin][RBegin] = true;
    dfs(map, BBegin, RBegin+1,ans, hasGone);
    dfs(map, BBegin+1, RBegin,ans, hasGone);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> map(n);
    for(int i = 0; i < n; ++i) cin >> map[i];
    int ans = INT32_MAX;
    vector<vector<bool>> hasGone(n, vector<bool>(n, false));
    dfs(map, 1, 2, ans, hasGone);
    cout << ans;
    return 0;
}
