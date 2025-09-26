#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

vector<int> replaceNonCorimes(vector<int>& nums) {
    if (nums.size() <= 1) return nums;
    vector<int> result;
    result.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        int curr = nums[i];
        while (!result.empty() && gcd(result.back(), curr) > 1) {
            curr = (long long)result.back() * curr / gcd(result.back(), curr);
            result.pop_back();
        }
        result.push_back(curr);
    }
    return result;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
