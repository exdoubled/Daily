#include <iostream>
#include <queue>
#include <vector>

// 读错题但AC幽默大赏
using namespace std;

struct Node{
    int val;
    int pos;
    int depth;
    Node* p;
    Node* l;
    Node* r;
    Node(int val, int pos, int depth) : val(val), pos(pos), depth(depth), l(nullptr), r(nullptr), p(nullptr) {}
};

void freeTree(Node* root){
    if(root == nullptr) return;
    if(root->l != nullptr) freeTree(root->l);
    if(root->r != nullptr) freeTree(root->r);
    if(root->l == nullptr && root->r == nullptr) delete root;
}

void dfs(vector<Node*>& tree, Node* cur, int& ans, int size, vector<bool>& hasGone){
    if(cur == nullptr) return;
    if(cur->p != nullptr && !hasGone[cur->p->pos]){
        hasGone[cur->pos] = true;
        dfs(tree, cur->p, ans, size+1, hasGone);
    }
    if(cur->l != nullptr && !hasGone[cur->l->pos]){
        hasGone[cur->pos] = true;
        dfs(tree, cur->l, ans, size+1, hasGone);
    }
    if(cur->r != nullptr && !hasGone[cur->r->pos]){
        hasGone[cur->pos] = true;
        dfs(tree, cur->r, ans, size+1, hasGone);
    }
    ans += cur->val * size;
}

int main() {
    int k;
    cin >> k;

    vector<Node*> v;
    v.push_back(nullptr);
    // 输入数据
    queue<Node*> q;
    int depth = 0;
    Node *root = new Node(0, 1, depth);
    q.push(root);
    q.push(nullptr);
    while(true){
        Node* cur = q.front();
        q.pop();
        if(cur == nullptr){
            if(q.empty()) break;
            depth++;
            q.push(nullptr);
        } else{
            int val;
            int l;
            int r;
            cin >> val >> l >> r;
            cur->val = val;
            v.push_back(cur);
            if(l != 0){
                Node *temp = new Node(0,l,depth+1);
                cur->l = temp;
                temp->p = cur;
                q.push(temp);
            } else{
                cur->l = nullptr;
            }
            if(r != 0){
                Node *temp = new Node(0,r,depth+1);
                cur->r = temp;
                temp->p = cur;
                q.push(temp);
            } else{
                cur->r = nullptr;
            }
        }
    }

    int n = (int)v.size();
    int ans = INT32_MAX;

    for(int i = 1; i < n; ++i){
        int temp = 0;
        vector<bool> hasGone(n, false);
        dfs(v, v[i], temp, 0, hasGone);
        ans = ans < temp ? ans : temp;
    }
    cout << ans;
    freeTree(root);
    return 0;
}
