#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

long long C(int n, int m, map<pair<int, int>, long long>& preC) {
    if (m < 0 || n < 0) return 0;
    if (m == 0 || n == m) return 1;
    if (m > n) return 0;
    auto key = make_pair(n, m);
    if (preC.find(key) != preC.end()) {
        return preC[key];
    }
    long long res = C(n - 1, m - 1, preC) + C(n - 1, m, preC);
    preC[key] = res;
    return res;
}

long long check(vector<int>& cnt, int n, map<pair<int, int>, long long>& allC) {
    long long ans = 1;
    int base = n;
    if (cnt[0] != 0) {
        int m = cnt[0];
        ans *= C(base - 1, m, allC);
        base -= m;
        if (base < 0) return 0;
    }

    for (int i = 1; i < 10; ++i) {
        int j = cnt[i];
        if (j == 0) continue;
        ans *= C(base, j, allC);
        base -= j;
        if (base < 0) return 0;
    }

    return ans;
}

void dfs(int i, int num, vector<int>& cnt, set<vector<int>>& opts, long long& ans, int n, int k, vector<int>& pow10_mod, map<pair<int, int>, long long>& allC) {
    int j = n - 1 - i;
    if (i > j) {
        if (num == 0) {
            if (!opts.count(cnt)) {
                opts.insert(cnt);
                ans += check(cnt, n, allC);
            }
        }
        return;
    }
    int start = (i == 0) ? 1 : 0;

    for (int a = start; a < 10; ++a) {
        int delta;
        if (i != j) {
            delta = (a * (pow10_mod[i] + pow10_mod[j])) % k;
        } else {
            delta = (a * pow10_mod[i]) % k;
        }
        delta %= k;
        int newNum = (num + delta) % k;
        if (newNum < 0) newNum += k;
        if (i != j) {
            cnt[a] += 2;
        } else {
            cnt[a] += 1;
        }
        dfs(i + 1, newNum, cnt, opts, ans, n, k, pow10_mod, allC);
        if (i != j) {
            cnt[a] -= 2;
        } else {
            cnt[a] -= 1;
        }
    }
}

long long countGoodIntegers(int n, int k) {
    if (k == 0) return 0;
    long long ans = 0;
    set<vector<int>> opts;
    vector<int> pow10_mod(n, 0);
    if (n > 0) {
        pow10_mod[0] = 1 % k;
        for (int i = 1; i < n; ++i) {
            pow10_mod[i] = (pow10_mod[i - 1] * 10) % k;
        }
    }
    vector<int> cnt(10, 0);
    map<pair<int, int>, long long> allC;
    dfs(0, 0, cnt, opts, ans, n, k, pow10_mod, allC);
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << countGoodIntegers(n, k);
    return 0;
}