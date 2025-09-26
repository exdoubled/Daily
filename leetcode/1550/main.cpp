#include <iostream>
#include <vector>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr){
    int n = (int)arr.size();
    for(int p = 0; p < n; ++p){
        if(arr[p] & 1){
            if(p+1 < n && (arr[p+1] & 1)){
                if(p+2 < n && (arr[p+2] & 1)){
                    return true;
                } else p += 2;
            } else p += 1;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) cin >> v[i];
    cout << threeConsecutiveOdds(v);
    return 0;
}
