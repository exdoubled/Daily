#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, h;
    bool operator>(const Cell& o) const { return h > o.h; }
};

int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();
    if (m < 3 || n < 3) return 0;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    for (int i = 0; i < m; ++i) {
        pq.push({i, 0, heightMap[i][0]}); vis[i][0] = true;
        pq.push({i, n-1, heightMap[i][n-1]}); vis[i][n-1] = true;
    }
    for (int j = 1; j < n-1; ++j) {
        pq.push({0, j, heightMap[0][j]}); vis[0][j] = true;
        pq.push({m-1, j, heightMap[m-1][j]}); vis[m-1][j] = true;
    }
    int res = 0, dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while (!pq.empty()) {
        auto [x, y, h] = pq.top(); pq.pop();
        for (auto& d : dirs) {
            int nx = x + d[0], ny = y + d[1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) continue;
            res += max(0, h - heightMap[nx][ny]);
            pq.push({nx, ny, max(h, heightMap[nx][ny])});
            vis[nx][ny] = true;
        }
    }
    return res;
}
