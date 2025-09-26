#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    auto start = v.begin();
    auto end = v.begin();
    vector<int> counts;
    vector<int> elements;

    int count = 0;
    while(end < v.end()){
        if(*start != *end){
            elements.push_back(*start);
            counts.push_back(count);
            start = end;
            count = 0;
        }
        count++;
        end++;
    }
    elements.push_back(*start);
    counts.push_back(count);

    for(int i = 0; i < elements.size(); i++){
        cout << elements[i] << " " << counts[i] << endl;
    }

    return 0;
}
