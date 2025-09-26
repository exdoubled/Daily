#include <iostream>
#include <cmath>

int findN(int N, int k){ // 找到N在k进制下的最大幂次
    int sum = 1;
    int cnt = 0;
    while(true){
        if(sum > N/k) return cnt;
        sum = sum * k;
        cnt++;
    }
}

int toNum(char c){
    switch (c) {
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default: return c - '0';
    }
}

void next(char& c){
    switch (c) {
        case '0': c = '1'; break;
        case '1': c = '2'; break;
        case '2': c = '3'; break;
        case '3': c = '4'; break;
        case '4': c = '5'; break;
        case '5': c = '6'; break;
        case '6': c = '7'; break;
        case '7': c = '8'; break;
        case '8': c = '9'; break;
        case '9': c = 'A'; break;
        case 'A': c = 'B'; break;
        case 'B': c = 'C'; break;
        case 'C': c = 'D'; break;
        case 'D': c = 'E'; break;
        case 'E': c = 'F'; break;
    }
}

using namespace std;

int main() {
    int n;
    string s;
    int k;
    cin >> n;
    cin >> s;
    cin >> k;
    long long num = 0;
    int m1 = (int)s.size();
    for(int i = m1-1; i >= 0; --i){
        num += toNum(s[i]) * pow(n, (m1-1-i));
    }
    int m2 = findN(num, k);
    string ans(m2+1, '0');
    while(num > 0){
        int i = findN(num, k);
        num -= pow(k, i);
        next(ans[m2-i]);
    }
    cout << ans;
    return 0;
}
