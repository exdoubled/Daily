#include <iostream>
#include <string>

using namespace std;

struct Node{
    char c;
    Node* l;
    Node* r;
    Node(char c) : c(c), l(nullptr), r(nullptr) {}
};

Node* createTree(string& mid, string& fir, int lm, int rm, int lf, int rf){
    if(lf > rf) return nullptr;
    char c = fir[lf];
    int cur = lm;
    while(mid[cur] != c) ++cur;
    int cnt = cur - lm;
    Node* root = new Node(c);
    root->l = createTree(mid, fir, lm, cur-1, lf+1, lf+cnt);
    root->r = createTree(mid, fir,cur+1, rm, lf+cnt+1, rf);
    return root;
}

void dfs(Node* root, string& ans){
    if(root == nullptr)return;
    dfs(root->l, ans);
    dfs(root->r, ans);
    ans.push_back(root->c);
}

void freeTree(Node* root){
    if(root == nullptr) return;
    if(root->l == nullptr && root->r == nullptr) delete root;
    else if(root->l != nullptr) freeTree(root->l);
    else freeTree(root->r);
}

int main() {
    string a, b, c;
    cin >> a >> b;
    int n = (int)a.size()-1;
    Node* root = createTree(a,b,0,n,0,n);
    dfs(root, c);
    cout << c;
    freeTree(root);
    return 0;
}
