#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int countLargestGroup(int n){
    int ans = 1;
    unordered_map<int, int> map;
    for(int num = 1; num <= n; ++num){
        // 求各数位之和
        int add = 0;
        string s = to_string(num);
        for(auto c : s){
            add += c - '0';
        }

        if(map.count(add) == 0){
            map[add] = 1;
        } else{
            map[add]++;
        }
    }

    int maxCnt = 0;
    for(auto key : map){
        if(key.second > maxCnt){
            maxCnt = key.second;
            ans = 1;
        } else if(key.second == maxCnt){
            ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << countLargestGroup(n);
    return 0;
}
