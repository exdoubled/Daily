#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void init(int n, vector<int>& primes, vector<bool>& not_prime) {
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) {
            primes.push_back(i);
        }
        for (int prime : primes) {
            if (i * prime > n) break;
            not_prime[i * prime] = true;
            if (i % prime == 0) break;
        }
    }
}

int find_start(const vector<int>& primes, int k) {
    for (size_t i = 0; i < primes.size(); ++i) {
        if (primes[i] >= k) {
            return (int)i;
        }
    }
    return (int)primes.size();
}

class DSU {
private:
    vector<int> parent;

public:
    explicit DSU(int size) {
        parent.resize(size + 1);
        for (int i = 0; i <= size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r, k;
    cin >> l >> r >> k;

    vector<int> primes;
    vector<bool> not_prime(r + 1, false);
    init(r, primes, not_prime);

    int begin = find_start(primes, k);
    int offset = l;
    int size = r - l + 1;
    DSU set(size);

    for (int idx = begin; idx < primes.size(); ++idx) {
        int p = primes[idx];
        if (p > r) break;

        int first = ((l + p - 1) / p) * p;
        if (first > r) continue;

        int base = first - offset + 1;
        for (int x = first; x <= r; x += p) {
            int node = x - offset + 1;
            set.unite(base, node);
        }
    }

    unordered_set<int> roots;
    for (int i = 1; i <= size; ++i) {
        roots.insert(set.find(i) + offset - 1);
    }

    cout << roots.size();

    return 0;
}