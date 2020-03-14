#include<iostream>
#include<cstdio>
using namespace std;
struct book{
    string ISBN;
    string name;
    double price;
};
struct Node{
    book data;
    Node *next;
};
void insert(Node* head,int pos,book e){
    Node *p = head;
    for (int i = 0; i < pos-1;i++){
        p = p->next;
        if(p==NULL and p->next==NULL){
            cout << "sorry, the storage location is illegal!" << endl;
            return;
        }
    }
    if(p->next!=NULL){
        Node *q = new Node;
        q->data = e;
        q->next = p->next;
        p->next = q;
    }
    else{
        Node *q = new Node;
        q->data = e;
        q->next = NULL;
        p->next = q;
    }
}
void print(Node *head){
    Node *p = head;
    while(p->next!=NULL){
        p = p->next;
        printf("%s %s %.2f\n", p->data.ISBN.c_str(), p->data.name.c_str(), p->data.price);
    }
}
void merge(Node *left,Node *right){
    Node *head = left;
    Node *p= new Node;
    p->next = NULL;
    Node *temp = p;
    while(left->next and right->next){
        if(left->next->data.price>right->next->data.price){
            p->next = left->next;
            left->next = left->next->next;
        }
        else{
            p->next = right->next;
            right->next = right->next->next;
        }
        p = p->next;
    }
    while(left->next){
        p->next = left->next;
        left->next = left->next->next;
        p = p->next;
    }
    while(right->next){
        p->next = right->next;
        right->next = right->next->next;
        p = p->next;
    }
    head->next = temp->next;
}
void mergesort(Node *head){
    if(!head->next or !head->next->next)
        return;
    Node *p = head, *q = head->next;
    while(q and q->next){
        p = p->next;
        q = q->next->next;
    }
    Node *right = new Node;
    right->next = p->next;
    p->next = NULL;
    mergesort(head);
    mergesort(right);
    merge(head, right);
}
void seqinsert(Node *head){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        book e;
        cin >> e.ISBN >> e.name >> e.price;
        insert(head, i + 1, e);
    }
}
void revinsert(Node *head){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        book e;
        cin >> e.ISBN >> e.name >> e.price;
        insert(head, 1, e);
    }
}
void deletenode(Node *head,int pos){
    if(pos<1){
        cout << "sorry, the delivery location is illegal!" << endl;
        return;
    }
    Node *p = head, *pre;
    for (int i = 0; i < pos;i++){
        pre = p;
        if(!p->next){
            p = p->next;
            break;
        }
        p = p->next;
    }
    if(p){
        pre->next = p->next;
        delete p;
    }
    else
        cout << "sorry, the delivery location is illegal!" << endl;
}
int main(){
    Node *head = new Node;
    head->next = NULL;
    seqinsert(head);
    mergesort(head);
    print(head);
    system("pause");
    return 0;
}