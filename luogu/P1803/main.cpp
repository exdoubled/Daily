#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    int start{};
    int end{};
};

bool cmp(Node& a, Node& b){
    if(a.end <= b.end) return true;
    else return false;
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].start >> v[i].end;
    sort(v.begin(), v.end(),cmp);
    int k = 0;
    int ans = 1;
    for(int i = 1; i < n; ++i){
        if(v[i].start >= v[k].end){
            k = i;
            ans++;
        }
    }
    cout << ans;
    return 0;
}
