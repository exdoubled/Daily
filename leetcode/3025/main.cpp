#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
}

int numberOfPairs(vector<vector<int>>& points){
    int ans = 0;
    sort(points.begin(),points.end(), cmp);
    int num = (int)points.size();
    for(int i = 0; i < num; ++i){
        int a = points[i][1];
        int max_y = INT32_MIN;
        for(int j = i + 1; j < num; ++j) {
            int b = points[j][1];
            if(a >= b && b > max_y){
                max_y = b;
                ++ans;
            }
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
