#include <string>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n % 2 != 0){
            return false;
        }

        int minB = 0, maxB = 0;
        for (int i = 0; i < n; ++i) {
            if(locked[i] == '0'){
                minB = minB - 1 > 0 ? minB - 1 : 0;
                maxB++;
            } else {
                if(s[i] == '(') {
                    minB++;
                    maxB++;
                } else { // s[i] == ')'
                    minB = minB - 1 > 0 ? minB - 1 : 0;
                    maxB--;
                }
            }
            if(maxB < 0) {
                return false;
            }
        }
        return minB == 0 ? true : false;
    }
};