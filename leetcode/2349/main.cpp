#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class NumberContainers{
public:
    unordered_map<int, int> nums;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> pos;
    NumberContainers() = default;

    void change(int index, int number) {
        nums[index] = number;
        pos[number].push(index);
    }

    int find(int number) {
        if(pos.find(number) == pos.end()) return -1;
        for(auto & pq = pos[number]; !pq.empty(); pq.pop()){
            if(nums[pq.top()] == number) return pq.top();
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
