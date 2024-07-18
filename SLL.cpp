#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node (int val)
    {
        data=val;
        next=NULL;
    }
};
void create(node* &head)
{
    node* temp;
    bool flag;
    char ans;
    temp=NULL;
    flag=true;
    int val;
    do 
    {
        cout<<"\nEnter data to insert: ";
        cin>>val;
        node* new_node=new node(val);
        if(new_node==NULL)
        {
            cout<<"\nMemory is not allocated";
        }
        else{
            new_node->data=val;
        }
        if(flag==true)
        {
            head=new_node;
            temp=head;
            flag=false;
        }
        else{
            temp->next=new_node;
            temp=new_node;
        }
        cout<<"\nDo you want to continue: ";
        cin>>ans;
    }
    while(ans=='y');
    {
        cout<<"\nSLL created\n";
    }
}
void insertAtHead(node* &head,int val)
{
    node* new_node=new node(val);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
}
void insertAtSpecific(node* head,int val)
{
    int key;
    node* new_node=new node(val);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    else{
        cout<<"\nEnter key after which you want to insert: ";
        cin>>key;
        node* temp=head;
        do{
            if(temp->data==key)
            {
                new_node->next=temp->next;
                temp->next=new_node;
                return;
            }
            else{
                temp=temp->next;
            }
            
        }while(temp!=NULL);
    }
}
void insertAtTail(node* &head,int val)
{
    node* new_node=new node(val);
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
}
bool search(node* head,int key)
{
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            return true;

        }
        temp=temp->next;
    }
    return false;
}
void deleteAtHead(node* &head)
{
    node* toDelete=head;
    head=head->next;
    delete toDelete;
}
void deletion(node* &head,int val)
{
    if(head==NULL)
    {
        cout<<"\nList empty";
    }
    if(head->next==NULL)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val)//it points to n-1 node(i.e next of head node)
    {
        temp=temp->next;
    }
    node* toDelete=temp->next;
    temp->next=temp->next->next;
    delete toDelete;
}
void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int main()
{
    node* head=NULL;
    create(head);
    display(head);

    insertAtTail(head,1);
    insertAtTail(head,2);
    display(head);

    insertAtHead(head,11);
    display(head);

    cout<<search(head,5)<<"\n";

    deletion(head,2);
    display(head);

    deleteAtHead(head);
    display(head);

    insertAtSpecific(head,10);
    display(head);
   
    return 0;
}
