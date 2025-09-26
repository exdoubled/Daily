#include <iostream>
#include <vector>

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

    void unite(int x, int y){
        father[find(x)] = find(y);
    }

    void erase(int pos){
        father[pos] = pos;
    }

};

int main() {
    int n, m, p;
    cin >> n >> m >> p;
    dsu set(n);
    while(m-- > 0){
        int a, b;
        cin >> a >> b;
        int min = std::min(a, b);
        int max = std::max(a, b);
        set.unite(min, max);
    }

    set.compress();
    while(p-- > 0){
        int a, b;
        cin >> a >> b;
        if(set.find(a) == set.find(b)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
