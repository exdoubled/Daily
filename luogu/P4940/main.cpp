#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    vector< vector<ll> > v(2, vector<ll>());
     while (cin >> s) {
        if (s == "END") {
            cout << "SUCCESS" << endl;
            if (v[0].empty()) {
                cout << "NONE" << endl;
            } else {
                for (int i = v[0].size() - 1; i >= 0; --i) {
                    cout << v[0][i] << " ";
                }
                cout << endl;
            }
            if (v[1].empty()) {
                cout << "NONE" << endl;
            } else {
                for (int i = v[1].size() - 1; i >= 0; --i) {
                    cout << v[1][i] << " ";
                }
                cout << endl;
            }
            break;
        }
        else if (s == "PUSH") {
            int id;
            ll x;
            cin >> id >> x;
            if (id < 0 || id > 1) {
                cout << "UNSUCCESS" << endl;
                continue;
            }
            v[id].push_back(x);
            cout << "SUCCESS" << endl;
        }
        else if (s == "POP") {
            int id;
            cin >> id;
            if (id < 0 || id > 1 || v[id].empty()) cout << "UNSUCCESS" << endl;
            else {
                v[id].pop_back();
                cout << "SUCCESS" << endl;
            }
        }
        else if (s == "ADD") {
            int id;
            cin >> id;
            if (id < 0 || id > 1 || v[0].empty() || v[1].empty()) cout << "UNSUCCESS" << endl;
            else {
                ll a = v[0].back();
                ll b = v[1].back();
                v[0].pop_back();
                v[1].pop_back();
                v[id].push_back(a + b);
                cout << "SUCCESS" << endl;
            }
        } else if (s == "SUB") {
            int id;
            cin >> id;
            if (id < 0 || id > 1 || v[0].empty() || v[1].empty()) cout << "UNSUCCESS" << endl;
            else {
                ll a = v[0].back();
                ll b = v[1].back();
                v[0].pop_back();
                v[1].pop_back();
                v[id].push_back(abs(a - b));
                cout << "SUCCESS" << endl;
            }
        } else if (s == "DEL") {
            int id;
            cin >> id;
            if (id < 0 || id > 1) {
                cout << "UNSUCCESS" << endl;
                continue;
            }
            v[id].clear();
            cout << "SUCCESS" << endl;
        } else if (s == "MOVE") {
            int id1, id2;
            cin >> id1 >> id2;
            if (id1 < 0 || id1 > 1 || id2 < 0 || id2 > 1 || id1 == id2) {
                cout << "UNSUCCESS" << endl;
                continue;
            }
            v[id1].insert(v[id1].end(), v[id2].rbegin(), v[id2].rend());
            v[id2].clear();
            cout << "SUCCESS" << endl;
        } else if (s == "SWAP") {
            swap(v[0], v[1]);
            cout << "SUCCESS" << endl;
        }
    }
    return 0;
}