#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 10000;
const int MAX_E = 13;


int idealArrays(int n, int maxValue){
    long long ans = 0;

    // 处理每个数的质因数分解
    vector<vector<int>> nums(maxValue+1);
    for(int num = 2; num <= maxValue; ++num){
        int res = num;
        for (int i = 2; i * i <= res; i++) {
            int cnt = 0;
            for (; res % i == 0; res /= i) {
                cnt++;
            }
            if(cnt) {
                nums[num].push_back(cnt);
            }
        }
        if (res > 1) {
            nums[num].push_back(1);
        }
    }

    //处理组合数
    vector<vector<int>> C(MAX_N+MAX_E,vector<int>(MAX_E+1));
    for(int i = 0; i < MAX_N+MAX_E; ++i){
        C[i][0] = 1;
        for(int j = 1; j <= min(i, MAX_E); ++j){
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }


    for(int i = 1; i <= maxValue; ++i){
        long long res = 1;
        for(int k : nums[i]){
            res = res * C[n + k - 1][k] % MOD;
        }
        ans += res;
    }
    return ans % MOD;
}

int main() {
    int n, maxValue;
    cin >> n >> maxValue;
    cout << idealArrays(n, maxValue);
    return 0;
}
