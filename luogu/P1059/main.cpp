#include <iostream>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> k;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        k.insert(temp);
    }

    cout << k.size() << endl;
    for (auto &i : k){
        cout << i << " ";
    }
}
