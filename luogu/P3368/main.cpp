#include <iostream>
#include <vector>

using namespace std;

class TreeArray{
private:
    vector<int> tree;

    static int lowbit(int n){
        return n & (-n);
    }
public:
    TreeArray()= default;

    // 要求数组a第一个元素a[0]是0;
    TreeArray(vector<int>& nums){
        int n = (int)nums.size() - 1;
        tree.resize(n+1, 0);
        for(int i = 1; i <= n; ++i){
            add(i, nums[i]);
        }
    }

    // 单点修改
    void add(int pos, int value){
        while(pos <= tree.size()-1){
            tree[pos] = tree[pos] + value;
            pos += lowbit(pos);
        }
    }

    // 求出1~pos的和
    long long sum(int pos){
        long long res = 0;
        while(pos > 0){
            res += tree[pos];
            pos -= lowbit(pos);
        }
        return res;
    }

    // 输出区间和
    void getSum(int l, int r){
        cout << sum(r) - sum(l-1) << endl;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> nums(n+1);
    nums[0] = 0;
    for(int i = 1; i <= n; ++i) cin >> nums[i];

    vector<int> delta(n+1);
    delta[0] = delta[1] = 0;
    for(int i = 1; i <= n; ++i){
        delta[i] = nums[i] - nums[i-1];
    }

    TreeArray T(delta);
    for(int i = 0; i < m; ++i){
        int method;
        cin >> method;
        if(method == 1){
            int x, y, k;
            cin >> x >> y >> k;
            T.add(x, k);
            T.add(y+1, -k);
        }else if(method == 2){
            int x;
            cin >> x;
            T.getSum(1, x);
        }
    }
    return 0;
}
