#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int numTilings(int n){
    vector<int> f(n+1);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; ++i) f[i] = ((2*f[i-1])%mod + f[i-3]%mod) % mod;
    return f[n];
}

int main() {
    int n;
    cin >> n;
    cout << numTilings(n);
    return 0;
}
