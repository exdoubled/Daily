#include <iostream>
#include <vector>

using namespace std;

class DSU{
private:
    std::vector<int> parent;
    int capacity;

public:
    explicit DSU(int init_size = 0) {
        capacity = init_size;
        parent.resize(init_size + 1);  // 1-based indexing
        for (int i = 0; i <= init_size; ++i) {
            parent[i] = i;
        }
    }

    // 带路径压缩的查找
    int find(int x) {
        if (x >= parent.size()) {
            extend(x);
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // 路径压缩
        }
        return parent[x];
    }

    // 合并操作
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

private:
    // 动态扩展存储空间
    void extend(int new_max) {
        int old_size = (int)parent.size();
        if (new_max >= old_size) {
            parent.resize(new_max + 2);  // +2保证足够空间
            for (int i = old_size; i <= new_max + 1; ++i) {
                parent[i] = i;  // 初始化新增元素
            }
            capacity = new_max;
        }
    }

public:
    void reset(int x) {
        if (x < parent.size()) {
            parent[x] = x;
        }
    }

    int size() const {
        return capacity;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for(int i = 0; i < m; ++i){
        int x, y, z;
        cin >> z >> x >> y;
        if(z == 1) dsu.unite(x, y);
        if(z == 2) {
            if(dsu.find(x) == dsu.find(y)) cout << "Y" << endl;
            else cout << "N" <<endl;
        }
    }
    return 0;
}
