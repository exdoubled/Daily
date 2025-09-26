#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getZip(string s){
    int num = 0;
    string ans;
    bool key = true;
    for(int i = 0; key; ++i){
        if (s[i] == '['){
            num++;
        }
        if (s[i] == ']'){
            num--;
        }
        ans += s[i];
        if(num == 0) key = false;
    }
    return ans;
}

string unzip(string s){
    string ans;
    for(auto c=s.begin(); c!=s.end();){
        if (*c == '['){
            // 获取压缩包
            string temp = getZip(s);
            // 记录压缩包的长度
            auto length = temp.size();
            // 删除压缩包的壳子
            temp.erase(temp.begin());
            temp.erase(temp.end() - 1);
            // 记录压缩包解压的数量
            int num = 0;
            for(auto i=temp.begin(); i!=temp.end();){
                if(isdigit(*i)){
                    num = num*10 + *i - '0';
                    i = temp.erase(i);
                } else break;
            }
            // 剩余的再解压缩一次,直到temp中不含'['就返回
            temp = unzip(temp);
            // 记录此时解压后的temp
            string temp0 = temp;
            // 将temp复制
            for(int i = 1; i < num; ++i){
                temp += temp0;
            }
            // 删除s的数量
            for(int i = 0; i < length; ++i) c = s.erase(c);
            ans += temp;
            continue;
        }
        ans += *c;
        c = s.erase(c);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << unzip(s);

    return 0;
}
