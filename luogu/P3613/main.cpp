#include<iostream>
#include<map>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    map<int,map<int,int>> q;
    for(int i = 0; i < m; i++) {
        int a;
        cin>>a;
        int b,c,d;
        if(a==1){
            cin >> b >> c >> d;
            q[b][c] = d;
        } else{
            cin >> b >> c;
            cout << q[b][c] << endl;
        }
    }
    return 0;
}
