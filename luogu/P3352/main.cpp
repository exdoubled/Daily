#include <iostream>
#include <vector>

using namespace std;

int mod = 10e9 + 7;

template <typename T>
class SegTreeLazyRangeSet {
    vector<T> tree, lazy;		// 线段树数组和懒标记数组
    vector<T> *arr;			// 指向原始数组的指针
    vector<bool> ifLazy;		// 标记是否有懒标记（因为懒标记值可能为0）
    int n, root, n4, end;		// 数组长度、根节点索引、4倍长度、末尾索引

    // 维护懒标记：将懒标记值下推到子节点
    void maintain(int cl, int cr, int p) {
        int cm = cl + (cr - cl) / 2;
        if (cl != cr && ifLazy[p]) {		// 如果不是叶子节点且有懒标记
            lazy[p * 2] = lazy[p], ifLazy[p * 2] = 1;
            lazy[p * 2 + 1] = lazy[p], ifLazy[p * 2 + 1] = 1;
            tree[p * 2] = lazy[p] * (cm - cl + 1);
            tree[p * 2 + 1] = lazy[p] * (cr - cm);
            lazy[p] = 0;
            ifLazy[p] = 0;
        }
    }

    // 区间查询：查询区间 [l, r] 的和
    T range_sum(int l, int r, int cl, int cr, int p) {
        if (l <= cl && cr <= r) return tree[p];
        int m = cl + (cr - cl) / 2;
        T sum = 0;
        maintain(cl, cr, p);
        if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
        if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
        return sum;
    }

    // 区间设置：将区间 [l, r] 的所有元素设置为 val
    void range_set(int l, int r, T val, int cl, int cr, int p) {
        if (l <= cl && cr <= r) {
            lazy[p] = val;
            ifLazy[p] = 1;
            tree[p] = (cr - cl + 1) * val;
            return;
        }
        int m = cl + (cr - cl) / 2;
        maintain(cl, cr, p);
        if (l <= m) range_set(l, r, val, cl, m, p * 2);
        if (r > m) range_set(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

    // 构建线段树
    void build(int s, int t, int p) {
        if (s == t) {
            tree[p] = (*arr)[s];
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }

public:
    // 构造函数：用给定向量初始化线段树
    explicit SegTreeLazyRangeSet<T>(vector<T> v) {
        n = v.size();
        n4 = n * 4;						// 分配4倍空间
        tree = vector<T>(n4, 0);		// 初始化线段树数组
        lazy = vector<T>(n4, 0);		// 初始化懒标记数组
        ifLazy = vector<bool>(n4, 0);	// 初始化懒标记存在标记数组
        arr = &v;						// 保存原始数组指针
        end = n - 1;					// 末尾索引
        root = 1;						// 根节点索引（从1开始）
        build(0, end, 1);				// 构建线段树
        arr = nullptr;					// 构建完成后释放指针
    }

    // 打印线段树结构（用于调试）
    void show(int p, int depth = 0) {
        if (p > n4 || tree[p] == 0) return;				// 超出范围或空值则返回
        show(p * 2, depth + 1);							// 先递归打印左子树
        for (int i = 0; i < depth; ++i) putchar('\t');	// 根据深度缩进
        printf("%d:%d\n", tree[p], lazy[p]);			// 打印节点值和懒标记值
        show(p * 2 + 1, depth + 1);						// 递归打印右子树
    }

    // 对外接口：区间查询 [l, r]
    T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

    // 对外接口：区间设置 [l, r] 的所有元素为 val
    void range_set(int l, int r, T val) { range_set(l, r, val, 0, end, root); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    return 0;
}
