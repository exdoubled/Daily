#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dfs(int cur, vector<int>& path, int& maxDistance, int curDistance, vector<bool>& visit, vector<int>& ans, vector<vector<int>>& adj) {
    if (curDistance > maxDistance) {
        maxDistance = curDistance;
        ans.clear();
        ans = path;
    }
    int n = (int)adj.size();
    for(int i = 1; i < n; ++i) {
        if(adj[cur][i] > 0 && !visit[i]) {
            visit[i] = true;
            path.push_back(i);
            dfs(i, path, maxDistance, curDistance + adj[cur][i], visit, ans, adj);
            path.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for(int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = w;
    }

    vector<int> nodes;
    vector<bool> visit(n + 1, false);
    int maxDistance = 0;

    vector<int> path;
    path.push_back(1);
    visit[1] = true;
    dfs(1, path, maxDistance, 0, visit, nodes, adj);
    int begin = nodes.back();

    fill(visit.begin(), visit.end(), false);
    nodes.clear();
    path.clear();
    path.push_back(begin);
    visit[begin] = true;
    maxDistance = 0;
    dfs(begin, path, maxDistance, 0, visit, nodes, adj);
    int end = nodes.back();
    int nodeNum = (int)nodes.size();

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
    for(int u = 1; u <= n; ++u) {
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int v = 1; v <= n; ++v) {
                if (adj[cur][v] > 0 && !visited[v]) {
                    visited[v] = true;
                    dist[u][v] = dist[u][cur] + adj[cur][v];
                    q.push(v);
                }
            }
        }
    }

    vector<int> edgeLengths;
    edgeLengths.reserve(nodeNum - 1);
for(int i = 0; i < nodeNum - 1; ++i) {
        edgeLengths.push_back(adj[nodes[i]][nodes[i + 1]]);
    }

    int minEcc = INT_MAX;
    for(int i = 0; i < nodeNum; ++i) {
        int current_length = 0;
        for(int j = i; j < nodeNum; ++j) {
            if (j > i) current_length += edgeLengths[j - 1];
            if (current_length > s) break;
            int ecc = 0;
            for(int v = 1; v <= n; ++v) {
                int minDist = INT_MAX;
                for (int k = i; k <= j; ++k) {
                    int u = nodes[k];
                    if (dist[v][u] < minDist) {
                        minDist = dist[v][u];
                    }
                }
                if(minDist > ecc) {
                    ecc = minDist;
                }
            }
            if(ecc < minEcc) {
                minEcc = ecc;
            }
        }
    }

    cout << minEcc << endl;

    return 0;
}