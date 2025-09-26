#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
struct Node{
    int val;
    int num;
};

bool cmp(Node& a, Node& b){
    return a.val < b.val;
}

int main() {
    int n, c;
    cin >> n >> c;
    vector<Node> v;
    int temp = 0;
    map<int, int> mp;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        mp[temp]++;
    }
    v.reserve(mp.size());
    for(auto & it : mp){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(),cmp);
    long long ans = 0;
    int l = 0, r = 0;

    while(r < v.size() && l < v.size()){
        if(v[r].val - v[l].val == c){
            ans += (long long)v[l].num * (long long)v[r].num;
            l++;
        } else if(v[r].val - v[l].val < c){
            r++;
        } else{
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
