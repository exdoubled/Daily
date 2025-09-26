#include <iostream>
#include <vector>

using namespace std;



int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships){
    auto hasConnect = [&languages , &friendships](int i) -> bool {
        int x = friendships[i][0];
        int y = friendships[i][1];
        for(auto l1 : languages[x-1]){
            for(auto l2 : languages[y-1]){
                if(l1 == l2) return true;
            }
        }
        return false;
    };
    vector<int> l(n+1, 0);
    int m = (int)friendships.size();
    int numUsers = languages.size();
    vector<bool> hasDone(numUsers+1, false);
    int all = 0;
    for(int i = 0; i < m; ++i){
        if(!hasConnect(i)){
            if(!hasDone[friendships[i][0]]){
                for(auto l1 : languages[friendships[i][0]-1]) l[l1]++;
                hasDone[friendships[i][0]] = true;
                all++;
            }
            if(!hasDone[friendships[i][1]]){
                for(auto l2 : languages[friendships[i][1]-1]) l[l2]++;
                hasDone[friendships[i][1]] = true;
                all++;
            }
        }
    }
    int max = 0;
    for(auto num : l) max = std::max(max, num);

    return all - max;

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
