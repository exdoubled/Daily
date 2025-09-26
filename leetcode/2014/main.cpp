#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

string longestSubsequenceRepeatedK(string s, int k) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    vector<char> words;
    for(auto& [ch, cnt] : freq) {
        if (cnt >= k) words.push_back(ch);
    }
    sort(words.begin(), words.end());

    auto check = [&](const string& str) -> bool {
        int cnt = 0, idx = 0;
        for(char c : s) {
            if (c == str[idx]) {
                idx++;
                if (idx == (int)str.size()) {
                    cnt++;
                    idx = 0;
                    if (cnt == k) return true;
                }
            }
        }
        return false;
    };

    string ans;
    queue<string> q;
    q.push("");
    unordered_set<string> vis;

    while(!q.empty()) {
        string top = q.front();
        q.pop();

        for(char c : words) {
            string newS = top + c;
            if (vis.count(newS)) continue;
            vis.insert(newS);

            if (check(newS)) {
                q.push(newS);
                if(
                        newS.length() > ans.length() ||
                        (newS.length() == ans.length() && newS > ans)
                        ) {
                    ans = newS;
                }
            }
        }
    }
    return ans;
}
int main() {
    string s;
    int k;
    cin >> s >> k;
    cout << longestSubsequenceRepeatedK(s,k);
    return 0;
}
