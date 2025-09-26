#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void print(vector<vector<int>>& ans){
    for(auto nums : ans){
        for(auto num : nums){
            cout << setw(3) << num;
        }
        cout << endl;
    }
}

void dfs(int n, int k, int size,int cur, vector<vector<int>>& ans, vector<int>& path){
    if(size == k){
        ans.push_back(path);
    }
    else{
        for(int i = cur; i <= n; ++i){
            path.push_back(i);
            dfs(n,k,size+1,i+1,ans,path);
            path.pop_back();
        }
    }

}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> ans;
    vector<int> path;
    dfs(n,k,0,1,ans,path);
    print(ans);
    return 0;
}
