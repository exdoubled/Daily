#include <iostream>
#include <vector>
#include <set>
// 算法正确，但是超时
using namespace std;

int n;
vector<vector<int> > ans;

void swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

bool key(vector<int>& v){
    set<int> s1;
    set<int> s2;
    for(int i = 0; i < n; ++i){
        int temp1 = i + 1 - v[i];
        int temp2 = i + 1 - v[n-i-1];
        s1.insert(temp1);
        s2.insert(temp2);
    }
    if(s1.size() != n || s2.size() != n) return false;
    else return true;
}

void dfs(vector<int> v, int l){
    if(l == n-1){
        if(key(v)) ans.push_back(v);
    } else{
        for(int i = l; i <= n-1; ++i){
            swap(v[l], v[i]);
            dfs(v, l+1);
            swap(v[l], v[i]);
        }
    }
}

int main() {
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        v[i] = i+1;
    }
    dfs(v,0);
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < n; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << ans.size();
    return 0;
}
