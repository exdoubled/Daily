#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    int n = (int)s.size();
    if(k == 1){
        cout << s[0];
    } else{
        unordered_map<char, int> map;
        bool key = true;
        for(int i = 0; i < n; ++i){
            if(map.count(s[i]) == 0){
                map[s[i]] = 1;
            } else{
                map[s[i]]++;
                if(map[s[i]] == k){
                    cout << s[i];
                    key = false;
                    break;
                }
            }
        }
        if(key){
            cout << "No";
        }
    }
    return 0;
}
