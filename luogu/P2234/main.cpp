#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(1);
    cin >> a[0];
    int ans = a[0];
    int temp;
    for(int i = 1; i < n; ++i) {
        cin >> temp;
        auto it = lower_bound(a.begin(), a.end(), temp);
        int diff = INT_MAX;
        if(it != a.end()) diff = abs(temp - *it);
        if(it != a.begin()) diff = min(diff, abs(temp - *(it - 1)));
        ans += diff;
        a.insert(it, temp);
    }
    cout << ans << endl;
    return 0;
}