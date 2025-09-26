#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

int minOperations(vector<int>& nums){
    unordered_map<int, int> cnt;
    stack<int> s;
    for(auto num : nums){
        if(num == 0){
            while(!s.empty()){
                int k = s.top();
                s.pop();
                cnt[k]++;
            }
        } else{
            while(!s.empty() && s.top() > num){
                int k = s.top();
                s.pop();
                cnt[k]++;
            }
            if(s.empty() || s.top() < num) s.push(num);
        }
    }
    while(!s.empty()){
        int k = s.top();
        s.pop();
        cnt[k]++;
    }

    int sum = 0;
    for(auto key : cnt){
        sum += key.second;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << minOperations(v);
    return 0;
}
