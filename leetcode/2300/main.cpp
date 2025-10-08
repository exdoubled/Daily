#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans;
    for (int spell : spells) {
        int left = 0, right = (int)potions.size() - 1;
        int idx = (int)potions.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if ((long long) spell * potions[mid] >= success) {
                idx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        ans.push_back((int)potions.size() - idx);
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}