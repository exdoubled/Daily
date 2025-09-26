#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node{
    int pos{};
    int score{};
};

bool cmp(Node a, Node b){
    if (a.score != b.score) return a.score < b.score;
    return a.pos > b.pos;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Node> v(n + 1);
    int k = floor((double)m * 1.50);
    for (int i = 1; i <= n; ++i){
        cin >> v[i].pos >> v[i].score;
    }
    sort(++v.begin(),v.end(), cmp);

    int score = v[n-k+1].score;
    int num = 0;
    vector<Node> ans;
    for(int i = n; v[i].score >= score; --i){
        ans.push_back(v[i]);
        ++num;
    }
    cout << score << " " << num << endl;
    for (auto & an : ans){
        cout << an.pos << " " << an.score << endl;
    }


    return 0;
}
