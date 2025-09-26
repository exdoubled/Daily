#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; i <= n; ++i){
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i <= n; ++i) matrix[i][0] = matrix[0][i] = 0;
    vector<vector<int>> sum(n+1, vector<int>(n+1));
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            sum[i][j] = sum[0][j] + sum[0][i] -
        }
    }
    return 0;
}
