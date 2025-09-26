#include <bits/stdc++.h>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    unordered_map<long long, long long> map;
    long long num = numerator, den = denominator;
    if (num == 0) return "0";
    string ans;
    if ((num < 0) ^ (den < 0)) ans += '-';
    num = abs(num), den = abs(den);
    ans += to_string(num / den);
    long long  temp = (long long)num % den;
    if (temp == 0) return ans;
    ans += '.';
    while (temp) {
        if (map.count(temp)) {
            ans.insert(map[temp], 1, '(');
            ans += ')';
            break;
        }
        map[temp] = (int)ans.size();
        temp *= 10;
        ans += to_string(temp / den);
        temp %= den;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}