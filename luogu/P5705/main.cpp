#include <iostream>
#include <string>

using namespace std;

int main() {
    string arr;
    cin >> arr;
    for (int i = arr.length() - 1; i >= 0; --i){
        cout << arr[i];
    }
    return 0;
}
