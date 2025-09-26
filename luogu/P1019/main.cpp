#include <iostream>
#include <string>
#include <vector>

using namespace std;
string temp;

int same(string a, string b, int limit){
    int n = limit < b.size() ? (int)limit : (int)b.size();
    for(int i = 0; i < n; ++i)
}

void dfs(vector<string>& v, string& ans, int limit){
    for(auto & str : v){
        if(!ans.empty() && *(ans.end()-1) == *(str.begin())){
            int temp = (int)ans.size();
            ans.pop_back();
            ans += str;
            dfs(v, ans, limit);
            ans = ans.substr(0, temp);
        }
        if(ans.empty()){
            ans += str;
            limit = (int)str.size();
            dfs(v, ans, limit);
            ans.clear();
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    vector<vector<bool>> hasGone(n, vector<bool>(n, false));
    for(int i = 0; i < n; ++i) cin >> v[i];
    string ans;
    dfs(v, ans, 0);
    cout << ans.size();
    return 0;
}
