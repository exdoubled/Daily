#include<iostream>
#include<cstring>

using namespace std;

char f[5005][2000];
inline void bigAdd(char *ret,const char *f1,const char *f2){
    int flag = 0;
    int i;
    for(i = 0;f1[i]!='\0'||f2[i]!='\0'||flag;++i){
        int a = f1[i]?f1[i]-'0':0;
        int b = f2[i]?f2[i]-'0':0;
        if(a+b+flag >= 10){
            ret[i] = a+b+flag-10+'0';
            flag = 1;
        }
        else{
            ret[i] = a+b+flag+'0';
            flag = 0;
        }
    }
}
int main(){
    int n;
    cin >> n;
    strcpy(f[0],"0");
    strcpy(f[1],"1");
    strcpy(f[2],"2");
    for(int i = 3;i <= n;i++)
        bigAdd(f[i],f[i-2],f[i-1]);
    for(int i = strlen(f[n])-1;i >= 0;--i)
        cout << f[n][i];
    cout << endl;

    return 0;
}
