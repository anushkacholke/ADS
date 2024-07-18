#include<iostream>
#include<cstdlib>
using namespace std;
class node
{
    public:
    int data;
    node* prev;
    node* next;
    node(int val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void create(node* &head)
{
    node* temp;
    int val;
    bool flag;
    char ans;
    temp=NULL;
    flag=true;
    do{
        cout<<"\nEnter data to be inserted: ";
        cin>>val;
        node *new_node=new node(val);
        if(new_node==NULL)
        {
            cout<<"\nMemory is not allocated";
        }
        else
        {
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
            new_node->prev=temp;
            temp=new_node;
        }
        cout<<"\nDo you want to continue: ";
        cin>>ans;
    }
    while(ans=='y');
    {
        cout<<"\nDLL created\n";
    }
}
void insertAtHead(node* &head,int val)
{
    node* new_node=new node(val);
    new_node->next=head;
    if(head!=NULL)
    {
        head->prev=new_node;
    }
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
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}

void deleteAtHead(node* &head)
{
    node* toDelete=head;
    head=head->next;
    head->prev=NULL;
    delete toDelete;
}
void deletion(node* &head,int val/*int pos*/)
{
    if(head==NULL/*pos==1*/)
    {
        deleteAtHead(head);
        return;
    }
    node* temp=head;
   // int count=1;
    while(temp->next->data!=val/*temp!=NULL&&count!=pos*/)
    {
        temp=temp->next;
        //count++;
    }
    temp->next=temp->next->next;
    if(temp->next!=NULL)
    {
        temp->next->prev=temp;
    }
    //temp->prev->next=temp->next;
   /* if(temp->next!=NULL)
    {
        temp->next->prev=temp->prev;
    }*/
    //delete temp;
    delete temp->next;
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

    insertAtHead(head,99);
    display(head);

    deletion(head,2);
    display(head);

    deleteAtHead(head);
    display(head);

    cout<<search(head,1);

}