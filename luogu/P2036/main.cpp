#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Ingredients{
    int sour;
    int bitter;
};

void dfs(vector<Ingredients>& ing, int& ans, int sumS, int sumB, int size, int cur){
    if(size != 0 && ans > abs(sumS - sumB)){
        ans = abs(sumS - sumB);
    }
    if(size == ing.size()){
        return;
    } else{
        for(int i = cur; i < ing.size(); ++i){
            sumS = size == 0 ? ing[i].sour: ing[i].sour * sumS;
            sumB = size == 0 ? ing[i].bitter : ing[i].bitter + sumB;
            size++;
            dfs(ing, ans, sumS, sumB, size, i+1);
            sumS /= ing[i].sour;
            sumB -= ing[i].bitter;
            size--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<Ingredients> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i].sour >> v[i].bitter;
    int ans = abs(v[0].sour - v[0].bitter);
    dfs(v, ans, 0, 0, 0, 0);
    cout << ans;
    return 0;
}
