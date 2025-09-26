#include <iostream>
#include <unordered_map>

using namespace std;

int maxFreqSum(string& s){
    unordered_map<char, int> map;
    for(auto c : s){
        if(map.count(c) == 0){
            map[c] = 1;
        } else{
            map[c]++;
        }
    }

    int ans1 = 0;
    int ans2 = 0;

    for(auto key : map){
        if(key.first == 'a' || key.first == 'e' || key.first == 'i' || key.first == 'o' || key.first == 'u'){
            ans1 = ans1 > key.second ? ans1 : key.second;
        } else{
            ans2 = ans2 > key.second ? ans2 : key.second;
        }
    }

    return ans1 + ans2;
}

int main() {
    string s;
    cin >> s;
    cout << maxFreqSum(s);
    return 0;
}
