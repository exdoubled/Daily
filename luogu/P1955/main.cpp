#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 并查集
template<typename T>
class DSU {
private:
    std::unordered_map<T, T> parent;
    std::unordered_map<T, int> rank;  // 用于按秩合并

public:
    // 查找根节点（带路径压缩）
    T find(const T& x) {
        // 自动添加未注册的节点
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            rank[x] = 0;
            return x;
        }

        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }

    // 合并两个集合（按秩合并）
    void unite(const T& x, const T& y) {
        T rootX = find(x);
        T rootY = find(y);

        if (rootX == rootY) return;

        // 按秩合并
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY]) {
                ++rank[rootY];
            }
        }
    }

    // 判断是否连通
    bool connected(const T& x, const T& y) {
        return find(x) == find(y);
    }

    // 重置元素
    void reset(const T& x) {
        parent.erase(x);
        rank.erase(x);
    }

    // 清空并查集
    void clear() {
        parent.clear();
        rank.clear();
    }
};

int main() {
    // 加快输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    // 输入每一组数据
    while(t-- > 0){
        int n;
        cin >> n;

        DSU<int> setTrue;
        vector<pair<int, int>> setFalse;

        int numN = n;
        while(numN-- > 0){
            int x, y, method;
            cin >> x >> y >> method;
            if(method == 1){
                setTrue.unite(x, y);
            } else if(method == 0){
                setFalse.emplace_back(x, y);
            }
        }

        bool key = true;
        for(auto &keys : setFalse){
            if(setTrue.find(keys.first) == setTrue.find(keys.second)) {
                key = false;
                break;
            }
        }
        cout << (key ? "YES" : "NO") << endl;
    }
    return 0;
}
