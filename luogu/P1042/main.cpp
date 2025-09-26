//
// Created by lenovo on 2025/1/7.
//
#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string read_string() {
    vector<char> chars;
    char c;
    while (cin >> c) {
        if (!isspace(c)) {
            chars.push_back(c);
        }
        if (c == 'E') {
            break;
        }
    }
    return string(chars.begin(), chars.end());
}

void rule_11(const string& s){
    int win = 0, lose = 0;
    int game_num = 0;
    for (char p : s) {
        // 判断读取是否结束
        if (p == '\0') {
            break;
        }

        // 读取数据
        if (p == 'W'){
            ++win;
        }
        else if (p == 'L') {
            ++lose;
        }

        // 判断是否需要输出
        if (win >= 11 || lose >= 11) {
            game_num = 1;
        }

        //  判断怎么输出
        if (game_num) {
            // 一局游戏
            if (win - lose >= 2 || lose - win >= 2){
                cout << win << ':' << lose << endl;
                win = 0;
                lose = 0;
                game_num = 0;
            }

                // 否则
            else {
                continue;
            }
        }
    }
    cout << win << ':' << lose << endl;
}

void rule_21(const string& s){
    int win = 0, lose = 0;
    int game_num = 0;
    for (char p : s) {
        // 判断读取是否结束
        if (p == '\0') {
            break;
        }

        // 读取数据
        if (p == 'W'){
            ++win;
        }
        else if (p == 'L') {
            ++lose;
        }
        else if (p == 'E') {
            break;
        }

        // 判断是否需要输出
        if (win >= 21 || lose >= 21) {
            game_num = 1;
        }

        //  判断怎么输出
        if (game_num) {
            // 一局游戏
            if (win - lose >= 2 || lose - win >= 2){
                cout << win << ':' << lose << endl;
                win = 0;
                lose = 0;
                game_num = 0;
            }

                // 否则
            else {
                continue;
            }
        }
    }
    cout << win << ':' << lose << endl;
}

int main() {
    string c = read_string();

    rule_11(c);
    cout << endl;
    rule_21(c);

    return 0;
}