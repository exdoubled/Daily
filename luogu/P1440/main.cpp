#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    deque<int> st;

    cout << 0 << endl;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && v[st.back()] > v[i]) {
            st.pop_back();
        }
        st.push_back(i);
        if (i != n-1) {
            while (st.front() <= i - m) {
                st.pop_front();
            }
            cout << v[st.front()] << endl;
        }
    }
    return 0;
}