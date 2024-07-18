#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head,int val)
{
    node* new_node=new node(val);
    if(head==NULL)
    {
        new_node->next=new_node;
        head=new_node;
        return;
    }
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
    head=new_node;
}
void insertAtTail(node* &head,int val)
{
    if(head==NULL)
    {
        insertAtHead(head,val);
        return;
    }
    node* new_node=new node(val);
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=head;
}
void deleteAtHead(node* &head)
{
    node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    node* toDelete=head;
    temp->next=head->next;
    head=head->next;
    delete toDelete;
}
void deletion(node* &head,int pos)
{
    if(pos==1)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(count!=pos-1)
    {
        temp=temp->next;
        count++;
    }
    node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}
void display(node* head)
{
    node* temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    while(temp!=head);
    cout<<"NULL\n";
}
int main()
{
    node* head=NULL;

    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    display(head);

    insertAtHead(head,99);
    display(head);

    deletion(head,3);
    display(head);

    deleteAtHead(head);
    display(head);

}