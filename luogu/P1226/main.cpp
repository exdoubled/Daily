#include <iostream>

using ll = long long;

ll quick_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    ll a, b, p;
    std::cin >> a >> b >> p;
    std::cout << a << "^" << b << " mod " << p << "=" << quick_pow(a, b, p);
    return 0;
}