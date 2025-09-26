#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool find(const vector<int>& v, int k){
    bool ans = false;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] >= k) break;
        if(count(v.begin(), v.end(), k - v[i]) && k - v[i] != v[i]){
            ans = true;
            break;
        }
    }
    return ans;
}

int minimumSum(int n, int k) {
    vector<int> v;
    int sum = 0;
    int space = 0;
    for (int i = 1; i <= n; ++i){
        int temp = i + space;
        while(true){
            v.push_back(temp);
            if(!find(v, k)) {
                v.pop_back();
                break;
            }
            space++;
            temp++;
            v.pop_back();
        }
        v.push_back(temp);
        sum += temp;
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    int ans = minimumSum(n, k);
    cout << ans;
    return 0;
}
