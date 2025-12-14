#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class ReversedLinkList{
    public:
    //returns reverse LL
    ListNode* reverseList(ListNode* node){
        ListNode *cur = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;

        while(cur != NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
    }
    private:
    ListNode* head;
};

ListNode* reverseListSimple(ListNode* head){
    ListNode* cur = head;
    ListNode* next = NULL;
    ListNode* prev = NULL;

    while(cur !=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node5;
    node5->next = NULL;

    ReversedLinkList reverser;

    cout << "Original Linked List: ";
    ListNode* current = node1;
    while (current != NULL){
        cout << current->val;
        if (current->next != NULL) cout << "->";
        current = current->next;

    }
    cout << endl;

   ListNode* reversedHead = reverseListSimple(node1);

   cout << "Reversed Link Lists: ";
   current = reversedHead;
   while(current != NULL){
    cout << current -> val;
    if(current->next !=NULL) cout << " -> ";
    current = current->next;
   }
   cout << endl;

   current = reversedHead;
   while(current != NULL){
    ListNode* temp = current;
    current = current->next;
    delete temp;
   }
   return 0;
}