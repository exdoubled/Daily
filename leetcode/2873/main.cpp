#include <iostream>
#include <vector>

using namespace std;

long long maximumTripletValue(vector<int>& nums){
    long long ans = 0;
    int lastI;
    int lastJ;
    int lastK;
    int n = (int)nums.size();
    for (int i = 0; i < n; ++i){
        if(i != 0 && nums[i] < lastI) continue;
        for (int j = i + 1;j < n; ++j){
            if(j != i+1 && nums[j] > lastJ) continue;
            for(int k = j + 1; k < n; ++k){
                if(k != j+1 &&  nums[k] < lastK) continue;
                long long temp = ((long long)nums[i] - (long long)nums[j]) * (long long)nums[k];
                if(temp <= 0) continue;
                ans = ans > temp ? ans : temp;
                lastK = nums[k];
            }
            lastK = 1;
            lastJ = nums[j];
        }
        lastJ = 0;
        lastI = nums[i];
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
    }
    cout << maximumTripletValue(v);

    return 0;
}
