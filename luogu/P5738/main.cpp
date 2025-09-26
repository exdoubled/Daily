#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// 定义函数求平均值
double avg(int m){
    vector<double> a(m,0);
    cin >> a[0];
    double max = a[0];
    double min = a[0];
    double sum = a[0];
    for (int i = 1; i < m; i++){
        cin >> a[i];
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
        sum += a[i];
    }
    double res = (sum - max - min) / (m - 2);
    return res;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<double> b(n, 0);
    double max = 0;
    for(int i = 0; i < n; i++){
        b[i] = avg(m);
        max = max >= b[i] ? max : b[i];
    }
    cout << fixed << setprecision(2) << max;
    return 0;
}
