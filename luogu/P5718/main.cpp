#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int min = INT32_MAX;
    while(--n > 0){
        int a;
        std::cin >> a;
        min = std::min(a, min);
    }
    std::cout << min;
    return 0;
}
