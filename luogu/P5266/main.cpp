#include <iostream>
#include <unordered_map>

using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<string, long long> map;
    while(n-- > 0){
        int method;
        cin >> method;
        if(method == 1){
            string name;
            long long score;
            cin >> name >> score;
            map[name] = score;
            cout << "OK" << endl;
        } else if(method == 2){
            string name;
            cin >> name;
            if(map.count(name) == 0) cout << "Not found" << endl;
            else cout << map[name] << endl;
        } else if(method == 3){
            string name;
            cin >> name;
            if(map.count(name) == 0) cout << "Not found" << endl;
            else{
                map.erase(name);
                cout << "Deleted successfully" << endl;
            }
        } else if(method == 4){
            cout << map.size() << endl;
        }
    }
    return 0;
}
