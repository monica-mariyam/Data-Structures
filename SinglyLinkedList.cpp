#include<iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
struct header
{
    int count;
    node *head;
    node *pos;
};
class sll
{
    private:
    node *pNew,*pred,*pLoc,*temp;
    header *pList;
    public:
    sll()
    {
        pList=new header;
        pList->count=0;
        pList->head=NULL;
        pList->pos=NULL;
    }
    
    void insertNode(int);
    void deleteNode(int);
    void display();
    int search(int);
    void traverse(int,int);
    int count();
    int isEmpty();
    void isFull();
    ~sll();
};
void sll ::insertNode(int x)
{
    int found=search(x);
    if(found)
    {
        cout<<"Duplicate entry. You can't insert data\n";
    }
    pNew=new node;
    if(pNew ==NULL)
    {
        cout<<"Memory full\n";
    }
    pNew->data=x;
    if(pred==NULL)
    {
        pNew->link=pList->head;
        pList->head=pNew;
    }
    else
    {
        pNew->link=pred->link;
        pred->link=pNew;
    }
    pList->count++;
}

void sll::deleteNode(int x)
{
    if(pList->count==0)
    {
        cout<<"Underflow. No node is there to be deleted\n";
        return;
    }
    int found=search(x);
    if(!found)
    {
        cout<<"Data not found. You can't delete\n";
        return;
    }
    if(pred==NULL)
    {
        pList->head=pLoc->link;
    }
    else
    {
        pred->link=pLoc->link;
    }
    cout<<pLoc->data<<" is deleted\n";
    delete pLoc;
    pList->count--;
}

void sll:: display()
{
    temp=pList->head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->link;
         
    }
    cout<<endl;
}

int sll :: search(int target)
{
    pred=NULL;
    pLoc=pList->head;
    while(pLoc!=NULL && pLoc->data<target)
    {
        pred=pLoc;
        pLoc=pLoc->link;
    }
    if(pLoc==NULL)
    {
        return 0;
    }
    else
    {
        if(pLoc->data==target)
           return 1;
        else
           return 0;
    }
}

void sll::traverse(int from,int dataout)
{
    if(pList->count==0)
    {
        cout<<"Empty list\n";
        return;
    }
    if(from==0)
    {
        pList->pos=pList->head;
        //pLoc=pList->pos;
        dataout=pList->pos->data;
        pList->pos=pList->pos->link;
        cout<<"Traversed element :"<<dataout<<endl;
    }
    else
    {
        if(pList->pos==NULL)
        {
            cout<<"Reached end of list\n";
            return;
        }
        else
        {
            dataout=pList->pos->data;
            pList->pos=pList->pos->link;
            cout<<"Traversed element :"<<dataout<<endl;
        }
    }
}

int sll::count()
{
    return pList->count;
}

int sll:: isEmpty()
{
    if(pList->count==0)
       return true;
    else
       return false;
}

void sll::isFull()
{
    temp=new node;
    if(temp==NULL)
       cout<<"Memory is full\n";
    else
       cout<<"Memory is not full\n";
}

sll::~sll()
{
    temp=pList->head;
    while(temp!=NULL)
    {
        pList->head=temp->link;
        cout<<"Removing the node containing "<<temp->data<<endl;
        delete temp;
        pList->count--;
        temp=pList->head;
    }
   delete pList;
}

int main()
{
    sll s;
    int ch,x,found,from,dataout;
    do
    {
        cout<<"\n1.Insert\n2.Delete\n3.Display\n4.Search\n5.Traverse\n6.Count\n7.isEmpty\n8.isFull\n9.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter the element to be inserted:";
            cin>>x;
            s.insertNode(x);
            break;
            
            case 2:
            cout<<"Enter the element to be deleted:";
            cin>>x;
            s.deleteNode(x);
            break;
            
            case 3:
            s.display();
            break;
            
            case 4:
            cout<<"Enter the target element:";
            cin>>x;
            found=s.search(x);
            if(found)
               cout<<"Element "<<x<<" is found\n";
            else
               cout<<"Element "<<x<<" is not found\n";
            break;
            
            case 5:
            cout<<"Enter from where element has to be traversed:";
            cin>>from;
            s.traverse(from,dataout);
            break;
            
            case 6:
            found=s.count();
            cout<<"No. of elements in the linked list are:"<<found<<endl;
            break;
            
            case 7:
            found=s.isEmpty();
            if(found==1)
               cout<<"Linked list is empty\n";
            else
               cout<<"It is not empty\n";
            break;
            
            case 8:
            s.isFull();
            break;
        }
    }
    while(ch!=9);    
    
}
