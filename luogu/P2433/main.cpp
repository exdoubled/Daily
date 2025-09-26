#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout << 3 << endl << 12 << endl << 2;
    } else if (T == 4) {
        cout << setprecision(6) << (double)500/(double)3;
    } else if (T == 5) {
        cout << (260 + 220) / (12 + 20);
    } else if (T == 6) {
        cout << sqrt(pow(float(6),2)+pow(float(9),2));
    } else if (T == 7) {
        cout << 110 << '\n' << 90 << '\n' << 0;
    } else if (T == 8) {
        double pi = 3.141593;
        cout << 2 * pi * 5 << endl << pi * 25 << endl << (float)4/(float)3 * pi * 125;
    } else if (T == 9) {
        cout << 22;
    } else if (T == 10) {
        cout << 9;
    } else if (T == 11) {
        cout << (double)100/(double)3;
    } else if (T == 12) {
        cout << (int)('M' - 'A' + 1) << '\n' << (char)('A' + 17);
    } else if (T == 13) {
        double i;
        double Pi=3.141593;
        i = pow(1.0*4/3*Pi*(64+1000),1.0*1/3);
        cout << (int)i;
    } else if (T == 14) {
        cout<<50;
    }
    return 0;
}