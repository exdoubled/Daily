#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findNumbers(vector<int>& nums){
    int ans = 0;
    for(auto num : nums){
        string temp = to_string(num);
        if(temp.size() & 1) continue;
        else ans++;
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
