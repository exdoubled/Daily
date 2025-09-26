#include <iostream>

using namespace std;

int main() {
    unsigned int n;
    cin >> n;
    unsigned int ans = (n >> 16) + (n << 16);
    cout << ans;
    return 0;
}
