#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long mod = 666623333;

void Euler(int length, vector<int>& primes) {
    vector<bool> is_prime(length + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= length; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= length; ++j) {
            is_prime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

int main() {
    long long l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<long long> phi(n);
    vector<long long> val(n);

    for (int i = 0; i < n; ++i) {
        phi[i] = l + i;
        val[i] = l + i;
    }

    long long max_prime = static_cast<long long>(sqrt(r));
    vector<int> primes;
    Euler(max_prime, primes);

    for (int pr : primes) {
        long long first = l % pr == 0 ? l : l + (pr - l % pr);
        if (first > r) continue;

        for (long long j = first; j <= r; j += pr) {
            int idx = j - l;
            if (val[idx] % pr != 0) continue;
            phi[idx] = phi[idx] / pr * (pr - 1);
            while (val[idx] % pr == 0) {
                val[idx] /= pr;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (val[i] > 1) {
            phi[i] = phi[i] / val[i] * (val[i] - 1);
        }
        ans = (ans + (l + i) - phi[i]) % mod;
    }

    cout << ans << endl;
    return 0;
}