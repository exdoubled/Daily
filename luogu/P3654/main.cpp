#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r,c,k;
    cin >> r >> c >> k;
    vector<vector<char>> map(r, vector<char>(c));
    vector<vector<char>> mapReverse(c, vector<char>(r));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j) {
            cin >> map[i][j];
            mapReverse[j][i] = map[i][j];
        }
    }

    int ans = 0;

    // 遍历行
    for(auto row : map){
        int left = 0;
        int right = 0;
        while(right < c){
            right++;
            if(row[left] == '.'){
                if(right == c || row[right] == '#'){
                    int temp = right - left;
                    ans += temp >= k ? temp - k + 1 : 0;
                    left = right;
                }
            } else{
                if(row[right] == '.'){
                    left = right;
                }
            }
        }
    }
    // 遍历列
    for(auto col : mapReverse){
        int left = 0;
        int right = 0;
        while(right < r){
            right++;
            if(col[left] == '.'){
                if(right == r || col[right] == '#'){
                    int temp = right - left;
                    ans += temp >= k ? temp - k + 1 : 0;
                    left = right;
                }
            } else{
                if(col[right] == '.'){
                    left = right;
                }
            }
        }
    }
    if(k == 1) ans /= 2;

    cout << ans;
    return 0;
}
