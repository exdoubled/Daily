#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

void cul(int W, vector<int>& weights, vector<int>& values,
         vector<long long>& sumV, vector<long long>& sum,
         vector<int>& l, vector<int>& r,
         long long& ans, long long& s){

    int n = (int)weights.size()-1;
    int m = (int)l.size();
    long long sigmaY = 0;
    for(int i = 1; i <= n; ++i){
        sumV[i] = (weights[i] >= W) ? (sumV[i-1]+values[i]) : sumV[i-1];
        sum[i] = (weights[i] >= W) ? (sum[i-1]+1) : sum[i-1];
    }
    for(int i = 0; i < m; ++i){
        sigmaY += (sum[r[i]] - sum[l[i]-1]) * (sumV[r[i]] - sumV[l[i]-1]);
    }
    ans = abs(s-sigmaY);
}

int main() {
    int n, m;
    long long s;
    cin >> n >> m >> s;
    vector<int> weights(n+1);
    vector<int> values(n+1);
    vector<long long> sumV(n+1);
    vector<long long> sum(n+1);
    sum[0] = sumV[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> weights[i] >> values[i];
    }
    int maxCnt = 0;
    int maxI = 1;
    queue<int> maxIq;
    maxIq.push(maxI);
    vector<int> delta(n, 0);
    vector<int> cnts(n+1, 0);
    vector<int> l(m);
    vector<int> r(m);
    delta[0] = 0;
    for(int i = 0; i < m; ++i){
        cin >> l[i] >> r[i];
        delta[l[i]-1]++;
        delta[r[i]]--;
    }
    for(int i = 0; i < n; ++i){
        cnts[i+1] = cnts[i] + delta[i];
        if(maxCnt < cnts[i+1]){
            maxCnt = cnts[i+1];
            maxI = i+1;
            maxIq.pop();
            maxIq.push(maxI);
        } else if(maxCnt == cnts[i+1]){
            maxIq.push(i+1);
        }
    }

    long long ans = LLONG_MAX;
    while(!maxIq.empty()){

        int lastW = weights[maxIq.front()];
        long long lastAns = 0;
        cul(lastW, weights, values, sumV,sum, l, r, lastAns, s);

        int leftW, rightW;
        long long leftAns = LLONG_MAX, rightAns = LLONG_MAX;
        if(maxIq.front()-1 > 0){
            leftW = weights[maxIq.front()-1];
            cul(leftW, weights, values, sumV,sum, l, r, leftAns, s);
        }
        if(maxIq.front()+1 <= n){
            rightW = weights[maxIq.front()+1];
            cul(rightW, weights, values, sumV,sum, l, r, rightAns, s);
        }
        maxIq.pop();

        long long minIq = leftAns < min(lastAns, rightAns) ? leftAns : min(lastAns, rightAns);
        ans = min(ans, minIq);
    }
    cout << ans;

    return 0;
}
