#include <iostream>
#include <vector>

int N = 1000010;
int main() {
    int n;
    std::cin >> n;
    std::vector<int> f(N);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; ++i){
        f[i] = (2*f[i-1]) % 10000 + f[i-3] % 10000;
        f[i] %= 10000;
    }
    std::cout << f[n];
    return 0;
}
