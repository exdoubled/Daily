#include <iostream>
#include <vector>

using namespace std;

long long countSubrrays(vector<int>& nums, long long k){
    int n = (int)nums.size();
    long long ans = 0;
    int j = 0;
    long long sum = 0;
    for(int i = 0; i < n; ++i){
        sum += nums[i];
        while(sum * (i - j + 1) >= k){
            sum -= nums[j];
            j++;
        }
        ans += i - j + 1;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << countSubrrays(v,k);
    return 0;
}
