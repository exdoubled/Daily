#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, vector<vector<int>>& ans, vector<int>& path, int sum, int step){
    if(step == 10){
        if(sum == n){
            ans.push_back(path);
        }
        return;
    }
    for(int i = 1; i < 4; ++i){
        path[step] = i;
        dfs(n, ans, path, sum + i, step + 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans;
    vector<int> path(10, 0);
    dfs(n, ans, path, 0, 0);
    if(n < 10 || n > 30) cout << "0";
    else{
        cout << ans.size() << endl;
        for(const auto& v : ans){
            for(auto num : v){
                cout << num << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
