#include <iostream>
#include <vector>
#include <set>

using namespace std;

int countCompleteSubarrays(vector<int>& nums){
    int l, r;
    l = r = 0;
    int n = (int)nums.size();
    int cnt = 0;
    set<int> set;
    for(auto num : nums){
        if(set.count(num) == 0){
            set.insert(num);
        }
    }
    cnt = (int)set.size();
    set.clear();
    int ans = 0;

    while(true){
        if(set.size() < cnt) {
            if(r == n) break;
            else{
                set.insert(nums[r]);
                r++;
            }
        }
        else if(set.size() == cnt){
            ans += n-r+1;
            set.clear();
            l++;
            r = l;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << countCompleteSubarrays(v);
    return 0;
}
