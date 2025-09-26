#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    n = n % 26;
    int m = (int)s.size();
    for(int i = 0; i < m; ++i){
        s[i] = (char)((s[i]-'a'+n) % 26 + 'a');
    }
    cout << s;
    return 0;
}
