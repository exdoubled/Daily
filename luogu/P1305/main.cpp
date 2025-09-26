#include <iostream>
#include <unordered_map>

using namespace std;

struct Node{
    char c;
    Node* l;
    Node* r;
    Node() : c(0), l(nullptr), r(nullptr) {}
    explicit Node(char _c) : c(_c), l(nullptr), r(nullptr) {}
};

void dfs(Node* root){
    if(root == nullptr) return;
    cout << root->c;
    dfs(root->l);
    dfs(root->r);
}

void deleteTree(Node* root){
    if(root == nullptr) return;
    deleteTree(root->l);
    deleteTree(root->r);
    delete root;
}

int main() {
    int n;
    cin >> n;
    unordered_map<char, Node*> map;
    bool key = true;
    char root;
    while(map.size() != n){
        char p, l, r;
        cin >> p >> l >> r;
        if(key){
            root = p;
            key = false;
        }
        Node *parent, * left, * right;
        if(map.count(p) != 0){
            parent = map[p];
        } else{
            map[p] = parent = new Node(p);
        }
        if(l == '*'){
            left = nullptr;
        } else{
            if(map.count(l) != 0){
                left = map[l];
            } else{
                map[l] = left = new Node(l);
            }
        }
        if(r == '*'){
            right = nullptr;
        } else{
            if(map.count(r) != 0){
                right = map[r];
            } else{
                map[r] = right = new Node(r);
            }
        }
        parent->l = left;
        parent->r = right;
    }
    dfs(map[root]);
    deleteTree(map[root]);
    return 0;
}
