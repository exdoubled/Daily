#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;
/*
long long maximumTotalDamage(vector<int> power) {
    int n = power.size();
    if (n == 0) return 0;
    sort(power.begin(), power.end());
    vector<long long> dp(n + 1, 0);
    int l = 0;
    int i = 0;
    while (i < n) {
        int curr = power[i];
        int j = i;
        while (j < n && power[j] == curr) j++;
        long long sum = (long long)(j - i) * curr;
        while (l < i && power[l] < curr - 2) l++;
        dp[j] = max(dp[i], dp[l] + sum);
        i = j;
    }
    return dp[n];
}
*/

long long maximumTotalDamage(vector<int> power) {
    map<int, int> powerMap;
    for (int p : power) {
        powerMap[p]++;
    }
    vector<pair<int, int>> powerVec(powerMap.begin(), powerMap.end());
    int n = powerVec.size();
    vector<long long> dp(n + 1, 0);
    int l = 0;
    int i = 0;
    while (i < n) {
        int curr = powerVec[i].first;
        long long sum = (long long)powerVec[i].second * curr;
        while (l < i && powerVec[l].first < curr - 2) l++;
        dp[i+1] = max(dp[i], dp[l] + sum);
        i++;
    }
    return dp[n];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}