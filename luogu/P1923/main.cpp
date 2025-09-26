#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    nth_element(v.begin(), v.begin()+k, v.end());
    cout << v[k];
    return 0;
}
