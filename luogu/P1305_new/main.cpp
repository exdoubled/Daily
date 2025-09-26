#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node{
    char c{};
    int l{};
    int r{};
};

void dfs(vector<Node>& tree, int root){
    if(root == 0) return;
    cout << tree[root].c;
    dfs(tree, tree[root].l);
    dfs(tree, tree[root].r);
}

int main() {
    int n;
    cin >> n;
    vector<Node> tree(n+1);
    unordered_map<char, int> f;
    bool key = true;
    char root;
    int nodeCNT = 1;
    for(int i = 0; i < n; ++i){
        char p, l ,r;
        cin >> p >> l >> r;

        if(key){
            root = p;
            key = false;
        }
        int parent, left, right;
        if(f.count(p) != 0) parent = f[p];
        else f[p] = parent = nodeCNT++;

        if(l == '*') left = 0;
        else{
            if(f.count(l) != 0) left = f[l];
            else f[l] = left = nodeCNT++;
        }

        if(r == '*') right = 0;
        else{
            if(f.count(r) != 0) right = f[r];
            else f[r] = right = nodeCNT++;
        }

        tree[parent].c = p;
        tree[parent].l = left;
        tree[tree[parent].l].c = l;
        tree[parent].r = right;
        tree[tree[parent].r].c = r;
    }
    dfs(tree, f[root]);

    return 0;
}
