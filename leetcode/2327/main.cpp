#include <iostream>
#include <vector>

using namespace std;

long long mod = 1000000007;

int peopleAwareOfSecret(int n, int delay, int forget){
    if(delay >= forget) return 0;

    vector<int> dp(n, 0);
    vector<int> share(n, 0); // share[i] 代表第 i 天有多少人分享
    vector<int> forgets(n, 0); // forgets[i] 代表第 i 天有多少人忘记
    dp[0] = 1;
    for(int i = 1; i < n; ++i){
        if(i - delay >= 0) share[i] = dp[i - delay];
        if(i - forget >= 0) forgets[i] = dp[i - forget];
        dp[i] = (int)(((long long)dp[i-1] - (long long)forgets[i] + (long long)share[i]) % mod);
    }
    return (int)(((long long)dp[n-1] - (long long)forgets[n-1] + 2*mod) % mod);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
