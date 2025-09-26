#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> days;
    int a;
    while(cin >> a){
        days.push_back(a);
        char c = cin.get();
        if(c == EOF) break;
    }
    int num = 0;
    int n = (int)days.size();
    for(int i = 0; i < n; ++i){
        if(days[i] == 1) num++;
        if(days[i] == 0){
            num = 0;
        }
    }
    cout << num;
    return 0;
}
