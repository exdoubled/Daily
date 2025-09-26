#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Node{
    double m{};
    double v{};
};

bool cmp(Node a, Node b){
    return a.m/a.v < b.m/b.v;
}

int main() {
    int n;
    double sum = 0, pack;
    cin >> n >> pack;
    vector<Node> gold(n);
    for(int i = 0; i < n; ++i) cin >> gold[i].m >> gold[i].v;
    sort(gold.begin(), gold.end(), cmp);
    for(int i = 0; i < n; ++i){
        if(pack >= gold[i].m){
            sum += gold[i].v;
            pack -= gold[i].m;
        } else{
            sum += pack * gold[i].v / gold[i].m;
            break;
        }
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}
