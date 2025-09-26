#include <iostream>
#include <vector>

using namespace std;

int lengthAfterTransformations(string s, int t) {
        int ans=0;
        int mod=(int) (1e9+7);
        vector<vector<int>> map(t+1, vector<int>(26));
        for(char c : s) {
            map[0][c-'a']++;
        }
        for(int i=1;i<=t;i++) {
            for(int j=1;j<26;j++) {
                map[i][j]=map[i-1][j-1];
            }
            map[i][0]=(map[i][0]+map[i-1][25])%mod;
            map[i][1]=(map[i][1]+map[i-1][25])%mod;
        }
        for(int i:map[t]) {
            ans=(ans+i)%mod;
        }
        return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
