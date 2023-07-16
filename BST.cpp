#include <iostream>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
class BSTOperations
{
    node *root;
    public:
    BSTOperations()
    {
        root=NULL;
    }
    node * addBST(node *r,int x)
    {
        if(r==NULL)
        {
            node *temp=new node;
            temp->data=x;
            temp->left=temp->right=NULL;
            return temp;
        }
        else
        {
            if(x<r->data)
            {
                r->left=addBST(r->left,x);
            }
            else
            r->right=addBST(r->right,x);
            return r;
        }
    }
    node* deleteBST(node* r,int x)
    {
        if(r==NULL)
            return NULL;
        else
        {
            if(x<r->data)
            r->left=deleteBST(r->left,x);
            else if(x>r->data)
            r->right=deleteBST(r->right,x);
            else
            {
                if(r->left==NULL)
                return r->right;
                else if(r->right==NULL)
                return r->left;
                else
                {
                    node* delnode=r;
                    node* largest=largestBST(r->left);
                    r->data=largest->data;
                    r->left=deleteBST(r->left,largest->data);
                    return r;
                }
            }
        }
        return r;
    }
    int searchBST(node* r,int target)
    {
        if(r==NULL) return 0;
        else
        {
            if(target<r->data)
            return searchBST(r->left,target);
            else if(target>r->data)
            return searchBST(r->right,target);
            else return 1;
        }
    }
    node* largestBST(node* r)
    {
        if(r->right==NULL) return r;
        else return largestBST(r->right);
    }
    node* smallestBST(node* r)
    {
        if(r->left==NULL) return r;
        else return smallestBST(r->left);
    }
    void preOrder(node* r)
    {
        if(r!=NULL)
        {
            cout<<r->data<<" ";
            preOrder(r->left);
            preOrder(r->right);
        }
    }
    void inOrder(node* r)
    {
        if(r!=NULL)
        {
            inOrder(r->left);
            cout<<r->data<<" ";
            inOrder(r->right);
        }
    }
    void postOrder(node* r)
    {
        if(r!=NULL)
        {
            postOrder(r->left);
            postOrder(r->right);
            cout<<r->data<<" ";
        }
    }
    void menu()
    {
        int choice,x;
        do
        {
            cout<<"\n1.Insert,2.Delete,3.Search,4.Largest node,5.Smallest node,6.Preorder,7.Inorder,8.PostOrder,9.Exit\n";
            cout<<"Enter your choice:";
            cin>>choice;
            switch(choice)
            {
                case 1:
                cout<<"Enter data to be inserted :";
                cin>>x;root=addBST(root,x);break;
                
                case 2:
                cout<<"Enter data to be deleted :";
                cin>>x;
                if(deleteBST(root,x))
                cout<<x<<" is deleted\n";
                else cout<<"Delete failed\n";
                break;
                
                case 3:
                cout<<"Enter data to be searched :";cin>>x;
                if(searchBST(root,x))
                cout<<x<<" is found in the tree\n";
                else cout<<x<<" is not found in the tree\n";break;
                
                case 4:
                cout<<"Largest data in the tree is "<<largestBST(root)->data<<endl;
                break;
                
                case 5:
                cout<<"Smallest data in the tree is "<<smallestBST(root)->data<<endl;
                break;
                
                case 6:
                preOrder(root);cout<<endl;break;
                
                case 7:
                inOrder(root);cout<<endl;break;
                
                case 8:
                postOrder(root);cout<<endl;break;
            }
        }while(choice!=9);
        cout<<"Exiting...";
    }
};
int main()
{
    BSTOperations b;
    b.menu();
}

