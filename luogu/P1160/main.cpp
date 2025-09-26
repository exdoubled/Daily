#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> queue_list;
    unordered_map<int, list<int>::iterator> pos_map;
    queue_list.push_back(1);
    pos_map[1] = queue_list.begin();
    for(int i = 2; i <= n; ++i) {
        int pos, method;
        cin >> pos >> method;
        auto it = pos_map[pos];
        if(method == 0) {
            pos_map[i] = queue_list.insert(it, i);
        } else {
            pos_map[i] = queue_list.insert(next(it), i);
        }
    }

    int m;
    cin >> m;
    while(m--) {
        int k;
        cin >> k;
        auto map_it = pos_map.find(k);
        if(map_it != pos_map.end()) {
            queue_list.erase(map_it->second);
            pos_map.erase(map_it);
        }
    }

    for(int num : queue_list) {
        cout << num << " ";
    }

    return 0;
}