#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct link_list {
    int data;
    struct link_list* next;
} LL;

LL * create_node(int n) {
    LL * new_node = (LL*)malloc(sizeof(LL));
    new_node->next = nullptr;
    new_node->data = n;
    return new_node;
}

void tail_insert(LL * &head, int k) {
    LL * new_node = create_node(k);
    if (head == nullptr) {
        head = new_node;
        return;
    }
    LL * cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = new_node;
}

void del_LL(LL * &head) {
    while (head != nullptr) {
        LL * temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;
    if (num1.length() < num2.length()) {
        swap(num1, num2);
    }

    int i = num1.length() - 1, j = num2.length() - 1;
    int carry = 0;
    LL * result = nullptr;

    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = i >= 0 ? num1[i] - '0' : 0;
        int digit2 = j >= 0 ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        tail_insert(result, sum % 10);
        i--; j--;
    }

    LL * prev = nullptr, *current = result, *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    result = prev;

    LL * cur = result;
    while (cur != nullptr) {
        cout << cur->data;
        cur = cur->next;
    }
    cout << endl;

    del_LL(result);

    return 0;
}