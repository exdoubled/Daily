#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, int cur){
    if(tree[cur][0] == 0 && tree[cur][1] == 0) return 1;
    if(tree[cur][0] != 0 && tree[cur][1] == 0) return dfs(tree, tree[cur][0])+1;
    if(tree[cur][0] == 0 && tree[cur][1] != 0) return dfs(tree, tree[cur][1])+1;
    if(tree[cur][0] != 0 && tree[cur][1] != 0) return max(dfs(tree, tree[cur][0]), dfs(tree, tree[cur][1])) + 1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n+1, vector<int>(2));
    for(int i = 1; i <= n; ++i) cin >> v[i][0] >> v[i][1];
    cout << dfs(v, 1);
    return 0;
}
