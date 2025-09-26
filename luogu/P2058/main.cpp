#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;
    queue<long long> time;
    unordered_map<int, long long> map;
    unordered_map<long long,vector<int>> mapRe;
    unordered_set<int> nation;
    while(n-- > 0){
        long long curTime;
        cin >> curTime;
        if(!time.empty()){
            while(curTime - time.front() >= 86400 && !time.empty()){
                long long lastTime = time.front();
                time.pop();
                for(auto aNation : mapRe[lastTime]){
                    if(map[aNation] == lastTime) nation.erase(aNation);
                }
                mapRe.erase(lastTime);
            }
        }
        time.push(curTime);
        int num;
        cin >> num;
        while(num-- > 0){
            int curNation;
            cin >> curNation;
            map[curNation] = curTime;
            mapRe[curTime].push_back(curNation);
            nation.insert(curNation);
        }
        cout << nation.size() << endl;
    }
    return 0;
}
