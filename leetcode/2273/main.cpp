#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

vector<string> removeAnagrams(vector<string>& words) {
    vector<string> res;
    int n = words.size();
    for (int i = 0; i < n; ++i) {
        if (res.empty()) res.push_back(words[i]);
        else {
            if (!cmp(res.back(), words[i])) {
                res.push_back(words[i]);
            }
        }
    }
    return res;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}