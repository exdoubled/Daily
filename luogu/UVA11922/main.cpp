/*
#include <iostream>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>

using namespace std;

struct Block {
    vector<int> d;
    bool lazy = false;
    Block(bool _lazy, vector<int> _d) : lazy(_lazy), d(std::move(_d)) {}
};

using BL = list<Block>;

void reverseLazy(BL::iterator it) {
    if (it->lazy) {
        reverse(it->d.begin(), it->d.end());
        it->lazy = false;
    }
}

BL::iterator split(BL& bl, BL::iterator it, int pos) {
    if (pos == 0) return it;
    if (pos == it->d.size()) return next(it);
    reverseLazy(it);

    Block newBlock(false, vector<int>(it->d.begin() + pos, it->d.end()));
    it->d.resize(pos);
    return bl.insert(next(it), newBlock);
}

BL getLR(int l, int r, BL& bl) {
    int pos = 0;
    auto it = bl.begin();
    while (it != bl.end() && pos + it->d.size() < l) {
        pos += it->d.size();
        ++it;
    }
    auto begin_it = split(bl, it, l - pos);

    it = begin_it;
    pos = l;
    while (it != bl.end() && pos + it->d.size() < r + 1) {
        pos += it->d.size();
        ++it;
    }
    auto end_it = split(bl, it, r + 1 - pos);

    BL ans;
    ans.splice(ans.begin(), bl, begin_it, end_it);
    return ans;
}

void maintain(BL& bl, int B) {
    for (auto it = bl.begin(); it != bl.end(); ) {
        while ((int)it->d.size() > 2 * B) {
            reverseLazy(it);
            vector<int> newD(it->d.begin() + B, it->d.end());
            it->d.resize(B);
            bl.insert(next(it), Block(false, newD));
        }

        if (it != bl.begin()) {
            auto prev = it; --prev;
            if ((int)prev->d.size() + (int)it->d.size() <= B) {
                reverseLazy(prev);
                reverseLazy(it);
                prev->d.insert(prev->d.end(), it->d.begin(), it->d.end());
                it = bl.erase(it);
                continue;
            }
        }
        ++it;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    int B = max(1, (int)sqrt(n));
    for (int i = 0; i < n; ++i) v[i] = i + 1;
    BL bl;
    bl.emplace_back(false, v);
    maintain(bl, B);

    while (m--) {
        int l, r; cin >> l >> r;
        --l; --r;
        BL LR = getLR(l, r, bl);
        LR.reverse();
        for (auto& block : LR) block.lazy = !block.lazy;
        bl.splice(bl.end(), LR);
        maintain(bl, B);
    }

    for (auto block = bl.begin(); block != bl.end(); ++block) {
        reverseLazy(block);
        for (int x : block->d) cout << x << " ";
    }

    return 0;
}
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_cxx;

int main() {
    int n, m;
    cin >> n >> m;
    rope<int> s,rs;
    for (int i = 1; i <= n; ++i ) {
        s.push_back(i);
        rs.push_front(i);
    }
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        rope<int> A = s.substr(0, l);
        rope<int> B = s.substr(l, r-l);
        rope<int> C = s.substr(r, n-r);
        rope<int> rA = rs.substr(n - l, l);
        rope<int> rB = rs.substr(n - r, r - l);
        rope<int> rC = rs.substr(0, n - r);
        s = A + C + rB;
        rs = B + rC + rA;
    }
    for (int i : s) cout << i << " ";
    return 0;
}