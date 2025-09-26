#include <iostream>

using namespace std;

int bit1Count(long long num){
    int ans = 0;
    for(int i = 1; i <= 64; ++i){
        if(num % 2 == 1) ans++;
        num >>= 1;
    }
    return ans;
}

int makeTheIntegerZero(int num1, int num2){
    if(num2 > num1) return -1;
    long long num = num1 - num2;
    for(int i = 1; i <= 60; ++i, num -= num2){
        if(num >= i && bit1Count(num) <= i) return i;
    }
    return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
