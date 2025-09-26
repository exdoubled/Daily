#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node{
    string data;
    int pos{};
};

bool cmp(const Node& c, const Node& d){
    // 大于比较
    const string& a = c.data;
    const string& b = d.data;
    if (a.length() != b.length())
        return a.length() > b.length();
    for (int i = 0; i < a.length(); ++i) {
        int numA = a[i] - '0';
        int numB = b[i] - '0';
        if (numA != numB)
            return numA > numB; // 高位不同时决定大小
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Node> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].data;
        v[i].pos = i + 1;
    }
    sort(v.begin(),v.end(),cmp);
    cout << v[0].pos << endl << v[0].data;

    return 0;
}
