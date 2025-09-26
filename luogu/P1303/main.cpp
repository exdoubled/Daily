#include <iostream>
#include <string>

using namespace std;

typedef struct ListNode{
    int val{};
    struct ListNode* next = nullptr;
} LN;

LN* create_node(LN* head,int val){
    LN* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    LN* node = new LN;
    node->val = val;
    temp->next = node;
    return head;
}

struct LL{
    LN* head;
    LL() : head(new LN) {}

    LL& operator=(const struct LL a){
        LN* temp = a.head;
        while(temp != nullptr){
            temp = temp->next;
            this->head = create_node(this->head, temp->val);
        }
        return *this;
    }

    LL operator+(const struct LL a) const{
        struct LL result{};
        LN* temp1 = this->head, * temp2 = a.head;
        if (temp1 == nullptr){
            return a;
        }
        if (temp2 == nullptr){
            return *this;
        }

        int ge;
        int shi = 0;
        while(temp1->next != nullptr && temp2->next != nullptr){
            temp1 = temp1->next;
            temp2 = temp2->next;
            ge = (temp1->val + temp2->val + shi) % 10;
            result.head = create_node(result.head, ge);
            shi = (temp1->val + temp2->val + shi) / 10;
        }

        while(temp1->next == nullptr && temp2->next != nullptr){
            temp2 = temp2->next;
            ge = (temp2->val + shi) % 10;
            result.head = create_node(result.head, ge);
            shi = (temp2->val + shi) / 10;
        }

        while(temp2->next == nullptr && temp1->next != nullptr){
            temp1 = temp1->next;
            ge = (temp1->val + shi) % 10;
            result.head = create_node(result.head, ge);
            shi = (temp1->val + shi) / 10;
        }

        return result;
    }

    LL operator*(const struct LL a) const{
        struct LL result{};
        LN* temp1 = this->head, * temp2 = a.head;
        if (temp1 == nullptr){
            return a;
        }
        if (temp2 == nullptr){
            return *this;
        }

        int ge;
        int shi = 0;
        while(temp1->next != nullptr && temp2->next != nullptr){
            temp1 = temp1->next;
            temp2 = temp2->next;
            ge = (temp1->val * temp2->val + shi) % 10;
            result.head = create_node(result.head, ge);
            shi = (temp1->val * temp2->val + shi) / 10;
        }

        while(temp1->next == nullptr && temp2->next != nullptr){
            temp2 = temp2->next;
            ge = (temp2->val + shi) % 10;
            result.head = create_node(result.head, ge);
            shi = (temp2->val + shi) / 10;
        }

        while(temp2->next == nullptr && temp1->next != nullptr){
            temp1 = temp1->next;
            ge = (temp1->val + shi) % 10;
            result.head = create_node(result.head, ge);
            shi = (temp1->val + shi) / 10;
        }

        return result;
    }
};

istream & operator>>(istream &in, LL& a){
    char c;
    while(in.get(c) && c != '\n'){
        if (isdigit(c)){
            a.head = create_node(a.head, c - '0');
        }
    }
    return in;
}

ostream & operator<<(ostream &out, const LL a){
    LN *temp = a.head;
    if (temp == nullptr) return out;
    while (temp->next != nullptr){
        temp = temp->next;
        out << temp->val;
    }
    return out;
}

void delete_LL(LL a){
    LN* b = a.head;
    while(b->next != nullptr){
        LN* temp = b;
        b = b->next;
        delete temp;
    }
}

int main() {
    LL a{}, b{};
    cin >> a >> b;
    LL c = a + b;
    cout << c;
    delete_LL(a);
    delete_LL(b);
    delete_LL(c);

    return 0;
}
