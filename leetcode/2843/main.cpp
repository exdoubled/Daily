#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int& num){
    string numS = to_string(num);
    if(numS.size() % 2 == 1) return false;
    int a = 0;
    int b = 0;
    int n = (int)numS.size();
    for(int i = 0; i < n/2; ++i){
        a += numS[i]-'0';
    }
    for(int i = n/2; i < n; ++i){
        b += numS[i]-'0';
    }
    if(a == b) return true;
    else return false;
}

int countSymmetricIntegers(int& low, int& high){
    int ans = 0;
    for(int i = low; i <= high; ++i){
        if(check(i)){
            ans++;
        }
    }
    return ans;
}

int main() {
    int low, high;
    cin >> low >> high;
    cout << countSymmetricIntegers(low, high);
    return 0;
}
