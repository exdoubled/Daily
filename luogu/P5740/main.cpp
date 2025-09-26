#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<string> name(n);
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<int> sum(n);
    cin >> name[0] >> a[0] >> b[0] >> c[0];
    sum[0] = a[0] + b[0] + c[0];
    int max = sum[0];
    int max_i = 0;
    for(int i = 1; i < n; i++){
        cin >> name[i] >> a[i] >> b[i] >> c[i];
        sum[i] = a[i] + b[i] + c[i];
        if (sum[i] > max) {
            max = sum[i];
            max_i = i;
        }
    }
    cout << name[max_i] << " " << a[max_i] << " " << b[max_i] << " " << c[max_i];

    return 0;
}
