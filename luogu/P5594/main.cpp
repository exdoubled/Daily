#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    int temp;
    int r = 0;
    vector<set<int> >  v(k);
    for (int i = 0; i < n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> temp;
            v[temp - 1].insert(j);
        }
    }

    for(int i = 0; i < k; ++i){
        cout << v[r++].size() << " ";
    }
    return 0;
}
