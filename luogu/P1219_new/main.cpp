#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > ans;
vector<int> line(100,0);
vector<int> col(100,0);
vector<int> lu_rd(100, 0);
vector<int> ru_ld(100, 0);

void dfs(int i){
    if(i > n) ans.push_back(line);
    else{
        for(int j = 1; j <= n; ++j){
            if(!col[j] && !lu_rd[i+j] && !ru_ld[i-j+n]){ // 不同
                line[i] = j;
                col[j] = 1;
                lu_rd[i+j] = 1;
                ru_ld[i-j+n] = 1;
                dfs(i+1);
                col[j] = 0;
                lu_rd[i+j] = 0;
                ru_ld[i-j+n] = 0;
            }
        }
    }
}

int main() {

    cin >> n;
    dfs(1);

    for(int i = 0; i < 3; ++i){
        for(int j = 1; j <= n; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans.size();
    return 0;
}
