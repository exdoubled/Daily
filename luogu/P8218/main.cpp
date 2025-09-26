#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n+1);
    for(int i = 1; i <= n; ++i) cin >> nums[i];

    vector<int> sum(n+1);
    sum[0] = 1;
    for(int i = 1; i <= n; ++i){
        sum[i] += sum[i-1] + nums[i];
    }

    int m;
    cin >> m;
    while(m-- > 0){
        int l, r;
        cin >> l >> r;
        cout << sum[r]- sum[l-1] << endl;
    }
    return 0;
}
