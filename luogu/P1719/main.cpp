#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> matrix[i][j];
        }
    }
    vector<vector<int>> sum(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = i; k <= n; ++k) {
                for (int l = j; l <= n; ++l) {
                    ans = max(ans, sum[k][l] - sum[i-1][l] - sum[k][j-1] + sum[i-1][j-1]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
