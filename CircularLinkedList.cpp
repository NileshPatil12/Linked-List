#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int d=this->data;
        this->next=NULL;
        delete next;
        cout<<"Deleted data is "<<d<<endl;
    }
};

void insertNode(Node* &tail,int element,int d){
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr=curr->next;
        }

        Node * temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;

    }
}

void deleteAtvalue(Node* &tail,int val){
    if(tail == NULL){
        cout<<" List is empty, please check again "<<endl;
        return;
    }
    else{
        Node* prev=tail;
        Node* cur=prev->next;
        while (cur->data != val)        
        {
            prev=cur;
            cur=cur->next;
        }

        prev->next=cur->next;
        if(cur==prev){
            tail=NULL;
        }

        if(tail==cur){
            tail=prev;
        }

        cur->next=NULL;
        delete cur;
        
    }
}

bool isCircular(Node* head){
    // Write your code here.
    if(head==NULL){
        return NULL;
    }
    cout<<"Hello"<<endl;
    Node* temp = head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}

void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"It is empty "<<endl;
        return;
    }
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    } while (tail != temp);
    cout<<endl;
}

int main()
{
    Node* tail=NULL;
    insertNode(tail,3,1);
    print(tail);
    insertNode(tail,1,2);
    print(tail);
    // deleteAtvalue(tail,2);
    // print(tail);
    // deleteAtvalue(tail,1);
    // print(tail);cout<<endl;
    if(isCircular(tail)){
        cout<<"it is circular "<<endl;
    }
}