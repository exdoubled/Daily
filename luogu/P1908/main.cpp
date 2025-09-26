#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 树状数组
class TreeArray{
private:
    vector<int> tree;

    static int lowbit(int n){
        return n & (-n);
    }
public:
    TreeArray()= default;

    explicit TreeArray(int n){
        tree.resize(n+1, 0);
    }

    // 要求数组a第一个元素a[0]是0;
    explicit TreeArray(vector<int>& nums){
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
    long long getSum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

// 离散化
struct Node{
    long long val{};
    int pos{};
};

bool cmp(Node& a, Node& b){
    if(a.val == b.val) return a.pos < b.pos;
    return a.val < b.val;
}

int main() {
    // 加快输入输出
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 输入数组
    int n;
    cin >> n;
    vector<Node> nums(n+1);
    for(int i = 1; i <= n; ++i) {
        cin >> nums[i].val;
        nums[i].pos = i;
    }

    // 对数组进行离散化
    // algorithm 里面的排序是快速排序，时间复杂度O(n*log(n))
    sort(nums.begin()+1, nums.end(), cmp);
    TreeArray T(n);

    // 利用树状数组求逆序数，时间复杂度O(n*log(n))
    long long ans = 0;
    for(int i = n; i > 0; --i){
        T.add(nums[i].pos, 1);
        ans += T.sum(nums[i].pos-1);
    }
    cout << ans;
    return 0;
}
