#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> primes;

    if (n >= 2) {
        vector<char> is_prime(n + 1, 1);
        is_prime[0] = is_prime[1] = 0;
        int sqrt_n = sqrt(n);
        for (int i = 2; i <= sqrt_n; ++i) {
            if (is_prime[i]) {
                for (long long j = (long long)i * i; j <= n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
    }

    while (q--) {
        int k;
        cin >> k;
        cout << primes[k - 1] << "\n";
    }
    return 0;
}