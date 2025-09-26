#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void dfs(vector<int>& arr, int a, int b, int c, int cur, int & ans, vector<int>& path){
    if(path.size() == 3) {
        if(abs(path[0] - path[1]) <= a &&
           abs(path[1] - path[2]) <= b &&
           abs(path[0] - path[2]) <= c){
            ans++;
        }
    } else{
        for(int i = cur; i < arr.size(); ++i){
            path.push_back(arr[i]);
            dfs(arr, a, b, c, i+1, ans, path);
            path.pop_back();
        }
    }
}

int countGoodTriplets(vector<int>& arr, int a, int b, int c){
    vector<int> path;
    int ans = 0;
    dfs(arr, a, b, c, 0, ans, path);
    return ans;
}

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << countGoodTriplets(v, a, b, c);
    return 0;
}
