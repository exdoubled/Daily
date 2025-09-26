#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Tree{
public:
   class TreeNode{
    public:
        int name;
        vector<TreeNode*> nexts;
        TreeNode* p;
        explicit TreeNode(int _name) {
            name = _name;
            p = nullptr;
        }
    };

private:
    TreeNode* root;
    vector<TreeNode*> v;

public:
    explicit Tree(int _root, const vector<vector<int>>& adj){
        root = new TreeNode(_root);
        int n = (int)adj.size() - 1;
        v.resize(n+1);
        v[root->name] = root;
        vector<bool> visited(n+1);
        queue<TreeNode*> q;
        q.push(root);
        visited[root->name] = true;
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(auto next : adj[cur->name]){
                if(!visited[next]){
                    auto* nextNode = new TreeNode(next);
                    v[next] = nextNode;
                    cur->nexts.push_back(nextNode);
                    nextNode->p = cur;
                    visited[next] = true;
                    q.push(nextNode);
                }
            }
        }
    }

    ~Tree(){
        for(auto node : v){
            if(node == nullptr) continue;
            else{
                delete node;
            }
        }
    }

    int question(int a, int b, const vector<vector<int>>& adj){
        int n = (int)adj.size()-1;
        vector<bool> visited(n+1, false);
        if(a == b) return a;
        else{
            TreeNode* cur = v[a];
            while(cur != nullptr){
                visited[cur->name] = true;
                cur = cur->p;
            }
            cur = v[b];
            while(!visited[cur->name]){
                cur = cur->p;
            }
            return cur->name;
        }

    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, root;
    cin >> n >> m >> root;
    vector<vector<int>> adj(n+1);
    while(--n > 0){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    Tree T(root, adj);

    while(m-- > 0){
        int a, b;
        cin >> a >> b;
        cout << T.question(a,b,adj) << endl;
    }

    return 0;
}
