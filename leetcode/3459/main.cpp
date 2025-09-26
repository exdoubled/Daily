#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int ans = solve(grid);
        grid = rotate(grid);
        ans = max(ans, solve(grid));
        grid = rotate(grid);
        ans = max(ans, solve(grid));
        grid = rotate(grid);
        ans = max(ans, solve(grid));
        return ans;
    }

private:
    /**
     * 只考虑真正的V字形，即拐点在下面的情况
     * 其他3种拐弯情况可通过旋转矩阵后再计算得到
     */
    int solve(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // f[i][j]表示从(i,j)往左上能走的最大步数
        vector<vector<int>> f(m, vector<int>(n, 0));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if ((grid[i][j] == 1 && grid[i - 1][j - 1] == 2) || // (i,j)可能是开始点1，只能连接2
                    (grid[i][j] == 2 && grid[i - 1][j - 1] == 0) ||
                    (grid[i][j] == 0 && grid[i - 1][j - 1] == 2)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                }
            }
        }

        // g[i][j]表示从(i,j)往右上能走的最大步数
        vector<vector<int>> g(m, vector<int>(n, 0));
        for (int i = 1; i < m; ++i) {
            for (int j = n - 2; j >= 0; --j) {
                if ((grid[i][j] == 2 && grid[i - 1][j + 1] == 1) || // 右上可能是开始点1，连接(i,j)的2
                    (grid[i][j] == 2 && grid[i - 1][j + 1] == 0) ||
                    (grid[i][j] == 0 && grid[i - 1][j + 1] == 2)) {
                    g[i][j] = g[i - 1][j + 1] + 1;
                }
            }
        }

        int ans = 0;
        // 枚举拐点 (i,j)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int gi = g[i][j], gj = j + g[i][j];
                int ii = i - gi, jj = gj;
                if (ii >= 0 && jj < n && grid[ii][jj] == 1) { // 边界检查
                    ans = max(ans, f[i][j] + g[i][j] + 1);
                }
            }
        }
        return ans;
    }

    // 顺时针旋转矩阵

    vector<vector<int>> rotate(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> gridNew(n, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                gridNew[j][m - i - 1] = grid[i][j];
            }
        }
        return gridNew;
    }
};
