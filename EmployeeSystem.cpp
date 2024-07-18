#include<iostream>
#include<cstdlib>
using namespace std;

class employee {
public:
    int empid;
    string ename, designation;
    float esal;
    employee* left;
    employee* right;

    employee(int eid, string empname, string desig, float sal) {
        empid = eid;
        ename = empname;
        designation = desig;
        esal = sal;
        left = NULL;
        right = NULL;
    }
};

void addEmp(employee* &root, int eid, string empname, string desig, float sal) {
    if (root == NULL) {
        root = new employee(eid, empname, desig, sal);
    } else {
        if (sal < root->esal) {
            addEmp(root->left, eid, empname, desig, sal);
        } else {
            addEmp(root->right, eid, empname, desig, sal);
        }
    }
}

void createEmp(employee* &root) {
    int num_emp, eid;
    string empname, desig;
    float sal;
    
   // root = new employee(eid, empname, desig, sal);
    cout << "\nEnter number of Employee to add: ";
    cin >> num_emp;
    for (int i = 1; i <= num_emp; i++) {
        cout << "\nEnter Employee ID: ";
    cin >> eid;
    cout << "\nEnter Employee name: ";
    cin >> empname;
    cout << "\nEnter Employee designation: ";
    cin >> desig;
    cout << "\nEnter Employee salary: ";
    cin >> sal;
        //cin >> eid >> empname >> desig >> sal;
        addEmp(root, eid, empname, desig, sal);
    }
}
employee* min(employee* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
employee* Delete(employee* root,int key)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(key<root->empid)
    {
        root->left=Delete(root->left,key);
    }
    else if(key>root->empid)
    {
        root->right=Delete(root->right,key);
    }
    else{
        if(root->left==NULL)
        {
            employee* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            employee* temp=root->left;
            delete root;
            return temp;
        }
        else{
            employee* temp=min(root->right);
            root->empid=temp->empid;
            root->ename=temp->ename;
            root->designation=temp->designation;
            root->esal=temp->esal;
            root->right=Delete(root->right,root->empid);
        }
        return root;
    }
}

employee* search(employee* root,string key)
{
    if(root==NULL || root->ename==key)
    {
        return root;
    }
    employee* found=search(root->right,key);
    if(found==NULL)
    {
        found=search(root->left,key);
    }
    return found;
}
void update(employee* &root,int key)
{
    if(root==NULL)
    {
        return;
    }
    if(root->empid==key)
    {
        cout<<"\nEnter new emp id: ";
        cin>>root->empid;
        cout<<"\nEnter new ename: ";
        cin>>root->ename;
        cout<<"\nEnter new desti: ";
        cin>>root->designation;
        cout<<"\nenter new emp sal: ";
        cin>>root->esal;
        cout<<"\nUpdated successfully";
    }
    update(root->left,key);
    update(root->right,key);
}
void inorderTraversal_Emp(employee* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal_Emp(root->left);
    cout << "\nEmployee ID: " << root->empid << "\tEmployee Name: " << root->ename << "\tEmployee Designation: " << root->designation << "\tEmployee Salary: " << root->esal;
    inorderTraversal_Emp(root->right);
}

int main() 
{
    employee* root = NULL;
    int ch;
    employee* found;
    int e_key;
    string key;
    char press;
    do{
        cout<<"\nEnter ur choice: ";
        cout<<"\n1.Add emp\n2.Display\n3.search\n4.update\n5.Delete";
        cin>>ch;
        switch(ch)
        {
            case 1:
                createEmp(root);
                break;
            case 2:
                inorderTraversal_Emp(root);
                break;
            case 3:
                cout<<"\nEnter employee name which is to be search: ";
                cin>>key;
                found=search(root,key);
                if(found!=NULL)
                {
                    cout<<"\nemp found";
                }
                else{
                    cout<<"\nNot found";
                }
                break;
            case 4:
                cout<<"\nEnter emp id to be updated: ";
                cin>>e_key;
                update(root,e_key);
                break;
            case 5:
                int id;
                cout<<"\nEnter emp id  to be delete: ";
                cin>>id;
                Delete(root,id);
                cout<<"\ndeleted successfully";
                break;           
        }
        cout<<"\nDo you want you continue: ";
        cin>>press;
    }while(press=='y'||press=='Y');
}
