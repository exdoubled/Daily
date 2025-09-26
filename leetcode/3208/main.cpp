#include <iostream>
#include <vector>

using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k){
    int n = (int)colors.size();
    if(n < k) return 0;
    int len = 0;
    int count = 0;
    for(int i = 1; i < n + k - 1; ++i){
        if(colors[i%n] != colors[(i-1) % n]){
            if(++len >= k) ++count;
        } else len = 1;
    }
    return count;
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin>>v[i];
    cout << numberOfAlternatingGroups(v, k);

    return 0;
}
