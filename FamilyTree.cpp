/*Design and implement a family tree hierarchy using a tree data structure. The family tree should allow 
efficient storage, retrieval, and manipulation of information related to individuals and their relationships 
within a family*/
#include <iostream>
#include <string>
using namespace std;
class family
{
    public:
    family* left;
    family* right;
    string name;
    int age;
    family(string n,int a)
    {
        left=NULL;
        right=NULL;
        name=n;
        age=a;
    }
};
void insert(family* &root,string name,int age)
{
    if(root==NULL)
    {
        root=new family(name,age);
        return;
    }
    family* temp=root;
    while(temp!=NULL)
    {
        char direction;
        cout<<"\nEnter direction(L/R) to insert node with value "<<name<<" "<<age<<" at node "<<temp->name<<" "<<temp->age<<" : ";
        cin>>direction;
        if(direction=='L'||direction=='l')
        {
            if(temp->left==NULL)
            {
                temp->left=new family(name,age);
                break;
            }
            else{
                temp=temp->left;
            }
        }
        else if(direction=='r'||direction=='R')
        {
            if(temp->right==NULL)
            {
                temp->right=new family(name,age);
                break;
            }
            else{
                temp=temp->right;
            }
        }
        else{
            cout<<"\nInvalid direction.";
        }
    }
}
void create(family* &root)
{
    int age;
    string name;
    char choice;
    do{
        cout<<"\nEnter age to be insert: ";
        cin>>age;
        cout<<"\nEnter person name: ";
        cin>>name;
        insert(root,name,age);
        cout<<"\nDo you want to continue: ";
        cin>>choice;
    }while(choice=='y'||choice=='Y');
}
void Delete(family* &root, string n) {
    if (root == NULL) {
        return;
    }
    if (root->left && root->left->name == n) {
        delete root->left;
        root->left = NULL;
        return;
    }
    if (root->right && root->right->name == n) {
        delete root->right;
        root->right = NULL;
        return;
    }
    Delete(root->left, n);
    Delete(root->right, n);
}

void update(family* root, string n) {
    if (root == NULL) {
        return;
    }
    if (root->name == n) {
        cout << "\nEnter new name: ";
        cin >> root->name;
        cout << "\nEnter new age: ";
        cin >> root->age;
        cout << "\nUPDATED SUCCESSFULLY";
        return;
    }
    update(root->left, n);
    update(root->right, n);
}
family* search(family* root, string n) {
    if (root == NULL || root->name == n) 
    {
        return root;
    }
    family* found = search(root->left, n);
    if (found == NULL) {
        found = search(root->right, n);
    }
    return found;
}

void inorderTraversal(family* root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        inorderTraversal(root->left);
        cout<<"NAME: "<<root->name<< ", AGE: "<<root->age<<"\n";
        inorderTraversal(root->right);
    }
}
int main()
{
    family* root=NULL;
    int ch;
    char press;
    string name;
    family* found;
    do{
        cout<<"\nEnter ur choice: ";
        cout<<"\n1.Create Family\n2.Display family tree\n3.Updation in family tree\n4.Searching in family tree\n5.Deletion in family tree";
        cin>>ch;
        switch(ch)
        {
            case 1:
                create(root);
                break;

            case 2:
                cout<<"\nDisplying family tree : ";
                inorderTraversal(root);
                break;

            case 3:
                cout<<"\nEnter person name to be update: ";
                cin>>name;
                update(root,name);
                break;
            
            case 4:
                cout<<"\nSearching family tree: ";
                cout << "\nEnter the name of the family member you want to search: ";
                cin>>name;
                found=search(root,name);
                if (found != NULL) {
                    cout << "\nFamily member found: " << found->name<< ", AGE: " << found->age << "\n";
                } 
                else {
                        cout <<"\nFamily member not found.";
                    }
                break;

            case 5:
                cout<<"\nEnter name of person to remove: ";
                cin>>name;
                Delete(root,name);
                break;
        }
        cout<<"\nDo you want to continue: (y/n)";
        cin>>press;
    }while(press=='y'||press=='Y');
}
