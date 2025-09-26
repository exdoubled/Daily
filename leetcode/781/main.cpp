#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int numRabbits(vector<int>& answers){
    int sum = 0;
    unordered_map<int, int> cnt;
    for(auto ans : answers){
        if(cnt.count(ans) == 0){
            cnt[ans] = 1;
        } else{
            cnt[ans]++;
        }
    }
    for(auto node : cnt){
        if(node.second % (node.first+1) == 0){
            sum += (node.second / (node.first+1)) * (node.first + 1);
        } else{
            sum += (node.second / (node.first+1) + 1) * (node.first + 1);
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << numRabbits(v);
    return 0;
}
