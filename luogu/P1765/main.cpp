#include <iostream>

using namespace std;

int get(char c){
    int ans = 0;
    switch (c) {
        case 'a':
        case 'd':
        case 'g':
        case 'j':
        case 'm':
        case 'p':
        case 't':
        case 'w': ans += 1;
            break;
        case 'b':
        case 'e':
        case 'h':
        case 'k':
        case 'n':
        case 'q':
        case 'u':
        case 'x': ans += 2;
            break;
        case 'c':
        case 'f':
        case 'i':
        case 'l':
        case 'o':
        case 'r':
        case 'v':
        case 'y': ans += 3;
            break;
        case 's':
        case 'z': ans += 4;
            break;
        default: ans += 1;
    }
    return ans;
}

int main() {
    char c;
    int ans = 0;
    while((c = getchar()) != '\n'){
        ans += get(c);
    }
    cout << ans;
    return 0;
}
