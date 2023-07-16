#include <iostream>

using namespace std;
class queuearray
{
    private:
    int queue[10];
    int n;
    int front,rear;
    public:
    queuearray()
    {
        cout<<"Enter no of elements:";
        cin>>n;
        front=rear=-1;
    }
    ~queuearray(){}
    void enqueue();
    void dequeue();
    void display();
    void isempty();
    void isfull();
    void Front();
    void Rear();
    void count();
};
void queuearray ::enqueue()
{
    if(rear<n-1)
    {
        int x;
        cout<<"Enter the element to be inserted:";
        cin>>x;
        if(front==-1)
           front++;
        queue[++rear]=x;
    }
    else
    cout<<"Queue Overflow\n";
}
void queuearray ::dequeue()
{
    if(front>-1)
    {
        int y=queue[front];
        cout<<y<<" is deleted\n";
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }
    else
    {
        cout<<"Queue underflow\n";
    }
}
void queuearray ::display()
{
    if(front>-1)
    {
        cout<<"Elements in the queue are:\n";
        for(int i=front;i<=rear;i++)
        {
            cout<<queue[i]<<'\t';
        }
        cout<<endl;
    }
    else
    {
        cout<<"Queue empty\n";
    }
}
void queuearray ::isempty()
{
    if(front>-1)
    {
        cout<<"Queue is not empty\n";
    }
    else
       cout<<"Queue is empty\n";
}
void queuearray :: isfull()
{
    if(rear==n-1)
       cout<<"Queue is full\n";
    else
       cout<<"Queue is not full\n";
}
void queuearray ::Front()
{
    if(front>-1)
      cout<<"Element in the front is:"<<queue[front]<<endl;
    else
      cout<<"Queue is empty\n";
}
void queuearray ::Rear()
{
    if(front>-1)
       cout<<"Element in the rear end is:"<<queue[rear]<<endl;
    else
      cout<<"Queue is empty\n";
}
void queuearray ::count()
{
    if(front>-1)
    {
        int c=0;
        for(int i=front;i<=rear;i++)
        {
            c++;
        }
        cout<<"No. of elements are:"<<c<<endl;
    }
    else
      cout<<"Queue is empty\n";
}
int main()
{
    queuearray q;
    int ch;
    do
    {
        cout<<"\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.ISEMPTY\n5.ISFULL\n6.FRONT\n7.REAR\n8.COUNT\n9.EXIT\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            q.enqueue();break;
            case 2:
            q.dequeue();break;
            case 3:
            q.display();break;
            case 4:
            q.isempty();break;
            case 5:
            q.isfull();break;
            case 6:
            q.Front();break;
            case 7:
            q.Rear();break;
            case 8:
            q.count();break;
        }
    }
    while(ch!=9);
    cout<<”Exiting…”;
}
            
