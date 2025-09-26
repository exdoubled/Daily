#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int count(int& n, int x, vector<int>& L){
    int cnt = 0;
    for(int i = 0; i < n; ++i) cnt += L[i] / x;
    return cnt;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> l(n);
    vector<int> L(n);
    for(int i = 0 ; i < n; ++i){
        cin >> l[i];
        L[i] = l[i] * 100;
    }
    sort(L.begin(), L.end());

    int left = 0;
    int right = L[n-1];
    int ans = 0;
    while(left <= right){
        int mid = (left + right) >> 1;
        if(mid == 0) break;
        if(count(n, mid, L) < k) right = mid - 1;
        else{
            left = mid + 1;
            ans = mid;
        }
    }
    cout << fixed << setprecision(2) << (double)ans / 100.0;
    return 0;
}
