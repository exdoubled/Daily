#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class dsu{
private:
    // father为0 1 2 3 4....
    int size;
    vector<int> father;

public:
    explicit dsu(int _size){
        size = _size;
        father.resize(_size+1, 0);
        for(int i = 1; i <= size; ++i) father[i] = i;
    }

    void insert(int cur, int curFather){
        int maxNum = max(cur, curFather);
        if(size < maxNum){
            father.resize(maxNum+1, 0);
            size = maxNum;
        }
        father[cur] = curFather;
    }

    // 查找一个集合的根节点
    int find(int pos){
        while(father[pos] != pos) pos = father[pos];
        return pos;
        // return father[x] == x ? x : find(father[pos])
    }

    // 压缩路径
    void compress(){
        for(int pos = 1; pos <= size; ++pos){
            if(father[pos] != pos){
                father[pos] = find(pos);
            }
        }
    }

    // 合并两个树
    void unite(int x, int y){
        int maxNum = max(x, y);
        if(size < maxNum){
            size = maxNum;
            father.resize(maxNum+1, 0);
            for(int i = 1; i <= size; ++i) father[i] = i;
        }
        father[find(x)] = find(y);
    }

    void erase(int pos){
        father[pos] = pos;
    }

};

int main() {
    while(true){
        int n, m;
        cin >> n;
        if(n == 0) break;
        cin >> m;
        dsu set(n);
        while(m-- > 0){
            int a,b;
            cin >> a >> b;
            set.unite(a,b);
        }
        unordered_set<int> node;
        for(int i = 1; i <= n; ++i){
            node.insert(set.find(i));
        }
        cout << node.size()-1 << endl;
    }
    return 0;
}
