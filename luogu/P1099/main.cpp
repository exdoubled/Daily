#include <iostream>
#include <vector>

using namespace std;

// 搜索最长路径
void dfs(int cur, vector<int>& path, double& maxDistance, double curDistance, vector<bool>& visit, vector<int>& ans, vector<vector<double>>& adj){
    if(curDistance > maxDistance){
        maxDistance = curDistance;
        ans.clear();
        ans = path;
    }
    int n = (int)adj.size();
    for(int i = 1; i < n; ++i){
        if((bool)adj[cur][i] && !visit[i]){
            curDistance += adj[cur][i];
            path.push_back(i);
            visit[i] = true;
            dfs(i, path, maxDistance, curDistance, visit, ans, adj);
            curDistance -= adj[cur][i];
            path.pop_back();
            visit[i] = false;
        }
    }
}

// 搜索最短偏心距
void dfsLen(double& curLength, int l, int r, double& midToL, double& midToR, vector<vector<double>>& adj, int& s, int& begin, int& end, vector<int>& nodes, int& ans){
    if(curLength > s) return;
    else{
        int n = (int)nodes.size();
        int now = (int)max(adj[nodes[l+1]][begin], adj[nodes[r-1]][end]);
        ans = min(now, ans);
        if(l >= 0 && (bool)midToL){ // 有左搜索左
            curLength += midToL;
            double nextMidToL = (l == 0) ? 0 : adj[nodes[l]][nodes[l-1]];
            dfsLen(curLength, l-1, r, nextMidToL, midToR, adj, s, begin, end, nodes, ans);
            curLength -= midToL;
        }
        if(r < n && (bool)midToR){ // 有右搜索右
            curLength += midToR;
            double nextMidToR = (r == n-1) ? 0 : adj[nodes[r]][nodes[r+1]];
            dfsLen(curLength, l, r+1, midToL, nextMidToR, adj, s, begin, end, nodes, ans);
            curLength -= midToR;
        }
    }
}

int main() {
    int n, s;
    cin >> n >> s;
    vector<vector<double>> adj(n+1, vector<double>(n+1, 0));
    vector<bool> visit(n+1, false);
    while(--n > 0){
        int from, to;
        double distance;
        cin >> from >> to >> distance;
        adj[from][to] = adj[to][from] = distance;
    }

    // 先随机选取一个结点进行 dfs
    vector<int> nodes, path;
    double maxDistance = 0.0;
    nodes.push_back(1);
    path.push_back(1);
    visit[1] = true;
    dfs(1, path, maxDistance, 0.0, visit, nodes, adj);


    //再选取这个节点的终点进行 dfs
    int begin = nodes.back();
    // 清空状态
    maxDistance = 0.0;
    nodes.clear();
    path.clear();
    fill(visit.begin(), visit.end(), false);
    // 重新初始化
    nodes.push_back(begin);
    path.push_back(begin);
    visit[begin] = true;

    dfs(begin, path, maxDistance, 0.0, visit, nodes, adj);
    // 现在得到的 nodes 是直径所经过的所有节点
    int end = nodes.back();
    double diam = 0.0;
    int nodeNum = (int)nodes.size();
    // 计算这条线段上面每个点之间的长度并存入邻接矩阵中（这里可以存入的原因是之后仅使用邻接矩阵储存的长度，而不是用邻接矩阵的邻接性
    for(int i = 0; i < nodeNum; ++i){
        for(int j = i+1; j < nodeNum; ++j){
            adj[nodes[i]][nodes[j]] = adj[nodes[j]][nodes[i]] = adj[nodes[i]][nodes[j-1]] + adj[nodes[j-1]][nodes[j]];
        }
    }

    // 计算这个图的直径
    for(int i = 0; i+1 < nodeNum; ++i){
        diam += adj[nodes[i]][nodes[i+1]];
    }

    // nodes[l], nodes[r] 分别是离中点最近的两个节点
    // mid 在线段 [nodes[l], nodes[r]) 上
    int l = 0, r = 1;
    double res = diam/2 - adj[nodes[l]][nodes[r]];
    while(res > 0){
        l++;
        r++;
        res -= adj[nodes[l]][nodes[r]];
    }
    double midToR = -res;
    double midToL = adj[nodes[l]][nodes[r]] + res;

    // ECC(diam) 取的点一定在直径上，而且是最远的两点之一, 即 begin 和 end 之一
    double curL = 0.0;
    // 从一个点开始进行 dfs 这里进行这个点处状态的初始化
    if(midToL < midToR){ // 如果里左侧进就移动到左侧的点
        midToL = (l == 0) ? 0 : adj[nodes[l]][nodes[l-1]];
        midToR = adj[nodes[l]][nodes[r]];
        l--;
    } else{ // 如果里右侧进就移动到右侧的点
        midToR = (r == nodeNum-1) ? 0 : adj[nodes[r]][nodes[r+1]];
        midToL = adj[nodes[l]][nodes[r]];
        r++;
    }
    int minDistance = INT32_MAX;

    dfsLen(curL, l, r, midToL, midToR, adj, s, begin, end, nodes, minDistance);

    cout << minDistance;

    return 0;
}
