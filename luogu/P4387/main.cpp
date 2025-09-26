#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;
    while(q-- > 0) {
        int n;
        cin >> n;
        vector<int> pushed(n);
        for(int i = 0; i < n; ++i) {
            cin >> pushed[i];
        }
        vector<int> poped(n);
        for(int i = 0; i < n; ++i) {
            cin >> poped[i];
        }

        stack<int> st;
        int i = 0;
        bool valid = true;
        for(int x : poped) {
            if(!st.empty() && st.top() == x) {
                st.pop();
            } else {
                while(i < n && pushed[i] != x) {
                    st.push(pushed[i]);
                    i++;
                }
                if(i == n) {
                    valid = false;
                    break;
                }
                i++;
            }
        }
        cout << (valid ? "Yes" : "No") << endl;
    }
    return 0;
}