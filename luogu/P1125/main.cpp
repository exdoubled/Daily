#include <iostream>
#include <string>
#include <map>

using namespace std;

bool check(int num){
    if(num == 1) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(int i = 3; i * i <= num; i = i + 2){
        if(num % i == 0) return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    map<char, int> m;
    for(int i = 0; i < n; ++i){
        if(m.find(s[i]) == m.end()){
            m.insert(make_pair(s[i], 1));
        }
        else{
            m[s[i]]++;
        }
    }
    int max = 0;
    int min = 1e5;
    auto it = m.begin();
    while(it != m.end()){
        max = max < it->second ? it->second : max;
        min = min > it->second ? it->second : min;
        ++it;
    }
    if(check(max-min)){
        cout << "Lucky Word" << endl << max-min;
    }else{
        cout << "No Answer" << endl << 0;
    }
    return 0;
}
