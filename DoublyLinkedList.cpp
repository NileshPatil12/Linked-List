#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;

    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    ~node(){
        int d=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"The data deleted is "<<d<<endl;
    }

};

void InsertAtHead(node* & head,node* & tail,int data){
    if(head==NULL){
        node* temp=new node(data);
        head=temp;
        tail=temp;
        return;
    }
    node* temp=new node(data);
    temp->next=head;
    head=temp;
}

void InsertAtTail(node* &head,node* &tail,int data){
    if(tail==NULL){
        node* temp=new node(data);
        head=temp;
        tail=temp;
        return;
    }
    node* temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    
}

void InsertAtPosition(node* &head,node* & tail,int pos,int data){
    int cnt=1;
    node* temp=head;
    if(pos==1){
        InsertAtHead(head,tail,data);
        return;
    }
    while(cnt < pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        InsertAtTail(head,tail,data);
        return;
    }
    node* t=new node(data);
    t->next=temp->next;
    t->prev=temp;
    temp->next->prev=t;
    temp->next=t;
}

void DeleteAtPos(node* &head,node* &tail,int pos){
    int cnt=1;
    if(pos==1){
        node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }

    node* cur=head;
    node* prev=NULL;
    while(cnt<pos){
        cnt++;
        prev=cur;
        cur=cur->next;
    }
    if(cur->next==NULL){
        tail=prev;
    }
    cur->prev=NULL;
    prev->next=cur->next;
    cur->next=NULL;
    delete cur;
}

node* reverseDLL(node * head)
{
    
    node* prev=NULL;
    node* next=NULL;
    node* curr=head;
    while(curr!=NULL){
        next=curr->next;
        curr->prev=next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

int main()
{
    node* Nil=new node(3);
    node* head=Nil;
    node* tail=Nil;
    InsertAtHead(head,tail,2);
    InsertAtTail(tail,tail,4);
    print(head);
    InsertAtPosition(head,tail,2,5);
    print(head);
    DeleteAtPos(head,tail,2);
    print(head);


}