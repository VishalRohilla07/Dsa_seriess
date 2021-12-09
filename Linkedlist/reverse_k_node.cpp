#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  node(int val){
    data = val;
    next = NULL;
  }
};

void insertAtTail(node* &head, int val){
  node* n = new node(val);
  if(head == NULL){
    head = n;
    return;
  }
  node * temp = head;
  while(temp -> next != NULL){
    temp = temp->next;
  }
  temp ->next = n;
}
void display(node * head){
  node* temp = head;
  while(temp != NULL){
    cout<< temp -> data << "->";
    temp = temp->next;
  }
  cout<< "NULL" <<endl;
}

void insertAthead( node* &head, int val){
  node *n = new node(val);
  n-> next = head;
  head = n;
}

bool search(node * head , int key){
  node*temp = head;
  while( temp != NULL){
    if(temp -> data ==key){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void deleteAtHead(node* &head){
  node* todelete = head;
  head = head-> next;
  delete todelete;
}

void deletion(node* &head, int val){
  if(head ==NULL)
  return;
  if(head->next==NULL){
    deleteAtHead(head);
    return;
  }
  node* temp = head;
  while (temp->next->data != val){
    temp = temp->next;
  }

  node* todelete = temp->next;
  temp-> next = temp->next->next;
  delete todelete;
}


node * reverse(node * &head){
  
  node* prevptr = NULL;
  node* currptr = head;
  node* nextptr;

  while(currptr !=NULL){
    nextptr= currptr->next;
    currptr->next=prevptr;

    prevptr=currptr;
    currptr=nextptr;

  }
  return prevptr;
}

node* reverseRecursive(node* &head){
  if(head ==NULL || head-> next ==NULL){
    return head;
  }

  node * newhead = reverseRecursive(head ->next);
  head->next->next = head;
  head->next = NULL;
  return newhead;
}


node * reversek(node * &head, int k){
  node* prevptr = NULL;
  node* currptr = head;
  node * nextptr;
  int count = 0;
  while(currptr != NULL && count <k){
    nextptr = currptr -> next;
    currptr ->next = prevptr;
    prevptr = currptr;
    currptr = nextptr;
    count++;
  }
  if(nextptr != NULL){
    head -> next = reversek(nextptr,k);
  }
  return prevptr;
}


bool detechCycle(node* &head){
  node* slow = head;
  node* fast = head;
  while( fast != NULL && fast -> next !=NULL){
    slow = slow-> next;
    fast = fast -> next ->next;
    if(fast == slow){
      return true;
    }
  }
  return false;
}

int main(){
  node* head =NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);

  display(head);
  int k =2;
  node* newhead= reversek(head,k);
  display(newhead);


  return 0;
}