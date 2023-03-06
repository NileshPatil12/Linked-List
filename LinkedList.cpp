#include<iostream>
#include<unordered_map>
#include<map>
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

void InsertAtHead(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
Node *removeDuplicates_map(Node *head)
{
     if(head == NULL){
       return NULL;
   }
   if(head->next == NULL){
       return head;
   }
   unordered_map<int,bool>visited;
   Node* curr = head;
   Node* pre = NULL;
   while(curr != NULL){
      if(visited[curr->data] == true){
          
          Node* del = curr;
          pre->next = curr->next;
          curr = curr->next;
          delete del;
      }
      else{
           visited[curr->data] = true;
           pre = curr;
           curr = curr->next;
      }
   }
 return head;
}

Node * uniqueSortedList(Node * head) {
    // Write your code here.
     // Write your code here
    if(head==NULL){
        return NULL;
    }
    Node* curr=head;
    while(curr!=NULL){
        if((curr->next!=NULL) && curr->data==curr->next->data){
            Node* nextnext=curr->next->next;
            Node* NodeTo=curr->next;
            delete (NodeTo);
            curr->next=nextnext;
        }
        else{
            curr=curr->next;
        }
    }
    return head;
}

Node *removeDuplicates(Node *head)
{
    // Write your code here
     Node*temp=head;
    while(temp!=NULL){
        Node*temp2=temp;
        while(temp2!=NULL){
            if(temp2->next!=NULL && temp->data==temp2->next->data){
                Node*t=temp2->next->next;
                temp2->next->next=NULL;
                delete (temp2->next);
                temp2->next=t;
            }
            else
                temp2=temp2->next;
        }
        temp=temp->next;
    }
    return head;
}

void insertAtTail(Node* & tail,int data){
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(Node* &head,int pos,int data,Node* &tail){
    Node* temp=head;
    int cnt=1;
    if(pos==1){
        InsertAtHead(head,data);
        return;
    }
    while(cnt!= pos-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;
    }
    Node* NodeToInsert=new Node(data);
    NodeToInsert->next=temp->next;
    temp->next=NodeToInsert;
}

void DeleteAtPos(Node* &head,Node* &tail,int pos){
    int cnt=1;
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    } 
    Node* cur=head;
    Node* prev=NULL;
    while(cnt<pos){
        cnt++;
        prev=cur;
        cur=cur->next;
    }
    if(cur->next==NULL){
        tail=prev;
    }
    prev->next=cur->next;
    cur->next=NULL;
    delete cur;
}

bool detectLoop(Node* head)
    {
        // your code here
        if(head==NULL){
            return true;
        }
        map<Node* ,bool> visited;
        Node* temp=head;
        while(temp!=NULL){
            if(visited[temp]==true){
                return true;
            }
            visited[temp]=true;
            temp=temp->next;
        }
        return false;
}

Node* FloydDetectLoop(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            cout<<"Loop is present at "<<slow->data;
            return slow;
        }
    }
    return NULL;
}

Node* LoopStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* inter=FloydDetectLoop(head);
    Node* slow=head;
    while(slow!=inter){
        slow=slow->next;
        inter=inter->next;
    }
    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }
    Node* Start=LoopStartingNode(head);
    Node* temp=Start;
    while (temp->next!=Start)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}

void print(Node* & head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{
    Node* mi=new Node(1);
    Node* head=mi;
    Node* tail=mi;

    InsertAtHead(head,2);
    InsertAtHead(head,3);
    insertAtTail(tail,0);
    print(head);cout<<endl;
    insertAtPosition(head,2,12,tail);
    print(head);
    cout<<endl;
    // cout<<"Head->"<<head->data<<endl;
    // cout<<"Tail->"<<tail->data<<endl;
    DeleteAtPos(head,tail,5);
    print(head);
    cout<<"Head->"<<head->data<<endl;
    cout<<"Tail->"<<tail->data<<endl;
    return 0;
}