//
// Created by lenovo on 2025/1/7.
//
#include <iostream>

using namespace std;

bool in_map(int x, int y, int n, int m) {
    if (x >= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;
}

int mine_num(char ** a, int x, int y, int n, int m){
    int num = 0;
    if (in_map(x-1, y-1, n, m) && a[x-1][y-1] == '*') {
        ++num;
    }

    if (in_map(x-1, y, n, m) && a[x-1][y] == '*') {
        ++num;
    }

    if (in_map(x-1, y+1, n, m) && a[x-1][y+1] == '*') {
        ++num;
    }

    if (in_map(x, y-1, n, m) && a[x][y-1] == '*') {
        ++num;
    }

    if (in_map(x, y+1, n, m) && a[x][y+1] == '*') {
        ++num;
    }

    if (in_map(x+1, y-1, n, m) && a[x+1][y-1] == '*') {
        ++num;
    }

    if (in_map(x+1, y, n, m) && a[x+1][y] == '*') {
        ++num;
    }

    if (in_map(x+1, y+1, n, m) && a[x+1][y+1] == '*') {
        ++num;
    }

    return num;
}

void game() {
    int n, m;
    cin >> n >> m;
    char **a = new char *[n];
    for (int i = 0; i < n; ++i)
        a[i] = new char[m];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (a[i][j] == '*') {
                cout << '*';
                continue;
            }
            cout << mine_num(a, i, j, n, m);
        }
        if (i != n-1)
            cout << endl;
    }

    for (int i = 0; i < n; ++i)
        delete [] a[i];
    delete[] a;

}

int main(){
    game();
    return 0;
}