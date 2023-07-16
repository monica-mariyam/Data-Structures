#include <iostream>
using namespace std;
#include<cstring>
int precedence(char x)
{
    if(x=='+'||x=='-') return 1;
    else if(x=='*'||x=='/') return 2;
    else return -1;
}
class stackarray
{
    char stack[20], infix[15];
    int size,top;
    public:
    stackarray()
    {
        cout<<"Enter infix expression:";
        cin>>infix;
        size=20;top=-1;
    }
    void push(char x)
    {
        if(top<size-1) stack[++top]=x;
        else cout<<"Stack empty\n";
    }
    char pop()
    {
        if(top>-1)return stack[top--];
        else return '\0';
    }
    int isempty()
    {
        if(top==-1) 
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    char stacktop()
    {
        if(top>-1) return stack[top];
        else return '\0';
    }
    void convert()
    {
        char ch;int i=0;
        while(i<strlen(infix))
        {
            ch=infix[i];
            if(ch=='(')
            {
                push(ch);
            }
            else if(ch==')')
            {
                while(stacktop()!='(')
                {
                    cout<<pop();
                }
                pop();
            }
            else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
            {
                while(precedence(ch)<=precedence(stacktop()))
                {
                    cout<<pop();
                }
                push(ch);
            }
            else if(isalnum(ch)) 
            {
                cout<<ch;
            }
            i++;
        }
        while(!isempty())
        {
            cout<<pop();
        }
    }
};

int main() 
{
    stackarray s;
    s.convert();
}
