#include<iostream>
#include<cstdlib>
using namespace std;
class library
{
    public:
    string title[10],author[10];
    int ISBN[10];
    int next[10];
    int i;
    library()
    {
        for(int j=0;j<10;j++)
        {
            title[j]=-1;
            author[j]=-1;
            ISBN[j]=-1;
            next[j]=0;
        }
        i = -1; 
    }
    int AddBook()
    {
        int head;
        cout<<"\nEnter index of 1st node: ";
        cin>>head; 
        int j=head;
        while(j!=-1)
        {
            cout<<"\nEnter title : ";
            cin>>title[j];
            cout<<"\nEnter author : ";
            cin>>author[j];
            cout<<"\nEnter ISBN : ";
            cin>>ISBN[j];
            cout<<"\nEnter index no. of next node: ";
            cin>>next[j];
            j=next[j];
        }
        i = head;
        return head;
    }
    void display()
    {
        int current = i; // set current to head
        while(current != -1) // traverse until end
        {
            if(title[current] == "") 
            {
                cout << "NO TITLE" << endl;
            }
            else
            {
                cout << "Title: " << title[current] << endl;
                cout << "Author: " << author[current] << endl;
                cout << "ISBN: " << ISBN[current] << endl;
            }
            current = next[current]; 
        }
    }
    void search()
    {
        string temp;
        cout<<"\nEnter the title of book to be searched: ";
      cin>>temp; 

        bool found = false;
        for(int j = 0; j < 10; j++)
        {
            if(title[j] == temp) 
            {
                if(title[j] != "") 
                {
                    cout << "Title: " << title[j] << endl;
                    cout << "Author: " << author[j] << endl;
                    cout << "ISBN: " << ISBN[j] << endl;
                    found = true;
                }
            }
        }

        if(!found)
        {
            cout << "Book not found." << endl;
        }
    }

 
   void del()
{
    string d;
    cout << "\nEnter the title of book to be deleted: ";
    cin >> d;
    bool found = false;
    for (int j = 0; j < 10; j++)
    {
        if (title[j] == d)
        {
            cout << "Title: " << title[j] << endl;
            cout << "Author: " << author[j] << endl;
            cout << "ISBN: " << ISBN[j] << endl;
            
            // Mark the book as deleted by clearing its data
            title[j] = "";
            author[j] = "";
            ISBN[j] = -1;
            found = true;
            break; // Exit loop after deleting the book
        }
    }

    if (!found)
    {
        cout << "Book not found." << endl;
    }
}
void update()
    {
        string nauthor[10],ntitle[10];
        int nISBN[10];
        string temp;
        cout<<"\nEnter title to be update: ";
        cin>>temp;
        bool found=false;
        for(int j=0;j<10;j++)
        {
            if(title[j]==temp)
            {
                cout<<"\nEnter new Tilte: ";
                cin>>ntitle[j];
                cout<<"\nEnter new author: ";
                cin>>nauthor[j];
                cout<<"\nEnter new ISBN: ";
                cin>>nISBN[j];
                found = true; 
                
                title[j]=ntitle[j];
                author[j]=nauthor[j];
                ISBN[j]=nISBN[j];
                cout<<"\nUpdated successfully";
                break;
            }
        }
        if(!found)
        {
            cout<<"\nNot found";
        }
    }

};
int main()
{
    library l;
    int ch;
    char press;
     do{
     cout<<"Enter your choice: ";
     cout<<"\n1.ADD BOOK";
     cout<<"\n2.display";
     cout<<"\n3.Search";
     cout<<"\n4.delete";
      cout<<"\n5.update";
    cin>>ch;
     switch(ch)
     {
     	case 1:
     	l.AddBook();
     	break;
     	case 2:
     	l.display();
     	break;
     	case 3:
     	l.search();
     	break;
     	case 4:
     	l.del();
     	break;
        case 5:
     	l.update();
     	break;
     	
     }
     cout<<"\nDo you want to continue: ";
     cin>>press;
   }while(press=='y'||press=='Y');
}
