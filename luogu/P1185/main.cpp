#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>

using namespace std;

const char spaceChar = 32;
const char nodeChar = 'o';

struct Node {
    int x;
    int y;
    Node(int x, int y) : x(x), y(y) {}
    Node() : x(0), y(0) {}
};

// 输出这棵树
void print(vector<vector<char>>& tree) {
    int n = (int)tree.size();
    int m = (int)tree[0].size();
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            cout << tree[i][j];
        }
        cout << endl;
    }
}

bool limit(vector<vector<char>>& tree, vector<vector<Node>>& nodes, int x, int y) {
    if (x < 0 || x >= (int)nodes.size()) return false;
    if (y < 0 || y >= (int)nodes[x].size()) return false;

    int realX = nodes[x][y].x;
    int realY = nodes[x][y].y;
    int maxH = (int)tree.size();
    int maxW = (int)tree[0].size();

    return realX >= 0 && realX < maxH && realY >= 0 && realY < maxW &&
           realX != INT32_MAX && realY != INT32_MAX;
}

void deleteTreeNode(vector<vector<char>>& tree, vector<vector<Node>>& nodes, int x, int y) {
    if (!limit(tree, nodes, x, y)) return;

    int parentX = x - 1;
    int parentY = (y + 1) / 2;

    if (parentX >= 1 && limit(tree, nodes, parentX, parentY)) {
        int childRealX = nodes[x][y].x;
        int childRealY = nodes[x][y].y;
        int parentRealX = nodes[parentX][parentY].x;
        int parentRealY = nodes[parentX][parentY].y;

        int deltaX = childRealX - parentRealX;

        if (childRealY < parentRealY) {
            for (int i = 1; i <= deltaX - 1; ++i) {
                int currX = parentRealX + i;
                int currY = parentRealY - i;
                if (currX >= 0 && currX < (int)tree.size() && currY >= 0 && currY < (int)tree[0].size()) {
                    tree[currX][currY] = spaceChar;
                }
            }
        } else {
            for (int i = 1; i <= deltaX - 1; ++i) {
                int currX = parentRealX + i;
                int currY = parentRealY + i;
                if (currX >= 0 && currX < (int)tree.size() && currY >= 0 && currY < (int)tree[0].size()) {
                    tree[currX][currY] = spaceChar;
                }
            }
        }
    }

    queue<pair<int, int>> q;
    q.emplace(x, y);

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();
        int currX = curr.first;
        int currY = curr.second;

        if (!limit(tree, nodes, currX, currY)) continue;

        int realX = nodes[currX][currY].x;
        int realY = nodes[currX][currY].y;
        tree[realX][realY] = spaceChar;

        int leftChildX = currX + 1;
        int leftChildY = 2 * currY - 1;
        if (limit(tree, nodes, leftChildX, leftChildY)) {
            int leftRealX = nodes[leftChildX][leftChildY].x;

            int deltaX = leftRealX - realX;
            for (int i = 1; i <= deltaX - 1; ++i) {
                int x_pos = realX + i;
                int y_pos = realY - i;
                if (x_pos >= 0 && x_pos < (int)tree.size() && y_pos >= 0 && y_pos < (int)tree[0].size()) {
                    tree[x_pos][y_pos] = spaceChar;
                }
            }

            q.emplace(leftChildX, leftChildY);
        }

        int rightChildX = currX + 1;
        int rightChildY = 2 * currY;
        if (limit(tree, nodes, rightChildX, rightChildY)) {
            int rightRealX = nodes[rightChildX][rightChildY].x;

            int deltaX = rightRealX - realX;
            for (int i = 1; i <= deltaX - 1; ++i) {
                int x_pos = realX + i;
                int y_pos = realY + i;
                if (x_pos >= 0 && x_pos < (int)tree.size() && y_pos >= 0 && y_pos < (int)tree[0].size()) {
                    tree[x_pos][y_pos] = spaceChar;
                }
            }

            q.emplace(rightChildX, rightChildY);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<Node>> Nodes(n + 2);
    for (int i = 0; i <= n + 1; ++i) {
        int t = (i == 0) ? 0 : (int)pow(2, i - 1);
        vector<Node> temp(t + 1, Node(INT32_MAX, INT32_MAX));
        Nodes[i] = temp;
    }
    // 生成节点相应的公式
    vector<int> sameTreeSpace(n + 1);
    vector<int> diffTreeSpace(n + 1);
    vector<int> startPos(n + 1);
    vector<int> heightNToN_1(n + 1);
    sameTreeSpace[n] = 3;
    diffTreeSpace[n] = 1;
    startPos[n] = 1;
    heightNToN_1[n] = 1;
    for (int i = n - 1; i > 0; --i) {
        sameTreeSpace[i] = sameTreeSpace[i + 1] + diffTreeSpace[i + 1] + 1;
        diffTreeSpace[i] = sameTreeSpace[i];
        startPos[i] = startPos[i + 1] + sameTreeSpace[i + 1] / 2 + 1;
        heightNToN_1[i] = sameTreeSpace[i] / 2;
    }
    int width = (int)(pow(2, n - 2) * (sameTreeSpace[n] + diffTreeSpace[n] + 2) - diffTreeSpace[n]);
    int height = (width + 1) / 2;
    vector<vector<char>> tree(height + 1, vector<char>(width + 1, spaceChar));

    // 生成结点和树枝
    int curHeight = height;
    // 逐层绘制
    for (int level = n; level > 0; --level) {
        int nodeNum = (int)pow(2, level - 1);
        int nodeNumConst = nodeNum;
        int cur = startPos[level];
        // 每一层从左到右绘制
        while (nodeNum-- > 0) {
            tree[curHeight][cur] = nodeChar;
            // Node[x][y] 中的 x储存实际图的x y储存实际图的y
            Nodes[level][nodeNumConst - nodeNum].x = curHeight;
            Nodes[level][nodeNumConst - nodeNum].y = cur;
            // 找到下一个点并且画出树枝
            if (nodeNum % 2 == 1 && level != 1) {
                int tempHeight = heightNToN_1[level];
                int i = 1;
                while (tempHeight-- > 0) {
                    tree[curHeight - i][cur + i] = '/';
                    i++;
                }
                cur += sameTreeSpace[level] + 1;
            }
            else if (nodeNum % 2 == 0 && level != 1) {
                int tempHeight = heightNToN_1[level];
                int i = 1;
                while (tempHeight-- > 0) {
                    tree[curHeight - i][cur - i] = '\\';
                    i++;
                }
                cur += diffTreeSpace[level] + 1;
            }
        }
        curHeight -= heightNToN_1[level] + 1;
    }


    // 输入操作
    vector<vector<int>> ops(k, vector<int>(2));
    for (int i = 0; i < k; ++i) cin >> ops[i][0] >> ops[i][1];
    for (int i = 0; i < k; ++i) {
        deleteTreeNode(tree, Nodes, ops[i][0], ops[i][1]);
    }
    print(tree);
    return 0;
}