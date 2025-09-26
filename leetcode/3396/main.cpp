#include <iostream>
#include <vector>

using namespace std;

bool diff(vector<int>& nums){
    if(nums.empty()) return true;
    else{
        bool key = true;
        int n = (int)nums.size();
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(nums[i] == nums[j]) return false;
            }
        }
        return key;
    }
}

int minimumOperations(vector<int>& nums){
    int ans = 0;
    while(!diff(nums)){
        if(nums.size() >= 3){
            nums.erase(nums.begin(), nums.begin()+3);
            ans++;
        }
        else{
            nums.clear();
            ans++;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << minimumOperations(v);
    return 0;
}
