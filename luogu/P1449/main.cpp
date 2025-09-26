#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    string string1;
    cin >> string1;
    int i = 0;
    int num = 0;
    while(i < string1.size()){
        if(isdigit(string1[i])){
            num = num*10 + (string1[i]-'0');
        } else if(string1[i] == '.'){
            s.push(num);
            num = 0;
        } else if(string1[i] == '+'){
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            num = num1 + num2;
            s.push(num);
            num = 0;
        } else if(string1[i] == '-'){
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            num = num1 - num2;
            s.push(num);
            num = 0;
        } else if(string1[i] == '*'){
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            num = num1 * num2;
            s.push(num);
            num = 0;
        } else if(string1[i] == '/'){
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            num = num1 / num2;
            s.push(num);
            num = 0;
        } else if(string1[i] == '@') break;
        ++i;
    }
    cout << s.top();
    return 0;
}
