#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    vector<int> lch(n + 1, 0), rch(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int fa, ch;
        cin >> fa >> ch;
        int current_node = i + 2;
        if (ch == 0) {
            lch[fa] = current_node;
        } else {
            rch[fa] = current_node;
        }
    }

    // 中序遍历
    vector<long long> inorder;
    stack<int> stk;
    int current = 1;
    while (!stk.empty() || current != 0) {
        if (current != 0) {
            stk.push(current);
            current = lch[current];
        } else {
            current = stk.top();
            stk.pop();
            inorder.push_back(vals[current - 1]);
            current = rch[current];
        }
    }

    for (int i = 0; i < (int)inorder.size(); i++){
        inorder[i] -= i;
    }

    vector<long long> lis;
    for (long long num : inorder) {
        auto it = upper_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    cout << n - lis.size();
    return 0;
}
