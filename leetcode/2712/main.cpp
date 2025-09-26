#include <iostream>
#include <string>

using namespace std;

long long minimumCost(string s){
    int size = s.size();
    long long sum = 0;
    for(int i = 1; i < size; ++i)
        if(s[i-1] != s[i]) sum += i < size-i ? i : size-i;
    return sum;
}

int main() {
    string s;
    cin >> s;
    cout << minimumCost(s);
    return 0;
}
