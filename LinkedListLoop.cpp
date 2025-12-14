#include <iostream>
using namespace std;

struct Node{
    Node* next;

    Node(*Node nextNode = nullptr) : next(nextNode) {}

    Node* getNext(){
        return next;
    }
};

int getLoopSize(Node* startNode){
    Node* slow = startNode;
    Node* fast = startNode;

    do {
        slow = slow->getNext();
        fast = fast->getNext()->getNext();
    } while (slow != fast)

    int length_count = 0;

    do{
        slow = slow->getNext();
        length_count++;
    } while (slow != fast)

    return length_count;
}

int main(){

    Node a, b, c , d;

    a = &b;
    b = &c;
    c = &d;
    d = &b;

    int loop_size = getLoopSize(&a);
    cout << loop_size << endl;
    
    return 0;
}
