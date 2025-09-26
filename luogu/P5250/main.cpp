#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> warehouse;
    while (n-- > 0){
        int method, length;
        cin >> method >> length;
        if(method == 1){
            if(warehouse.count(length) == 0) warehouse.insert(length);
            else cout << "Already Exist" << endl;
        }
        if(method == 2){
            if(warehouse.empty()) cout << "Empty" << endl;
            else{
                auto it = warehouse.find(length);
                if(it != warehouse.end()){ // 找到了
                    cout << length << endl;
                    warehouse.erase(it);
                } else{
                    warehouse.insert(length);
                    it = warehouse.find(length);
                    auto next = ++it;
                    it--;
                    if(next == warehouse.end()){ // 后面没有
                        auto prev = --it;
                        it++;
                        cout << *prev << endl;
                        warehouse.erase(prev);
                        warehouse.erase(it);
                        continue;
                    }
                    if(it == warehouse.begin()){ // 前面没有
                        cout << *next << endl;
                        warehouse.erase(next);
                        warehouse.erase(it);
                        continue;
                    }
                    if(it != warehouse.begin() && next!= warehouse.end()){
                        auto prev = --it;
                        it++;
                        int deltaPrev = *it - *prev;
                        int deltaNext = *next - *it;
                        if(deltaNext < deltaPrev){
                            cout << *next << endl;
                            warehouse.erase(next);
                            warehouse.erase(it);
                        }
                        if(deltaNext >= deltaPrev){
                            cout << *prev << endl;
                            warehouse.erase(prev);
                            warehouse.erase(it);
                        }
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}
