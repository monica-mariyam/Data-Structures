#include <iostream>
using namespace std;
class stackarray
{
    private:
    int stack[10];
    int size,top;
    public:
    stackarray()
    {
        cout<<"Enter no of elements:";
        cin>>size;
        top=-1;
    }
    ~stackarray(){}
    void push(int);
    void pop();
    void stacktop();
    void display();
    void isempty();
    void isfull();
    void peek();
};
void stackarray ::push(int x)
{
    if(top<size-1)
        stack[++top]=x;
    else
        cout<<"Stack Overflow\n";
}
void stackarray ::pop()
{
    if(top>-1)
    {
        int y=stack[top--];
        cout<<y<<" is deleted\n";
    }
    else
        cout<<"Stack underflow\n";
}
void stackarray ::stacktop()
{
    if(top==-1)
        cout<<"Stack is empty\n";
    else
        cout<<"Stack top element :"<<stack[top]<<endl;
}
void stackarray ::display()
{
    if(top>-1)
    {
        cout<<"Elements in the stack are:\n";
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<'\t';
        }
        cout<<endl;
    }
    else
    {
        cout<<"Stack is empty\n";
    }
}
void stackarray ::isempty()
{
    if(top==-1)
        cout<<"Stack is empty\n";
    else
       cout<<"Stack is not empty\n";
}
void stackarray :: isfull()
{
    if(top==size-1)
       cout<<"Stack is full\n";
    else
       cout<<"Stack is not full\n";
}
void stackarray ::peek()
{
    if(top>-1)
    {
        int i;
        cout<<"Enter the position of element:";
        cin>>i;
        cout<<"\nElement in position "<<i<<" is :"<<stack[top-i+1]<<endl;
    }
    else
        cout<<"It is a empty stack\n";
}

int main()
{
    stackarray s;
    int ch;
    do
    {
        cout<<"\n1.PUSH\n2.POP\n3.STACKTOP\n4.ISEMPTY\n5.ISFULL\n6.PEEK\n7.DISPLAY\n8.EXIT\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:
            int x;
            cout<<"Enter the element to be inserted :";
            cin>>x;
            s.push(x);break;
            case 2:
            s.pop();break;
            case 3:
            s.stacktop();break;
            case 4:
            s.isempty();break;
            case 5:
            s.isfull();break;
            case 6:
            s.peek();break;
            case 7:
            s.display();break;
        }
    }
    while(ch!=8);
    cout<<"Exiting....";
}
