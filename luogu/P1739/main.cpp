#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> s;
    char c;
    while(cin >> c){
        if (c == EOF) break;
        if (c == '(') s.push(c);
        if (c == ')') {
            if (s.empty()) {
                cout << "NO";
                return 0;
            } else s.pop();
        }
    }
    if (s.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
