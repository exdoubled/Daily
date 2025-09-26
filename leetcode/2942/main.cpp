#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x){
    vector<int> ans;
    int n = (int)words.size();
    for(int i = 0; i < n; ++i){
        if(words[i].find(x) != words[i].npos){
            ans.emplace_back(i);
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
