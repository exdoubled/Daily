#include <iostream>
#include <set>
#include <string>
// SAM后缀自动机

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    set<string> set;
    for(int l = 0, r = 0; l != s.size()-1; r++){
        set.insert(s.substr(l,r - l + 1));
        if(r == s.size()-1){
            l++;
            r = l - 1;
        }
    }
    set.insert(s.substr(s.size()-1,1));
    cout << set.size();
    return 0;
}
