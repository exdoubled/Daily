#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n,m;
    cin >> m;
    n = (int)pow(2, m);
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int maxL = -1, maxLi, maxR = -1, maxRi;
    for(int i = 0; i < n/2; ++i){
        if(maxL < v[i]){
            maxL = v[i];
            maxLi = i+1;
        }
    }
    for(int i = n/2; i < n; ++i){
        if(maxR < v[i]){
            maxR = v[i];
            maxRi = i+1;
        }
    }
    if(maxL < maxR) cout << maxLi;
    else cout << maxRi;
    return 0;
}
