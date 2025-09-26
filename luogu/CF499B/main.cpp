#include <iostream>
#include <string>
#include <vector>
// 未提交

using namespace std;

int find(vector<string> x, const string& val){
    for(int k = 0; k < x.size(); ++k){
        if (x[k] == val) return k;
    }
    return 0;
}

string shorter(const vector<string>& a, vector<string> b, const string& val){
    string temp = b[find(a, val)];
    return val.size() <= temp.size() ? val : temp;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a;
    vector<string> b;
    for (int i = 0; i < m; ++i){
        string temp;
        cin >> temp;
        a.push_back(temp);
        cin >> temp;
        b.push_back(temp);
    }
    vector<string> result;
    for (int i = 0; i < n; ++i){
        string temp;
        cin >> temp;
        result.push_back(shorter(a,b,temp));
    }

    for(auto i : result){
        cout << i << " ";
    }
    return 0;
}
