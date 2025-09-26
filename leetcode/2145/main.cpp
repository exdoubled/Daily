#include <iostream>
#include <vector>

using namespace std;

int numberOfArrays(vector<int>& differences, int lower, int upper){
    long xMin = 0;
    long xMax = 0;
    long start = 0;
    for(auto diff : differences){
        start += diff;
        xMin = xMin > start ? start : xMin;
        xMax = xMax < start ? start : xMax;
    }

    int ans = (upper - lower) - (xMax - xMin) + 1;
    return ans > 0 ? ans : 0;
}

int main() {
    int n, l , u;
    cin >> n >> l >> u;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << numberOfArrays(v, l, u);
    return 0;
}
