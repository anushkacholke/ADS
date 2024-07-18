#include<iostream>
#define MAX 10
using namespace std;
class Hash
{
    public:
    Hash* ht[MAX];
    Hash* next;
    int music_no,duration;
    string album,title;
    Hash()
    {
        for(int i=0;i<MAX;i++)
        {
            ht[i]=NULL;
        }
    }
    void insert();
    void search();
    void display();
    void update();
    void Delete();
};
void Hash::insert()
{
    int addr;
    Hash* ptr;
    Hash* temp;
    temp=new Hash();
    cout<<"\nEnter music_no: ";
    cin>>temp->music_no;
    cout<<"\nEnter title: ";
    cin>>temp->title;
    cout<<"\nEnter duration: ";
    cin>>temp->duration;
    cout<<"\nEnter album: ";
    cin>>temp->album;
    addr=temp->music_no%MAX;
    temp->next=NULL;
    if(ht[addr]==NULL)
    {
        ht[addr]=temp;
    }
    else{
        ptr=ht[addr];
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void Hash::display()
{
    cout << "\n####HASH TABLE####";
    cout << "\nIndex\tMusic_no\tTitle\tAlbum\tDuration\n";
    for(int i = 0; i < MAX; i++)
    {
        Hash* ptr = ht[i];
        cout << "\n" << i << "\t";
        while(ptr != NULL)
        {
            cout <<ptr->music_no << "\t" << ptr->title << "\t" << ptr->album << "\t" << ptr->duration;
            ptr = ptr->next;
        }
    }
}
void Hash:: search()
{
    int key,addr;
    Hash* ptr;
    cout<<"\nEnter music_no to be search: ";
    cin>>key;
    addr=key%MAX;
    ptr=ht[addr];
    while(ptr!=NULL && key!=ptr->music_no)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL && key==ptr->music_no)
    {
        cout<<"\nfound";
    }
    else{
        cout<<"\nNot found";
    }
}
void Hash::update()
{
    int key,addr;
    Hash* ptr;
    cout<<"\nEnter key to be update: ";
    cin>>key;
    addr=key%MAX;
    ptr=ht[addr];
    while(ptr!=NULL && key!=ptr->music_no)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL && key==ptr->music_no)
    {
        cout<<"\nEnter new title: ";
        cin>>ptr->title;
        cout<<"\nEnter new album: ";
        cin>>ptr->album;
        cout<<"\nEnter new duration: ";
        cin>>ptr->duration;
        cout<<"\nUpdated successfully";
    }
    else{
        cout<<"\nEntered music_no not found.";
    }
}
void Hash::Delete()
{
    int key, addr;
    Hash *ptr, *prev;
    cout << "\nEnter key to be deleted: ";
    cin >> key;
    addr = key % MAX;
    ptr = ht[addr];
    prev = NULL;
    while (ptr != NULL && key != ptr->music_no)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr != NULL && key == ptr->music_no)
    {
        // If the record to be deleted is the first node in the chain
        if (prev == NULL)
        {
            ht[addr] = ptr->next;
        }
        else
        {
            prev->next = ptr->next;
        }

        delete ptr;
        cout << "\nRecord deleted successfully.";
    }
    else
    {
        cout << "\nRecord not found.";
    }
}

int main()
{
    Hash h;
    int ch;
    char press;
    do{
        cout<<"\nEnter ur ch: ";
        cout<<"\n1.Insert\n2.Display\n3.Search\n4.update\n5.Delete";
        cin>>ch;
        switch(ch)
        {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.search();
                break;
            case 4:
                h.update();
                break;
            case 5:
                h.Delete();
                break;
        }
        cout<<"\nDo you want to continue: ";
        cin>>press;
    }while(press=='Y'||press=='y');
}