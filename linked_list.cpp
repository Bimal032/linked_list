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

void insertAtParticular(Node* prevNode,int val){
    if(prevNode==NULL){
        return;
    }
    Node*n=new Node(val);
    n->next=prevNode->next;
    prevNode->next=n;
}

void deleteNode(Node* &head,int val){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    Node*nodeDel=temp->next;
    temp->next=temp->next->next;
    free(nodeDel);
}

bool searchVal(Node* &head, int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
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
Node* lastToFirst(Node*&head){
    Node*temp1=head;
    Node*temp2=temp1->next;
    while(temp2->next!=NULL){
        temp2=temp2->next;
        temp1=temp1->next;
    }
    temp1->next=NULL;
    temp2->next=head;
    head=temp2;
    return head;
}
void printMiddleElement(Node*head){
    Node*mid=head;
    int count=0; 
    while(head!=NULL){
        if(count & 1){
            mid=mid->next;
        }
        count++;
        head=head->next;
    }
    if(mid!=NULL){
        cout<<"The middle Element is : "<<mid->data<<endl;
    }
}

void checkCircular(Node*head){
    Node*temp=head;
    while(temp->next!=NULL && temp->next!=head){
        temp=temp->next;
    }
    cout<<"ready"<<endl;
    if(temp->next==head){
        cout<<"This is cirular linked list"<<endl;
    }
    else{
        cout<<"This is singly linked list"<<endl;
    }
}

int main(){     
    Node*head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    printList(head);
    cout<<searchVal(head,5);
    cout<<endl;
    insertAtParticular(head->next->next,6);
    printList(head);
    // deleteNode(head,6);
    printList(head);
    // head=reversell(head);
    // printList(head);
    lastToFirst(head);
    printList(head);
    printMiddleElement(head);
    checkCircular(head);
    head->next->next->next->next->next=head;
    checkCircular(head);

    return 0;
}