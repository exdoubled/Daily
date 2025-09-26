#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

int numEquivDominoPairs(vector<vector<int>>& dominoes){
    unordered_map<pair<int, int>, int, pair_hash> count;
    for (auto& d : dominoes) {
        int a = d[0];
        int b = d[1];
        if (a > b) swap(a, b);
        pair<int, int> key(a, b);
        ++count[key];
    }
    int ans = 0;
    for (auto & it : count) {
        int cnt = it.second;
        ans += cnt * (cnt - 1) / 2;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
