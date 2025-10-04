#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        max_area = max(max_area, h * w);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return max_area;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}