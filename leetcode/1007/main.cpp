#include <iostream>
#include <vector>

using namespace std;

int minDominoRotations(vector<int>& tops, vector<int>& bottoms){
    int n = (int)tops.size();
    int type;
    int top, bottom;
    type = tops[0];
    top = 1, bottom = 0;
    bool key1 = true;
    int ans1;
    for(int i = 1; i < n; ++i){
        if(tops[i] == type) {
            if(bottoms[i] == type) continue;
            top++;
        }
        else if (bottoms[i] == type) bottom++;
        else{
            key1 = false;
            break;
        }
    }
    if(key1){
        ans1 = min(top, bottom);
    }

    type = bottoms[0];
    top = 0, bottom = 1;
    bool key2 = true;
    int ans2;
    for(int i = 1; i < n; ++i){
        if(bottoms[i] == type) {
            if(tops[i] == type) continue;
            bottom++;
        }
        else if (tops[i] == type) top++;
        else{
            key2 = false;
            break;
        }
    }
    if(key2){
        ans2 = min(top, bottom);
    }

    if(key1){
        if(key2) return min(ans1, ans2);
        else return ans1;
    } else{
        if(key2) return ans2;
        else return -1;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> tops(n);
    for(int i = 0; i < n; ++i) cin >> tops[i];
    vector<int> bottoms(n);
    for(int i = 0; i < n; ++i) cin >> bottoms[i];
    cout << minDominoRotations(tops, bottoms);
    return 0;
}
