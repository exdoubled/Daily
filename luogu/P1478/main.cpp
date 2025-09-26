#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    return a.second < b.second;
}

int main() {
    int n,s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    int ans = 0;
    vector<pair<int, int>> apple;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;
        if(a+b >= x) apple.emplace_back(x,y);
    }

    sort(apple.begin(), apple.end(), cmp);
    for(auto key : apple){
        if(s < key.second) break;
        else{
            ans++;
            s -= key.second;
        }
    }
    cout << ans;

    return 0;
}
