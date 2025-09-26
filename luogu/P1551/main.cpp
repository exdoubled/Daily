#include <iostream>
#include <vector>

using namespace std;

int find(vector<int>& prev, int x){
    return x == prev[x] ? x : (prev[x] = find(prev, prev[x]));
}

void merge(vector<int>& prev, int i, int j){
    prev[find(prev, i)] = find(prev, j);
}

void question(vector<int>& prev, int i, int j){
    if(find(prev, i) == find(prev, j)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> v(n+1);
    for(int i = 0; i < n+1; ++i){
        v[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        merge(v, a, b);
    }

    for (int i = 0; i < p; ++i) {
        int a, b;
        cin >> a >> b;
        question(v, a, b);
    }

    return 0;
}