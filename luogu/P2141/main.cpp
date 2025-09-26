#include<bits/stdc++.h>

using namespace std;

int sum = 0;
int num[200];
int n;
bool inside(int search){
    for(int i = 0;i < n;i++){
        if(num[i] == search){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> num[i];
    }
    sort(num + 0,num + n);
    for(int i = n - 1;i >= 0;i--){
        for(int j = 0;j < i;j++){
            if(inside(num[i] - num[j]) and num[i] - num[j] != num[j]){
                sum += 1;
                break;
            }
        }
    }
    cout << sum;
    return 0;
}
