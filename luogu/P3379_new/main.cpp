#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Tree {
public:
    class TreeNode {
    public:
        int name;
        vector<TreeNode*> children;
        TreeNode* parent;
        vector<TreeNode*> ancestors;
        int depth;

        explicit TreeNode(int _name) : name(_name), parent(nullptr), depth(0) {}
    };

private:
    TreeNode* root;
    vector<TreeNode*> nodes;
    int maxLevel;

    void preprocessBinaryLifting() {
        for(int j = 1; j < maxLevel; ++j) {
            for(int i = 1; i < nodes.size(); ++i) {
                if(nodes[i] && nodes[i]->ancestors[j-1]) {
                    nodes[i]->ancestors[j] = nodes[i]->ancestors[j-1]->ancestors[j-1];
                }
            }
        }
    }

public:
    explicit Tree(int _root, const vector<vector<int>>& adj) {
        int n = (int)adj.size() - 1;
        nodes.resize(n + 1, nullptr);
        maxLevel = (int)log2(n) + 1;
        
        for (int i = 1; i <= n; ++i) {
            nodes[i] = new TreeNode(i);
            nodes[i]->ancestors.resize(maxLevel, nullptr);
        }
        root = nodes[_root];
        vector<bool> visited(n + 1, false);
        queue<TreeNode*> q;
        q.push(root);
        visited[root->name] = true;
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            for (int neighbor : adj[current->name]) {
                if (!visited[neighbor]) {
                    nodes[neighbor]->parent = current;
                    nodes[neighbor]->depth = current->depth + 1;
                    nodes[neighbor]->ancestors[0] = current;
                    current->children.push_back(nodes[neighbor]);
                    visited[neighbor] = true;
                    q.push(nodes[neighbor]);
                }
            }
        }
        preprocessBinaryLifting();
    }

    ~Tree() {
        for (TreeNode* node : nodes)
            delete node;
    }

    int findLCA(int a, int b) {
        TreeNode* nodeA = nodes[a];
        TreeNode* nodeB = nodes[b];
        if(!nodeA || !nodeB) return -1;
        if(nodeA->depth < nodeB->depth) swap(nodeA, nodeB);
        for(int i = maxLevel - 1; i >= 0; --i) {
            if(nodeA->ancestors[i] && nodeA->ancestors[i]->depth >= nodeB->depth) {
                nodeA = nodeA->ancestors[i];
            }
        }

        if(nodeA == nodeB) return nodeA->name;
        for(int i = maxLevel - 1; i >= 0; --i) {
            if(nodeA->ancestors[i] && nodeA->ancestors[i] != nodeB->ancestors[i]) {
                nodeA = nodeA->ancestors[i];
                nodeB = nodeB->ancestors[i];
            }
        }
        
        return nodeA->parent->name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, root;
    cin >> n >> m >> root;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    Tree tree(root, adj);

    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << tree.findLCA(a, b) << '\n';
    }

    return 0;
}