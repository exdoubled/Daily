#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long goodTriplets(vector<int>& nums1, vector<int>& nums2){
    map<int, int> num2Pos;
    int n = (int)nums2.size();
    for(int i = 0; i < n; ++i){
        num2Pos[nums2[i]] = i;
    }
    vector<int> visited;
    visited.push_back(num2Pos[nums1[0]]);
    long long ans = 0;
    for(int i = 1; i < n; ++i){
        int index = num2Pos[nums1[i]];
        int next = 0;
        int prev = 0;
        if(visited.back() >= index){
            auto it = lower_bound(visited.begin(), visited.end(), index);
            prev = it - visited.begin();
            visited.insert(it, index);
        } else{
            prev = (int)visited.size();
            visited.push_back(index);
        }
        next = n-index-1-(i - prev);
        ans += (long long)next * prev;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> num1(n);
    vector<int> num2(n);
    for(int i = 0; i < n; ++i) cin >> num1[i];
    for(int i = 0; i < n; ++i) cin >> num2[i];
    cout << goodTriplets(num1, num2);
    return 0;
}
