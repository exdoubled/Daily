#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int val;
    int time;
};

int main() {
    int times, n;
    cin >> times >> n;
    vector<Node> v(n);
    vector<bool> key(n, false);
    for(int i = 0; i < n; ++i){
        cin >> v[i].time >> v[i].val;
    }
    vector<int> dp(times + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = times; j >= v[i].time; --j) {
            dp[j] = max(dp[j], dp[j - v[i].time] + v[i].val);
        }
    }
    cout << dp[times];
    return 0;
}
