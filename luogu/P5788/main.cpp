#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<int> nextGreaterIndex(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    stack<int> st; 

    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            nextGreaterIndex[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << nextGreaterIndex[i] << " ";
    }

    return 0;
}