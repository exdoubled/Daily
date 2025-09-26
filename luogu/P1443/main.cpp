#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
struct Node{
    int x;
    int y;
    Node() : x(0), y(0) {}
    Node(int x, int y) : x(x), y(y) {}
};

bool limit(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}

vector<Node> next(Node& a) {
    vector<Node> v;
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
    for (int i = 0; i < 8; ++i) {
        int nx = a.x + dx[i];
        int ny = a.y + dy[i];
        if (limit(nx, ny)) {
            v.emplace_back(nx, ny);
        }
    }
    return v;
}

void bfs(vector<vector<bool> >& key, vector<vector<int> >& step, int x, int y) {
    queue<Node> q;
    q.emplace(x, y);
    key[x][y] = true;
    step[x][y] = 0;
    int steps = 0;
    while (!q.empty()) {
        int levelSize = (int)q.size();
        for (int i = 0; i < levelSize; ++i) {
            Node cur = q.front();
            q.pop();
            vector<Node> overs = next(cur);
            for (auto& over : overs) {
                int cx = over.x, cy = over.y;
                if (!key[cx][cy]) {
                    key[cx][cy] = true;
                    step[cx][cy] = steps + 1;
                    q.push(over);
                }
            }
        }
        steps++;
    }
}

int main() {
    int x,y;
    cin >> n >> m >> x >> y;
    x = x-1; y = y-1;
    vector<vector<bool> > key(n,vector<bool>(m, false));
    key[x][y] = true;
    vector<vector<int> > step(n, vector<int>(m,0));
    bfs(key,step,x,y);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!key[i][j]) cout << -1 << " ";
            else cout << step[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
