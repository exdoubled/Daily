#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int getDigit(long long num){
    if(num == 0) return 0;
    int ans = 0;
    while(num != 0){
        num /= 10;
        ++ans;
    }
    return ans;
}

long long cul(long long num, int& limit, vector<long long>& dp, string& s){
    long long ans = 0;
    string nums = to_string(num);
    int lenN = getDigit(num);
    int lenS = (int)s.size();
    // 每一位的dp加起来
    for(int i = 0; i < lenN - lenS; ++i){
        int cur = nums[i] - '0';
        int k = min(cur, limit+1);
        ans += k * dp[lenN - i - 1 - lenS];
        if(cur > limit) return ans;
    }
    // 如果剩余的在s之后
    if(num % (long long)(pow(10, lenS)) >= stoll(s)) ++ans;
    return ans;
}

long long numberOfPowerfulInt(long long& start, long long& finish, int& limit, string& s){
    int lenN = getDigit(finish);
    int lenS = (int)s.size();
    // dp[i]表示以s结尾的i数字最好情况
    vector<long long> dp(lenN - lenS + 1);
    dp[0] = 1;
    for(int i = 1; i < dp.size(); ++i){
        dp[i] = (limit+1) * dp[i-1];
    }
    return cul(finish, limit, dp, s) - cul(start-1, limit, dp, s);
}

int main() {
    long long start, finish;
    int limit;
    string s;
    cin >> start >> finish >> limit >> s;
    cout << numberOfPowerfulInt(start, finish, limit, s);
    return 0;
}
