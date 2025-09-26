#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int> > questions;
    int num = questions.size();
    vector<int> dp(num+1, 0);
    for (int i = num-1; i > 0; --i){
        int a = num > i+1+questions[i][1] ? i+1+questions[i][1] : num;
        int cmp = questions[i][0] + dp[a];
        dp[i] = dp[i+1] > cmp ? dp[i+1] : cmp;
    }
    return 0;
}
