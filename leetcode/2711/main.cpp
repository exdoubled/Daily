#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vector<vector<int>> answer(n, vector<int>(m));


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            set<int> topSet, bottomSet;
            for (int x = i + 1, y = j + 1; x < n && y < m; ++x, ++y) {
                bottomSet.insert(grid[x][y]);
            }

            for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; --x, --y) {
                topSet.insert(grid[x][y]);
            }

            answer[i][j] = abs((int)bottomSet.size() - (int)topSet.size());
        }
    }
    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (auto &row : grid) {
        for (auto &elem : row) {
            cin >> elem;
        }
    }
    vector<vector<int>> ans = differenceOfDistinctValues(grid);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}