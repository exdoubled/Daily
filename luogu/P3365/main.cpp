#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* l;
    TreeNode* r;
    TreeNode* p;
};

TreeNode* createNode(int val) {
    TreeNode* newNode = new TreeNode;
    newNode->val = val;
    newNode->l = nullptr;
    newNode->r = nullptr;
    newNode->p = nullptr;
    return newNode;
}

void delNode(TreeNode* root) {
    if (!root) return;
    stack<pair<TreeNode*, bool>> s;
    s.emplace(root, false);
    while (!s.empty()) {
        auto [node, visited] = s.top();
        s.pop();
        if (!visited) {
            s.emplace(node, true);
            if (node->r) s.emplace(node->r, false);
            if (node->l) s.emplace(node->l, false);
        } else {
            delete node;
        }
    }
}

int ans(TreeNode* root, int n) {
    vector<int> v;
    stack<TreeNode*> s;
    TreeNode* cur = root;
    while (cur || !s.empty()) {
        if (cur) {
            s.push(cur);
            cur = cur->l;
        } else {
            TreeNode* temp = s.top();
            s.pop();
            v.push_back(temp->val);
            cur = temp->r;
        }
    }

    // 计算最长严格递增子序列
    vector<int> lis;
    for (int num : v) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    return n - lis.size();
}

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for (int i = 0; i < n; ++i) {
        cin >> vals[i];
    }

    vector<TreeNode*> nodes(n + 1);
    nodes[1] = createNode(vals[0]);

    for (int i = 2; i <= n; ++i) {
        int fa, ch;
        cin >> fa >> ch;
        TreeNode* parent = nodes[fa];
        nodes[i] = createNode(vals[i - 1]);
        if (ch == 0) {
            parent->l = nodes[i];
        } else {
            parent->r = nodes[i];
        }
        nodes[i]->p = parent;
    }

    cout << ans(nodes[1], n) << endl;

    delNode(nodes[1]);
    return 0;
}