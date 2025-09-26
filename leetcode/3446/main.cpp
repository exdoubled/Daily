#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

inline int& at(vector<vector<int>>& g, int p, int i, int len) {
    // p >= 0: A[i] = g[i][i+p]
    // p < 0 : A[i] = g[len-i-p][len-i]
    return (p >= 0 ? g[i][i+p] : g[len-i-p][len-i]);
}


int paritition(vector<vector<int>>& grid, int p, int low, int high, int length) {
    int pivot = at(grid, p, low, length);
    while (low < high) {
        while (low < high && at(grid, p, high, length) >= pivot) --high;
        at(grid, p, low, length) = at(grid, p, high, length);
        while (low < high && at(grid, p, low, length) <= pivot) ++low;
        at(grid, p, high,length) = at(grid, p, low, length);
    }
    at(grid, p, low, length) = pivot;
    return low;
}

void quickSort(vector<vector<int>>& grid, int p, int low, int high, int length) //(vector<int> A, int low, int high)
{
    if (low < high) {
        int pivot = paritition(grid, p , low, high, length);
        quickSort(grid, p, low, pivot - 1, length);
        quickSort(grid, p, pivot + 1, high, length);
    }
}


vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    int n = (int)grid.size();
    for (int p = n - 1; p >= 1 - n; --p) {
        int len = n - abs(p);
        if (len > 1) {
            quickSort(grid, p, 0, len - 1, len - 1);
        }
    }
    return grid;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
