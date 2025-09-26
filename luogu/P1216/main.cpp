#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < i+1; ++j){
            cin >> v[i][j];
        }
    }

    for(int i = n-2; i >=0; --i){
        for(int j = 0; j <=i; ++j){
            v[i][j] = max(v[i+1][j],v[i+1][j+1])+v[i][j];
        }
    }
    cout << v[0][0];
    return 0;
}
