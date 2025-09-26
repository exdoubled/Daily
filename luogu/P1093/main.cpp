#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int x;
    int y;
    int z;
    int all;
    int pos;
};

bool cmp(Node& a, Node& b){
    if(a.all > b.all) return true;
    else if(a.all < b.all) return false;
    else {
        if(a.x > b.x) return true;
        else if(a.x < b.x) return false;
        else{
            if(a.pos < b.pos) return true;
            else if(a.pos > b.pos) return false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].x >> v[i].y >> v[i].z;
        v[i].pos = i+1;
        v[i].all = v[i].x + v[i].y + v[i].z;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i = 0; i < 5; ++i){
        cout << v[i].pos << " " << v[i].all << endl;
    }
    return 0;
}
