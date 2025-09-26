#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    string name;
    int y{};
    int m{};
    int d{};
    int pos{};
};

bool cmp(const Node& a, const Node& b){
    if(a.y < b.y) return true;
    else if(a.y > b.y) return false;
    else if(a.m < b.m) return true;
    else if(a.m > b.m) return false;
    else if(a.d < b.d) return true;
    else if(a.d > b.d) return false;
    return a.pos > b.pos;
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i].name >> v[i].y >> v[i].m >> v[i].d;
        v[i].pos = i;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < n; ++i) cout << v[i].name << endl;
    return 0;
}
