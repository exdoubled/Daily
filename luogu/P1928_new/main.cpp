#include <iostream>
#include <string>

using namespace std;

int where = 0;

string get(int cnt, const string& str){
    string builder;
    for(int i = 0; i < cnt; ++i){
        builder += str;
    }
    return builder;
}

string f(string& s, int i){
    string ans;
    int cnt = 0;
    bool key = false;
    while(i < s.size() && s[i] != ']'){
        if(key){
            if(isdigit(s[i])) {
                cnt = cnt * 10 + s[i++] - '0';
                continue;
            }
            ans += get(cnt, f(s, i));
            i = where+1;
            cnt = 0;
            key = false;
        } else if(isalpha(s[i])){
            ans.push_back(s[i++]);
        } else if(s[i++] == '['){
            key = true;
        }
    }
    where = i;
    return ans;
}
int main() {
    string s;
    cin >> s;
    cout << f(s, 0);
    return 0;
}
