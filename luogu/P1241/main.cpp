#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node{
    char c{};
    bool key{false};
    Node(char _c, bool _key) {
        c = _c, key = _key;
    }
    Node(){
        key = false;
    }
};

void dfs(stack<Node*>& s){
    if(!s.empty()) {
        auto temp = s.top();
        s.pop();
        dfs(s);
        if((temp->c == '(' && !temp->key)|| (temp->c == ')' && !temp->key)) cout << "()";
        else if((temp->c == '[' && !temp->key)|| (temp->c == ']' && !temp->key)) cout << "[]";
        else cout << temp->c;
    }
}

int main() {
    string str;
    cin >> str;
    int n = (int)str.size();
    vector<Node> s(n);

    stack<Node*> left;
    stack<Node*> all;

    for(int i = 0; i < n; ++i){
        s[i].c = str[i];
        Node* cur = &s[i];
        if(s[i].c == '('){
            left.push(cur);
            all.push(cur);
        }
        if(s[i].c == '['){
            left.push(cur);
            all.push(cur);
        }
        if(s[i].c == ')'){
            if(!left.empty() && left.top()->c == '('){
                left.top()->key = true;
                left.pop();
                cur->key = true;
                all.push(cur);
            } else{
                all.push(cur);
            }
        }
        if(s[i].c == ']'){
            if(!left.empty() && left.top()->c == '['){
                left.top()->key = true;
                left.pop();
                cur->key = true;
                all.push(cur);
            } else{
                all.push(cur);
            }
        }
    }

    dfs(all);

    return 0;
}
