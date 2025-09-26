#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool limit(int n, int m, int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

int minTimeToReach(vector<vector<int>>& moveTime) {
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n = (int)moveTime.size(), m = (int)moveTime[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int t = cur[0], x = cur[1], y = cur[2];

        if(x == n-1 && y == m-1) return t;
        if(t > dist[x][y]) continue;

        for(auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                int nt = max(t, moveTime[nx][ny]) + 1;
                if(nt < dist[nx][ny]) {
                    dist[nx][ny] = nt;
                    pq.push({nt, nx, ny});
                }
            }
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> moveTime(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> moveTime[i][j];
        }
    }
    cout << minTimeToReach(moveTime);
    return 0;

}