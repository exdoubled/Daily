#include <iostream>
#include <vector>

using namespace std;

long long get(long long n){
    long long ans = 0;
    for(long long i = 1ll; i <= n; i *= 4ll) ans += n-i + 1ll;
    return ans;
}

long long minOperations(vector<vector<int>>& queries){
    long long ans = 0;
    for(vector<int>& q : queries) ans += (get(q[1]) - get(q[0] - 1ll) + 1ll) / 2ll;
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
