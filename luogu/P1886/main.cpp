#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class MaxQueue {
public:
    MaxQueue() {}
    int max_value() {
        if(!maxDeq.empty()) return maxDeq.front();
        else return -1;
    }

    void push_back(int value) {
        dataDeq.push_back(value);
        if(maxDeq.empty()) {
            maxDeq.push_back(value);
            return;
        }
        while(!maxDeq.empty() && maxDeq.back() < value)
            maxDeq.pop_back();
        maxDeq.push_back(value);
    }

    //弹出队首元素
    int pop_front() {
        if(!dataDeq.empty()) {
            int ret = dataDeq.front();
            dataDeq.pop_front();
            if(maxDeq.front() == ret)
                maxDeq.pop_front();
            return ret;
        }
        return -1;
    }

private:
    deque<int> dataDeq;
    deque<int> maxDeq;
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0 ; i < n; ++i) cin >> nums[i];
    vector<int> min;
    vector<int> max;

    MaxQueue q;
    int cnt = 0;
    int i = 0;
    while(cnt <= k && i < n){
        if(cnt < k){
            q.push_back(nums[i]);
        } else if(cnt == k){

        }
    }

    return 0;
}
