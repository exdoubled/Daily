#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long num = 0;
    for(long long i = 1; i*i <= 2*n; ++i){
        if(2*n % i != 0) continue;
        long long j = 2*n / i;
        if(!((i+j) & 1)) continue;
        num++;
    }
    cout << num;
    return 0;
}
