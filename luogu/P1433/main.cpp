#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Node {
    double x;
    double y;
};

double getLen(Node& a, Node& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> v[i].x >> v[i].y;
    Node start{};
    start.x = 0;
    start.y = 0;
    // 计算距离
    vector<vector<double>> dist(n + 1, vector<double>(n + 1));
    for (int i = 1; i <= n; ++i) {
        dist[0][i] = getLen(start, v[i]);
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = getLen(v[i], v[j]);
        }
    }

    // 最大的状态
    int maxN = 1 << n;
    // 初始化状态
    vector<int> g(n + 1);
    g[1] = 1;
    for (int i = 2; i <= n; ++i) {
        g[i] = g[i - 1] << 1;
    }

    vector<vector<double>> dp(1 << n, vector<double>(n + 1, 0x3f3f3f3f));
    // 初始状态：从起点到各个点的距离
    for (int i = 1; i <= n; ++i) {
        dp[g[i]][i] = dist[0][i];
    }
    dp[0][0] = 0;

    for (int i = 0; i < maxN; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i & g[j]) {
                for (int k = 1; k <= n; ++k) {
                    if (k != j && (i & g[k])) {
                        dp[i][j] = min(dp[i][j], dp[i ^ g[j]][k] + dist[k][j]);
                    }
                }
            }
        }
    }

    double ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[maxN - 1][i]);
    }
    cout << fixed << setprecision(2) << ans;
    return 0;
}