#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T-- > 0){
        int n;
        cin >> n;
        unordered_set<int> s;
        vector<int> v(n);
        int temp;
        int count = 0;
        for(int i = 0; i < n; ++i){
            cin >> temp;
            if(s.find(temp) == s.end()){
                v[count] = temp;
                count++;
            }
            s.insert(temp);
        }
        for(int i = 0; i < count;++i) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}
