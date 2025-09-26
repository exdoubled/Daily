#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    while(k){
        int i;
        for(i = 0; s[i] <= s[i+1] && i < s.size() - 1; i++);
        s.erase( i, 1 ); // 从第 i 个位置连续删 1 个元素
        k--;
    }
    while(s[0] == '0' && s.size() > 1 ) {
        s.erase(0, 1);
    }
    cout << s;
    return 0;
}
