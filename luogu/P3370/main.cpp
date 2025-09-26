#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<string> set;
    while(n-- > 0){
        string s;
        cin >> s;
        auto it = set.find(s);
        if(it == set.end()){
            set.insert(s);
        }
    }
    cout << set.size();
    return 0;
}
