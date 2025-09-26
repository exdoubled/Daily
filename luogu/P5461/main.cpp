#include <iostream>
#include <cmath>

// 时间复杂度Θ(4^n) 空间复杂度O(1)
using namespace std;

void f(int *x, int k){
    if ((*x) % k == 0) *x = k;
    else *x %= k;
}

// 时间复杂度Θ(4^n) 空间复杂度O(1)
bool pardon(int x, int y, int n) {
    bool result = false;
    for (int k = pow(2, n); k > 1; k /= 2, f(&x,k), f(&y, k)) {
        if (x <= k/2 && y <= k/2) {
            result = true;
            break;
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    int sum = pow(2, n);
    for(int i = 1; i <= sum; i++){
        for(int j = 1; j <= sum; j++){
            if (pardon(i, j, n)){
                cout << 0 << " ";
            }
            else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
