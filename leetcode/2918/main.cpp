#include <iostream>
#include <vector>

using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2){
    long long sum1 = 0, sum2 = 0;
    int num01 = 0, num02 = 0;
    for(auto num1 : nums1){
        if(num1 == 0) num01++;
        sum1 += num1;
    }
    for(auto num2 : nums2){
        if(num2 == 0) num02++;
        sum2 += num2;
    }
    long long min1 = sum1 + num01;
    long long min2 = sum2 + num02;
    if(min1 == min2 || (min1 < min2 && num01) || (min1 > min2 && num02)) return min1 > min2 ? min1 : min2;
    else return -1;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
