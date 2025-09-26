#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool cmp(const string& a, const string& b){
    bool ans = true;
    if (a.size() > b.size()) return false;

    for(int i = 0; i < a.size(); ++i){
        if(a[i] != b[i]){
            ans = false;
            break;
        }
    }
    return ans;
}

int countPredixes(vector<string>& words, string s){
    int ans = 0;
    for(auto word : words){
        if(cmp(word, s)){
            ++ans;
        }
    }
    return ans;
}


int main() {
    string s;

    cin >> s;
    int n = 0;
    cin >> n;
    vector<string> words(n);

    for(int i = 0; i < n; ++i){
        cin >> words[i];
    }

    cout << countPredixes(words,s);
    return 0;
}
