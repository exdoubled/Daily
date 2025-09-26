#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class BigInt {
public:
    // 内部采用字符串存储数字，保证没有多余的前导零
    string s;

    // 默认构造函数
    BigInt() : s("0") {}

    // 从字符串构造（同时去除前导零）
    BigInt(const string &str) {
        int pos = 0;
        // 跳过前导零
        while (pos < str.size() && str[pos] == '0') pos++;
        if (pos == str.size()) s = "0";
        else s = str.substr(pos);
    }

    // 比较运算符：先比较长度，再逐位比较
    bool operator<(const BigInt &other) const {
        if (s.size() != other.s.size())
            return s.size() < other.s.size();
        return s < other.s;
    }
    bool operator==(const BigInt &other) const {
        return s == other.s;
    }
    bool operator>(const BigInt &other) const {
        return other < *this;
    }
    bool operator<=(const BigInt &other) const {
        return !(other < *this);
    }
    bool operator>=(const BigInt &other) const {
        return !(*this < other);
    }
    bool operator!=(const BigInt &other) const {
        return !(*this == other);
    }

    // 高精度乘法：利用传统的“竖式乘法”算法
    BigInt operator*(const BigInt &other) const {
        int n = s.size(), m = other.s.size();
        vector<int> result(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s[i] - '0') * (other.s[j] - '0');
                int sum = result[i + j + 1] + mul;
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        string resStr;
        for (int num : result) {
            if (!(resStr.empty() && num == 0))
                resStr.push_back(num + '0');
        }
        if (resStr.empty()) resStr = "0";
        return BigInt(resStr);
    }

    // 辅助函数：减法（假定 *this >= other）
    BigInt operator-(const BigInt &other) const {
        string a = s, b = other.s;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        string res;
        while (i >= 0) {
            int x = a[i] - '0';
            int y = (j >= 0 ? b[j] - '0' : 0);
            int sub = x - y - carry;
            if (sub < 0) { sub += 10; carry = 1; }
            else { carry = 0; }
            res.push_back(sub + '0');
            i--; j--;
        }
        reverse(res.begin(), res.end());
        // 去除前导零
        int pos = 0;
        while (pos < res.size() - 1 && res[pos] == '0') pos++;
        return BigInt(res.substr(pos));
    }

    // 高精度除法：长除法算法，返回向下取整的商
    BigInt operator/(const BigInt &divisor) const {
        if (divisor == BigInt("0"))
            throw runtime_error("除数不能为0");
        string quotient;
        BigInt remainder("0");
        // 对于被除数的每一位，更新余数，并求当前位的商
        for (char c : s) {
            // remainder = remainder * 10 + (当前数字)
            if (remainder.s == "0")
                remainder.s = string(1, c);
            else
                remainder.s.push_back(c);
            // 去掉可能产生的前导零
            remainder = BigInt(remainder.s);

            int count = 0;
            while (!(remainder < divisor)) { // 当余数大于等于除数时
                remainder = remainder - divisor;
                count++;
            }
            quotient.push_back(count + '0');
        }
        // 去除商的前导零
        int pos = 0;
        while (pos < quotient.size() - 1 && quotient[pos] == '0') pos++;
        return BigInt(quotient.substr(pos));
    }

    // 重载输入输出流
    friend istream& operator>>(istream &in, BigInt &a) {
        string str;
        in >> str;
        a = BigInt(str);
        return in;
    }
    friend ostream& operator<<(ostream &out, const BigInt &a) {
        out << a.s;
        return out;
    }
};

struct Node{
    BigInt l;
    BigInt r;
};

bool cmp1(const Node& a, const Node& b){
    return a.r*a.l < b.r*b.l;
}

bool cmp2(const BigInt& a, const BigInt& b){
    return a > b;
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n);
    BigInt ml;
    BigInt mr;
    cin >> ml >> mr;
    for(int i = 0; i < n; ++i){
        cin >> v[i].l >> v[i].r;
    }
    sort(v.begin(), v.end(),cmp1);
    BigInt res = ml;
    vector<BigInt> vec(n);
    for(int i = 0; i < n; ++i){
        vec[i] = res / v[i].r;
        res = res * v[i].l;
    }
    sort(vec.begin(),vec.end(),cmp2);

    cout << *vec.begin();

    return 0;
}
