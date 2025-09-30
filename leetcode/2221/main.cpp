#include <iostream>
#include <vector>

using namespace std;

/*
long long exgcd(long long a,long long b,long long& x,long long& y){
    if(a%b == 0){
        x = 0,y = 1;
        return b;
    }
    long long r,tx,ty;
    r = exgcd(b, a%b, tx, ty);
    x = ty;
    y = tx - a/b*ty;
    return r;
}
long long comp(long long a, long long b, long long m){
    if(a < b) return 0;
    if(a == b) return 1;
    if(b > a-b) b = a-b;
    long long ans = 1, ca = 1, cb = 1;
    for(int i = 0; i < b; ++i){
        ca = ca * (a-i) % m;
        cb = cb * (b-i) % m;
    }
    long long x, y;
    exgcd(cb, m, x, y);
    x = (x%m + m) % m;
    ans = ca * x % m;
    return ans;
}

long long lucas(long long a, long long b, long long m){
    long long ans = 1;
    while(a && b){
        ans = (ans * comp(a%m, b%m, m)) % m;
        a /= m;
        b /= m;
    }
    return ans;
}

long long exlucas(long long n, long long k, long long m){
    long long res = 0, mod = m;
    std::vector<long long> pi, ai;
    for(long long i = 2; i * i <= m; ++i){
        if(m % i == 0){
            long long p = 1;
            while(m % i == 0){
                p *= i;
                m /= i;
            }
            pi.push_back(p);
            ai.push_back(lucas(n, k, p));
        }
    }
    if(m > 1){
        pi.push_back(m);
        ai.push_back(lucas(n, k, m));
    }
    for(int i = 0; i < pi.size(); ++i){
        long long M = mod / pi[i], x, y;
        exgcd(M, pi[i], x, y);
        x = (x % pi[i] + pi[i]) % pi[i];
        res = (res + M * x % mod * ai[i] % mod) % mod;
    }
    return res;
}

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    int mod = 10;
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = (ans + nums[i] * exlucas(n-1, i, mod)) % mod;
    return ans;
}
*/
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            nums[j] = (nums[j] + nums[j + 1]) % 10;
        }
    }
    return nums[0];
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}