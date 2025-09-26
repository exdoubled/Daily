#include <iostream>
#include <stack>

using namespace std;

char getChar(int i){
    if(i >= 0 && i <= 9) return (char)('0' + i);
    else return (char)('A'+i-10);
}

int main() {
    int n, x;
    cin >> n >> x;
    stack<char> ans;
    if(n == 0) ans.push('0');
    else {
        while(n){
            ans.push(getChar(n%x));
            n /= x;
        }
    }
    while(!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
    return 0;
}
