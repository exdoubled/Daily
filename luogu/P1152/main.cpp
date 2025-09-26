#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isJolly(vector<long long> a){
    vector<bool> ans(a.size()-1, false);
    for(int i = 0, j = i+1; j < a.size(); ++i, ++j){
        int k = abs(a[i] - a[j]) - 1;
        if (k >= 0 && k <a.size() - 1) ans[abs(a[i] - a[j]) - 1] = true;
        else return false;
    }
    for (auto i : ans){
        if(!i) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    if(isJolly(v)) cout << "Jolly";
    else cout << "Not jolly";
    return 0;
}
