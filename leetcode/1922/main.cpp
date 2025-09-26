#include <iostream>

using namespace std;

long long quick_pow(long long base, long long  power){
    long long res = 1;
    while(power > 0){
        if(power & 1){
            res = res * base % 1000000007;
        }
        base = base * base % 1000000007;
        power >>= 1;
    }
    return res % 1000000007;
}

int countGoodNumbers(long long n){
    long long n1 = (n+1)/2; // 奇数位
    long long n2 = n/2; // 偶数位
    return (int)(quick_pow(5,n1) * quick_pow(4,n2) % 1000000007);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
