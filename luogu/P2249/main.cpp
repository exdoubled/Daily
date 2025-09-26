#include <iostream>
#include <vector>
#include <map>

using namespace std;


int main() {
    int n,m;
    cin >> n >> m;
    int temp;
    map<int, int> map;
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        if(map.find(temp) == map.end()){
            map[temp] = i + 1;
        }
    }

    for(int i = 0; i < m; ++i){
        cin >> temp;
        auto it = map.find(temp);
        if(it != map.end()){
            cout << it->second << " ";
        } else{
            cout << -1 << " ";
        }
    }
    return 0;
}
