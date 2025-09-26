#include <vector>
#include <iostream>

  using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void downsort(vector<ListNode*>& dui, int i){
    int n = (int)dui.size();
    while (true) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < n && dui[left]->val < dui[smallest]->val) {
            smallest = left;
        }
        if (right < n && dui[right]->val < dui[smallest]->val) {
            smallest = right;
        }
        if (smallest == i) break;
        swap(dui[i], dui[smallest]);
        i = smallest;
    }
}

void firstsort(vector<ListNode*>& dui) {
    int num = (int)dui.size();
    for(int i = num/2 - 1; i >= 0; i--){
        downsort(dui,i);
    }
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int num = lists.size();
    if(num==0) return nullptr;
    vector<ListNode*> dui;
    for(int i=0;i<num;i++){
        dui.push_back(lists[i]);
    }
    firstsort(dui);
    ListNode* current=nullptr;
    ListNode* head=nullptr;
    while(dui[0]->next!=nullptr){
        if(head == nullptr){
            current=new ListNode(dui[0]->val);
            head= current;
        }
        else {
            current->next =new ListNode(dui[0]->val);
            current=current->next;
        }
        dui[0]=dui[0]->next;
        downsort(dui,0);
    }
    if(head==nullptr){
        current=new ListNode(dui[0]->val);
        head= current;
    }
    else {
        current->next =new ListNode(dui[0]->val);
        current=current->next;
    }
    vector<ListNode*> nextListNode(num-1);
    for(int i=0;i<num-1;i++){
        nextListNode[i]= dui[i+1];
    }
    current->next=mergeKLists(nextListNode);
    return head;
}

void swap(ListNode*& a,ListNode*& b){
    ListNode* temp=a;
    a=b;
    b=temp;
}

int main(){

}

