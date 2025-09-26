#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string find(string& a, unordered_map<string, string>& f){
    if(f[a] != a) f[a] = find(f[a], f);
    return f[a];
}

int main() {
    unordered_map<string, string> f;
    string name;
    string father;
    char op;
    while(cin >> op){
        if(op == '$') break;
        else if(op == '#'){
            cin >> father;
            if(f.find(father) == f.end()) f[father] = father;
        } else if (op == '+'){
            cin >> name;
            f[name] = father;
        } else if(op == '?'){
            cin >> name;
            cout << name << " " <<  find(name, f) << endl;
        }
    }
    return 0;
}
