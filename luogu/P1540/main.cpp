#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int m,n;
    int temp;
    cin >> m >> n;
    int count = 0;
    queue<int> q;
    vector<bool> v(1001,false);
    while(n-- > 0){
        cin >> temp;
        if(!v[temp]){
            v[temp] = true;
            if(q.size() < m){
                q.push(temp);
                count++;
            } else{
                int t = q.front();
                q.pop();
                v[t] = false;
                q.push(temp);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
