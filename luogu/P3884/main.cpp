#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    int val;
    int depth;
    Node* l;
    Node* r;
    Node* p;
    Node(int val, int depth) : val(val),depth(depth), l(nullptr), r(nullptr), p(nullptr) {}
    Node() : val(0),depth(0), l(nullptr), r(nullptr), p(nullptr) {}
};

void freeTree(Node* root){
    if(root == nullptr) return;
    if(root->l != nullptr) freeTree(root->l);
    if(root->r != nullptr) freeTree(root->r);
    delete root;
}

int main() {
    int n;
    cin >> n;
    vector<Node*> v;

    Node* root = new Node(1, 1);
    v.push_back(nullptr);
    v.push_back(root);
    int depth = 1;
    Node* cur = nullptr;

    for(int i = 0; i < n-1; ++i){
        int a, b;
        cin >> a >> b;
        if (a >= v.size()) v.resize(a + 1, nullptr);
        if (b >= v.size()) v.resize(b + 1, nullptr);

        Node* parent = v[a];
        Node* temp = new Node(b, parent->depth + 1);
        temp->p = parent;
        if (parent->l == nullptr) parent->l = temp;
        else parent->r = temp;

        v[b] = temp;

        if (temp->depth > depth) depth = temp->depth;
    }

    // 统计最大宽度
    vector<int> depthCount(depth + 1, 0);
    for (auto node : v) {
        if (node) depthCount[node->depth]++;
    }
    int length = *max_element(depthCount.begin(), depthCount.end());

    int x, y;
    cin >> x >> y;

    int depthX = v[x]->depth;
    int depthY = v[y]->depth;
    vector<bool> hasGone(n+2, false);
    cur = v[x];
    while(cur != nullptr){
        hasGone[cur->val] = true;
        cur = cur->p;
    }

    cur = v[y];
    while(!hasGone[cur->val]){
        cur = cur->p;
    }

    int depthLCA = cur->depth;
    int ans3 = (depthX - depthLCA)*2 + (depthY - depthLCA);
    cout << depth << endl << length << endl << ans3;
    freeTree(root);
    return 0;
}
