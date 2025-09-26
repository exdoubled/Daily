#include <iostream>
#include <unordered_set>

using namespace std;

using ull = unsigned long long;

const ull mod1 = 212370440130137957;
const ull mod2 = 1e9 + 7;
const ull base = 131;

ull get_hash1(const string& s) {
    ull ans = 0;
    for (char c : s) {
        ans = (ans * base + static_cast<ull>(c)) % mod1;
    }
    return ans;
}

ull get_hash2(const string& s) {
    ull ans = 0;
    for (char c : s) {
        ans = (ans * base + static_cast<ull>(c)) % mod2;
    }
    return ans;
}

struct HashPair {
    ull h1, h2;
    HashPair(ull h1, ull h2) : h1(h1), h2(h2) {}
    bool operator==(const HashPair& other) const {
        return h1 == other.h1 && h2 == other.h2;
    }
};

namespace std {
    template<>
    struct hash<HashPair> {
        size_t operator()(const HashPair& p) const {
            return hash<ull>()(p.h1) ^ (hash<ull>()(p.h2) << 1);
        }
    };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<HashPair> set;

    while (n--) {
        string s;
        cin >> s;
        ull h1 = get_hash1(s);
        ull h2 = get_hash2(s);
        set.emplace(h1, h2);
    }

    cout << set.size() << endl;
    return 0;
}