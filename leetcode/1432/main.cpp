#include <iostream>

using namespace std;

int maxDiff(int num) {
    int maxNum = 0;
    int minNum = 0;
    string s = to_string(num);
    char temp = '9';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '9') continue;
        else {
            temp = s[i];
            break;
        }
    }
    for (char & i : s) {
        if (i == temp) i = '9';
    }
    maxNum = atoi(s.c_str());

    s = to_string(num);
    if (s[0] != '1') {
        temp = s[0];
        for (char & i : s) {
            if (i == temp) i = '1';
        }
    } else {
        temp = '0';
        bool allEq = true;
        bool find = false;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != '0' && !find && s[i] != s[0]) {
                temp = s[i];
                find = true;
            }
            if (s[i] != s[i-1]) allEq = false;
        }
        if (!allEq) {
            for (char & i : s) {
                if (i == temp) i = '0';
            }
        }
    }
    minNum = atoi(s.c_str());
    return maxNum - minNum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}