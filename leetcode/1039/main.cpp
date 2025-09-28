#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int minScoreTriangulation(vector<int>& values) {
    int n = values.size();
    // dp[i][j] 表示以 i 和 j 为端点的多边形的最小三角剖分值
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // 倒着枚举 i
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 2; j < n; ++j) {
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}