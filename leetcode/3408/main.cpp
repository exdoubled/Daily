#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class TaskManager
{
private:
    vector<int> userIds;
    vector<int> taskIds;
    vector<int> priorities;
    vector<int> version; // 添加版本号
    priority_queue<tuple<int, int, int, int>> pq; // (优先级, 任务ID, 用户ID, 版本号)
    int currentVersion = 0;

public:
    TaskManager(vector<vector<int>>& tasks)
    {
        int n = (int)tasks.size();
        userIds.resize(n);
        taskIds.resize(n);
        priorities.resize(n);
        version.resize(n);
        for(int i = 0; i < n; i++) {
            userIds[i] = tasks[i][0];
            taskIds[i] = tasks[i][1];
            priorities[i] = tasks[i][2];
            version[i] = currentVersion++;
            pq.emplace(priorities[i], taskIds[i], userIds[i], version[i]);
        }
    }

    void add(int userId, int taskId, int priority)
    {
        userIds.push_back(userId);
        taskIds.push_back(taskId);
        priorities.push_back(priority);
        version.push_back(currentVersion++);
        pq.emplace(priority, taskId, userId, version.back());
    }

    void edit(int taskId, int newPriority)
    {
        for(int i = 0; i < (int)taskIds.size(); i++) {
            if(taskIds[i] == taskId && priorities[i] != -1) {
                priorities[i] = newPriority;
                version[i] = currentVersion++;
                pq.emplace(newPriority, taskId, userIds[i], version[i]);
                break;
            }
        }
    }

    void rmv(int taskId)
    {
        for(int i = (int)taskIds.size() - 1; i >= 0; i--) {
            if (taskIds[i] == taskId && priorities[i] != -1) {
                priorities[i] = -1;
                break;
            }
        }
    }

    int execTop() {
        while (!pq.empty()) {
            auto [priority, egTaskId, egUserId, egVersion] = pq.top();
            pq.pop();

            // 通过版本号快速验证记录有效性
            for (int i = 0; i < (int) taskIds.size(); i++) {
                if (taskIds[i] == egTaskId &&
                    userIds[i] == egUserId &&
                    version[i] == egVersion &&
                    priorities[i] != -1) {
                    priorities[i] = -1;
                    return egUserId;
                }
            }
        }
        return -1;
    }
};


int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}