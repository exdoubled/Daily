#include <iostream>
#include <string>

using namespace std;

// 链表结点
struct ListNode {
    string data;
    int dic;
    ListNode *next;
    ListNode *last;
};

// 插入节点
void insertNode(ListNode *head, int dic, const string &data) {
    ListNode *newNode = new ListNode{data, dic, head->next, head->last};
    if (head->next == nullptr) {
        head->next = newNode;
        head->last = newNode;
        newNode->next = newNode;
        newNode->last = newNode;
    } else {
        head->last->next = newNode;
        head->next->last = newNode;
        head->last = newNode;
    }
}

// 删除所有节点
void deleteAllNodes(ListNode *head) {
    if (head->next == nullptr) {
        return;
    }
    ListNode *current = head->next;
    do {
        ListNode *next = current->next;
        delete current;
        current = next;
    } while (current != head->next);
    head->next = nullptr;
    head->last = nullptr;
}

// 移动操作
ListNode *move(ListNode *cur, int dic, int num, int n) {
    num %= n; // 确保移动次数不超过链表长度
    if (cur->dic == 0) { // 朝内
        if (dic == 0) { // 左数
            while (num-- > 0) {
                cur = cur->next;
            }
        } else { // 右数
            while (num-- > 0) {
                cur = cur->last;
            }
        }
    } else { // 朝外
        if (dic == 0) { // 左数
            while (num-- > 0) {
                cur = cur->last;
            }
        } else { // 右数
            while (num-- > 0) {
                cur = cur->next;
            }
        }
    }
    return cur;
}

int main() {
    int n, m;
    cin >> n >> m;
    ListNode *head = new ListNode{"", 0, nullptr, nullptr};

    // 输入链表
    for (int i = 0; i < n; ++i) {
        int dic;
        string data;
        cin >> dic >> data;
        insertNode(head, dic, data);
    }
    ListNode *cur = head->next;

    // 输入指令
    for (int i = 0; i < m; ++i) {
        int dic, num;
        cin >> dic >> num;
        cur = move(cur, dic, num, n);
    }

    cout << cur->data << endl;

    // 释放内存
    deleteAllNodes(head);
    delete head; // 释放头节点
    return 0;
}