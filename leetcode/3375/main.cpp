#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int minOperations(vector<int>& nums,int k){
    int flag = 0;
    set<int> s;
    for(int num : nums){
        if(num < k) return -1;
        if(num == k) flag = 1;
        s.insert(num);
    }
    return (int)s.size() - flag;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << minOperations(v, k);
    return 0;
}
