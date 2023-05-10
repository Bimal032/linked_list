#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtTail(Node* &head, int val){
    Node*n=new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void printList(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
Node*reversell(Node*&head){
    Node*prevptr=NULL;
    Node*currptr=head;
    Node*nextptr;

    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;

        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

// before calling the function reverse the linked list and after calling function again reverse the linked list
Node * oneplus(Node*head){
    Node* res=head;
    Node* temp,*prev=NULL;
    int sum;
    int carry=1;
    while(head!=NULL){
        sum=carry+head->data;
        carry=(sum>=10)?1:0;
        sum=sum%10;
        head->data=sum;
        temp=head;
        head=head->next;
    }
    if(carry>0){
        temp->next=new Node(carry);
    return res;
    }
}

int main(){     
    Node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,9);
    insertAtTail(head,9);
    insertAtTail(head,9);
    printList(head);
    head=reversell(head);
    printList(head);
    oneplus(head);
    printList(head);
    head=reversell(head);
    printList(head);
    return 0;
}