#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int x;
    int y;
};

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void dfs(vector<vector<bool>>& barrier,
         int& n, int& m,
         int& ans,
         Node& end,
         vector<bool>& hasGone,
         int cur_x, int cur_y)
{
    if (cur_x == end.x && cur_y == end.y) {
        ans++;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int new_x = cur_x + dx[i];
        int new_y = cur_y + dy[i];
        int new_cur = new_x * m + new_y;

        // 内联条件判断
        if (new_x >= 0 && new_x < n &&
            new_y >= 0 && new_y < m &&
            !barrier[new_x][new_y] &&
            !hasGone[new_cur])
        {
            hasGone[new_cur] = true;
            dfs(barrier, n, m, ans, end, hasGone, new_x, new_y);
            hasGone[new_cur] = false;
        }
    }
}

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<bool> hasGone(n * m, false);
    vector<vector<bool>> barrier(n, vector<bool>(m, false));

    Node start{}, end{};
    cin >> start.x >> start.y >> end.x >> end.y;
    start.x--; start.y--;
    end.x--; end.y--;
    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        barrier[x-1][y-1] = true;
    }
    if (barrier[start.x][start.y] || barrier[end.x][end.y]) {
        cout << 0;
        return 0;
    }

    int ans = 0;
    hasGone[start.x * m + start.y] = true;

    dfs(barrier, n, m, ans, end, hasGone, start.x, start.y);

    cout << ans;
    return 0;
}