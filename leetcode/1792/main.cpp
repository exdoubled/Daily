#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    double a_pass, a_total, b_pass, b_total;
    bool operator()(const vector<int>& a, const vector<int>& b){
        a_pass = a[0], a_total = a[1], b_pass = b[0], b_total = b[1];
        if((a_total - a_pass) / ((a_total + 1) * a_total) > (b_total - b_pass) / ((b_total + 1) * b_total)) return false;
        else return true;
    }
};

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents){
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    vector<int> top;
    int num = (int)classes.size();
    for(int i = 0; i < num; ++i) pq.emplace(classes[i]);
    while(extraStudents--){
        top.assign(pq.top().begin(), pq.top().end());
        pq.pop();
        ++top[0];
        ++top[1];
        pq.emplace(top);
    }

    // 计算答案
    double sum = 0.0;
    while(!pq.empty()){
        top.assign(pq.top().begin(), pq.top().end());
        pq.pop();
        sum += (double) top[0] / (double) top[1];
    }
    return sum / num;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
