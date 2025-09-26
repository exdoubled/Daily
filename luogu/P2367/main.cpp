#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> delta(n+1);
    vector<int> a(n+1);
    delta[0] = a[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        delta[i] = a[i] - a[i-1];
    }
    while(p-- > 0){
        int l,r,t;
        cin >> l >> r >> t;
        delta[l] += t;
        if(r != n) delta[r+1] -= t;
    }

    int min = INT32_MAX;
    for(int i = 1; i <= n; ++i){
        a[i] = a[i-1] + delta[i];
        min = min <= a[i] ? min : a[i];
    }
    cout << min;
    return 0;
}
