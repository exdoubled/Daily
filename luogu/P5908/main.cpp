#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int& ans, int begin, vector<vector<int>>& adj, vector<bool>& hasGone, int max) {
    queue<int> q;
    q.push(begin);
    hasGone[begin] = true;
    ans = 0;
    int distance = 0;

    while(!q.empty() && distance < max) {
        int level_size = (int)q.size();
        for(int i = 0; i < level_size; ++i) {
            int cur = q.front();
            q.pop();
            for(int neighbor : adj[cur]) {
                if(!hasGone[neighbor]) {
                    hasGone[neighbor] = true;
                    q.push(neighbor);
                    ans++;
                }
            }
        }
        distance++;
    }
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<vector<int>> adj(n + 1);
    vector<bool> hasGone(n + 1, false);

    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int ans = 0;
    bfs(ans, 1, adj, hasGone, d);
    cout << ans;

    return 0;
}