#include <iostream>
#include <vector>

using namespace std;

long long minTime(vector<int> skill, vector<int> mana) {
    int n = (int)skill.size();
    vector<long long> time(n, 0);
    for (int m : mana) {
        long long t = 0;
        long long off = 0;
        for (int i = 0; i < n; i++) {
            off = max(off, time[i] - t);
            t += (long long)skill[i] * m;
            time[i] = t;
        }
        for (int i = 0; i < n; i++) time[i] += off;
    }
    return time[n-1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}