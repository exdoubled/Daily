#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m,c;
    cin >> n >> m >> c;
    vector<vector<int>> map(n,vector<int>(m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> sum(n+1, vector<int>(m+1));
    for(int i = 0; i < n+1; ++i){
        if(i == 0) {
            for(int j = 0; j < m+1; ++j){
                sum[i][j] = 0;
            }
        } else{
            sum[i][0] = 0;
            for(int j = 1; j < m+1; ++j){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + map[i-1][j-1];
            }
        }
    }
    int max = INT32_MIN;
    int maxI, maxJ;
    maxI = maxJ = 0;
    for(int i = 1; i + c - 1 <= n; ++i){
        for(int j = 1; j + c - 1 <= m; ++j){
            int sumk = sum[i + c - 1][j + c - 1] + sum[i-1][j-1] - sum[i-1][j+c-1] - sum[i+c-1][j-1];
            if(sumk >= max) {
                max = sumk;
                maxI = i;
                maxJ = j;
            }
        }
    }
    cout << maxI  << " " << maxJ;
    return 0;
}
