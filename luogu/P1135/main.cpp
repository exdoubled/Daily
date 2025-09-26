#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<int> k;
bool m[2] = {true, false};

bool limit(int t){
    return t >= 0 && t < n;
}

int bfs(vector<bool>& flag, int start, int end){
    if(start == end) return 0;
    queue<int> q;
    int ans = 0;
    q.push(start);
    q.push(-1);
    while(!q.empty()){
        int levelSize = (int)q.size();
        ans++;
        for(int i = 0; i < levelSize; ++i){
            int cur = q.front();
            q.pop();
            for(bool mod : m){
                int next = mod ? cur + k[cur] : cur - k[cur];
                if(next == end){
                    return ans;
                }
                if(limit(next) && !flag[next]){ // 在限制内并且未访问过
                    flag[next] = true;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main() {
    int a,b;
    cin >> n >> a >> b;
    a = a-1; b = b-1;
    for(int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        k.push_back(temp);
    }
    vector<bool> flag(n, false);
    flag[a] = true;
    cout << bfs(flag, a,b);
    return 0;
}
