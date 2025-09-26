#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& dimensions){
    int maxI = 0;
    int ans = dimensions[maxI][0] * dimensions[maxI][1];
    int length = (int)dimensions.size();
    for(int i = 1; i < length; ++i){
        if(pow(dimensions[i][0],2) + pow(dimensions[i][1],2) > pow(dimensions[maxI][0],2) + pow(dimensions[maxI][1],2)){
            maxI = i;
            ans = dimensions[i][0] * dimensions[i][1];
        } else if(pow(dimensions[i][0],2) + pow(dimensions[i][1],2) == pow(dimensions[maxI][0],2) + pow(dimensions[maxI][1],2)){
            ans = ans > dimensions[i][0] * dimensions[i][1] ? ans : dimensions[i][0] * dimensions[i][1];
        }
    }
    return ans;
}

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
