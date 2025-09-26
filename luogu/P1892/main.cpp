#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int>& f){
    if(f[x] != x) f[x] = find(f[x], f);
    return f[x];
}

void merge(int a, int b, vector<int>& f){
    int fa = find(a, f);
    int fb = find(b, f);
    if(fa != fb) f[fa] = fb;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n+1);
    vector<int> e(n+1);
    for(int i = 1; i <= n; i++) e[i] = 0;
    for(int i = 1; i <= n; i++) f[i] = i;
    char op;
    int x, y;
    int count = 0;
    while(m-- > 0){
        cin >> op >> x >> y;
        if(op == 'F') merge(x,y,f);
        else{
            if(e[x] == 0) e[x] = find(y,f);
            else merge(y,e[x],f);
            if (e[y] == 0) e[y] = find(x,f);
            else merge(x,e[y],f);
        }
    }
    for(int i = 1; i <= n; ++i) if(f[i] == i) count++;
    cout << count << endl;
    return 0;
}
