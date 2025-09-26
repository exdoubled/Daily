#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float a;
    int b;
    cin >> a >> b;
    cout << fixed << setprecision(3) << a/b;
    cout << endl;
    cout << b*2;
    return 0;
}
