#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string s;
    cin >> s;
    // 转换成kx+b的形式
    bool isLeft = true;
    bool opera = true; // 加
    int num = 0;
    int lNum = 0, rNum = 0; // 常数
    int lX = 0, rX = 0; // 系数
    char x;
    for(auto c : s){
        if(isdigit(c)){
            num = num*10 + c-'0';
        } else if (c == '+'){
            if(isLeft){
                if(opera){
                    lNum += num;
                } else{
                    rNum += num;
                }
            } else{
                if(opera){
                    rNum += num;
                } else{
                    rNum -= num;
                }
            }
            num = 0;
            opera = true;
        } else if (c == '-'){
            if (isLeft){
                if(opera) {
                    lNum += num;
                } else{
                    rNum -= num;
                }
            } else{
                if(opera){
                    rNum += num;
                } else{
                    rNum -= num;
                }
            }
            num = 0;
            opera = false;
        } else if(c == '='){
            if(isLeft){
                if(opera){
                    lNum += num;
                } else{
                    lNum -= num;
                }
            } else{
                if(opera){
                    rNum += num;
                } else{
                    rNum -= num;
                }
            }
            num = 0;
            opera = true;
            isLeft = false;
        } else if (isalpha(c)){
            x = c;
            if(num == 0){
                num = 1;
            }
            if(isLeft){
                if(opera){
                    lX += num;
                } else{
                    lX -= num;
                }
            } else{
                if(opera){
                    rX += num;
                } else{
                    rX -= num;
                }
            }
            num = 0;
        }
    }
    if(num != 0){
        if(opera){
            rNum += num;
        } else{
            rNum -= num;
        }
    }
    double ans = (double)(rNum - lNum) / (double)(lX - rX);
    if(ans == 0.0){
        ans = abs(ans);
    }
    cout << x << "=";
    cout << fixed << setprecision(3) << ans;
    return 0;
}
