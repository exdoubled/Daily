#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> nums1;
    vector<int> nums2;
    for(int i = 1; i <= n;++i) cin >> v[i];
    sort(v.begin(),v.end());
    for(int l = 0, r = n; l <= r; ++l, --r){
        if(l == r){
            nums1.push_back(v[l]);
        }
        nums1.push_back(v[l]); // num1 从小到大
        nums2.push_back(v[r]); // num2 从大到小
    }

    long long ans = 0;
    int l = 0;
    int r = 0;
    bool key = true;
    while(l + r <= n-1){
        ans += pow(nums1[l] - nums2[r], 2);
        if(key){
            l++;
            key = false;
        } else{
            r++;
            key = true;
        }
    }
    cout << ans;

    return 0;
}
