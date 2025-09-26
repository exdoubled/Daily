#include <iostream>

using namespace std;

long sum(int x){
    long result = 0;
    for(int i = x; i > 0; --i) result += i;
    return result;
}

int main() {
    int n,m;
    cin >> n >> m;
    long sq = 0;
    for(int i = n, j = m; i > 0 && j > 0; --i, --j){
        sq += i * j;
    }
    long b = sum(m) * sum(n) - sq;
    cout << sq << " " << b;
    return 0;
}
