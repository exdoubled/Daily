#include <iostream>

// 卡特兰数
using namespace std;
long long h[21];
int main(){
    int n;
    h[0] = h[1] = 1;
    cin >> n;
    for (int i=2; i<=n; i++)
    {
        h[i] += h[i-1] * (4*i-2) / (i+1);
    }
    cout << h[n] << endl;
}