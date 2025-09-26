#include <iostream>

using namespace std;

bool fx(int a, int x, int y, int z){
    return (a == x || a == y || a == z);
}

bool gx(int x, int y, int z){
    return (x == y || x == z || y == z || z == 0 || y == 0 || x == 0);
}

int main() {
    int A,B,C;
    int num = 0;
    cin >> A >> B >> C;
    if (A == 0 || B == 0 || C == 0) {
        cout << "No!!!";
        return 0;
    }


    for(int i = 123; i < 1000; ++i){
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;
        if (gx(a,b,c)){
            continue;
        }

        int j = i * (B / A);
        int k = i * (C / A);
        if(j >= 1000 || k >= 1000) continue;

        int d = j / 100;
        int e = (j / 10) % 10;
        int f = j % 10;
        if (fx(a,d,e,f) || fx(b,d,e,f) || fx(c,d,e,f) || gx(d,e,f)) continue;

        int g = k / 100;
        int h = (k / 10) % 10;
        int l = k % 10;
        if (fx(a,g,h,l) || fx(b,g,h,l) || fx(c,g,h,l) || fx(d,g,h,l) || fx(e,g,h,l) || fx(f,g,h,l) || gx(g,h,l) ) continue;

        cout << i << " " << j << " " << k << endl;
        ++num;
    }
    if (num == 0) cout << "No!!!";

    return 0;
}
