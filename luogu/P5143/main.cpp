#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Node{
    int x;
    int y;
    int z;
};

bool cmp(Node e,Node r){
    return e.z < r.z;
}

int main() {
    int n;
    double ans = 0;
    cin >> n;
    vector<Node> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i].x >> v[i].y >> v[i].z;
    }
    sort(v.begin(),v.end(), cmp);
    for(int i = 0; i < n-1; ++i){
        ans += sqrt(pow(v[i].x-v[i+1].x,2)+pow(v[i].y-v[i+1].y,2)+pow(v[i].z-v[i+1].z,2));
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}
