#include <iostream>
#include <algorithm>

using namespace std;

template<class Node>
class MyIterator{
private:
    Node* ptr;
public:
    MyIterator(Node* p = NULL):ptr(p){}

    Node& operator*(){
        return *ptr;    
    }

    Node* operator->(){
        return ptr;    
    }

    bool operator!=(const MyIterator& i){
        return ptr != i.ptr;    
    }

    bool operator==(const MyIterator& i){
        return ptr == i.ptr;    
    }

    MyIterator& operator++(){
        ptr = ptr->next;
        return *this;
    }

    MyIterator operator++(int){
        MyIterator tmp = *this;
        ++*this;
        return tmp;
    }

    MyIterator& operator=(Node* p){
        ptr = p;
        return *this;
    }

};

struct List{
    int val;
    List* next;
    List(int v):val(v), next(NULL){}
};

ostream& operator<<(ostream &os, const List& node){
    os << node.val;
    return os;
}

void print(List head){
    cout << head << " ";
}

List* remove(List *head){
    if(head == NULL){
        return NULL;    
    }        

    List *newHead = new List(0);
    List *p = head;
    while(p){
        List *tmp = p;
        p=p->next;
        tmp->next = NULL;
        List *q = newHead->next;
        while(q != NULL && q->val != tmp->val){
            q=q->next;    
        }

        if(q == NULL){
            tmp->next = newHead->next;
            newHead->next = tmp;
        }
    }
    cout << endl;
    head = newHead->next;
    delete newHead;
    return head;
}

void test(List *head){
    head = head->next;        
}
int main(int argc, char *argv[]){
    List n1(5);
    List n2(5);
    List n3(2);
    List n4(3);
    List n5(2);
    List n6(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    test(&n1);
    MyIterator<List> begin(&n1);
    MyIterator<List> end;

    for_each(begin, end, print);
    //cout << endl;
    //List *r = remove(&n1);
    //begin = r;
    //for_each(begin, end, print);
    //cout << endl;
    return 0;
}
