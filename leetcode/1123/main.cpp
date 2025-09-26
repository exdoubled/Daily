#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(x), left(left), right(right) {}
};

int Dfs(TreeNode* root){
    if(!root) return 0;
    int l = Dfs(root->left);
    int r = Dfs(root->right);
    return max(l , r) + 1;
}

TreeNode* lcaDeepestLeaves(TreeNode* root){
    int l = Dfs(root->left);
    int r = Dfs(root->right);
    if(l == r) return root;
    else if (l > r) return lcaDeepestLeaves(root->left);
    return lcaDeepestLeaves(root->right);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
