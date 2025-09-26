#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int x){
    if(x == 1) return false;
    if(x == 2) return true;
    if(x % 2 == 0) return false;
    for(int i = 3; i*i < x; i += 2){
        if(x % i == 0) return false;
    }
    return true;
}

void dfs(vector<int>& nums, int& k, int sum, int cur, int size, int& ans){
    if(size == k){
        if(isPrime(sum)) ++ans;
    }
    else{
        for(int i = cur; i < nums.size(); ++i){
            sum += nums[i];
            ++size;
            dfs(nums, k, sum, i+1, size, ans);
            sum -= nums[i];
            --size;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int ans = 0;
    dfs(v,k,0,0,0,ans);
    cout << ans;
    return 0;
}
