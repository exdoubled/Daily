#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void getLineAns(const string& input) {
    int num = 0;
    int n = (int)input.size();
    string temp;

    vector<string> s;
    for(int i = 0; i < n; ++i) {
        if (input[i] == ' ') {            // 到下一个单词
            if (!temp.empty()) {
                s.push_back(temp);
                temp.clear();
                num++;
            }
        } else temp += input[i];          // 其他情况
    }

    if(!temp.empty()) {
        s.push_back(temp);
        num++;
    }

    sort(s.begin(), s.end());

    cout << num << " ";
    for(const auto& ss : s) cout << ss << " ";
    cout << endl;
}

int main() {
    string input;
    while (getline(cin, input)) {
        if (input.empty()) {
            cout << "0" << endl;
            continue;
        };
        getLineAns(input);
    }
    return 0;
}