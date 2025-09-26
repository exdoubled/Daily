#include <iostream>
#include <vector>

using namespace std;

void pop(vector<int>& v, int k){
    cout << v[k] << " ";
    v.erase(v.begin()+k);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) nums[i] = i+1;
    int cnt = 1;
    int it = 0;
    while(!nums.empty()){
        if(cnt % k == 0){
            pop(nums, it);
            n--;
            it--;
        }
        cnt++;
        it = n != 0 ? (it+1) % n : it;
    }
    return 0;
}
