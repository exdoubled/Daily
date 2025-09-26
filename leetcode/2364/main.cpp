#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

long long countBadPairs(vector<int>& nums){
    int n = (int)nums.size();
    vector<int> goodNums(n);
    unordered_map<int, int> record;
    for(int i = 0; i < n;++i){
        goodNums[i] = nums[i] - i;
        if(record.count(goodNums[i])){
            record[goodNums[i]]++;
        } else{
            record[goodNums[i]] = 1;
        }
    }
    long long goodCNT = 0;
    for(auto cnt : record){
        goodCNT += (cnt.second * (cnt.second-1)) / 2;
    }

    long long sum = n*(n-1) / 2;
    return sum - goodCNT;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i) cin >> nums[i];
    cout << countBadPairs(nums);
    return 0;
}
