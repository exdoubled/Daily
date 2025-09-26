#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void dfs(set<int>& ans, int path, unordered_map<int, int>& map, int size){
    if(size == 3) {
        if(!(path&1)) ans.insert(path);
        return;
    }
    for(auto& key : map){
        if(size == 0 && key.first == 0) continue;
        if(key.second){
            path = path * 10 + key.first;
            key.second--;
            dfs(ans, path, map, size+1);
            key.second++;
            path /= 10;
        }
    }
}

vector<int> findEvenNumbers(vector<int>& digits){
    unordered_map<int, int> map;
    for(auto digit : digits){
        map[digit]++;
    }
    vector<int> ans;
    set<int> set;
    int path = 0;
    dfs(set, path, map, 0);
    for(auto t : set) ans.push_back(t);
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<int> ans = findEvenNumbers(v);
    for(auto k : ans) cout << k << " ";
    return 0;
}
