#include <iostream>
//#include<cstring>
using namespace std;
class stackarray
{
    char stack[10];
    int top;
    public :
    stackarray()
    {
        top=-1;
    }
    void push(char c)
    {
        stack[++top]=c;
    }
    char pop()
    {
        char y=stack[top--];
        return y;
    }
    int isempty()
    {
        if(top==-1) return 1;
        else return 0;
    }
    char stacktop()
    {
        if(!isempty()) return stack[top];
        else return '\0';
    }
};
int precedence(char c)
{
    if(c=='*'||c=='/')
        return 2;
    else if(c=='+'||c=='-')
        return 1;
    else
        return 0;
}

int main()
{
    char ch,del;
    string infix,postfix="";
    stackarray s;//creating stack
    cout<<"Enter the infix expression :";
    cin>>infix;int count=0;
    while(infix[count]!='\0')//loop(for each character in infix)
    {
        ch=infix[count];
        if(isalnum(ch))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            s.push(ch);  // push into stack if open parenthesis
        }
        else if(ch==')')
        {
            while(s.stacktop()!='(')
            {
                del=s.pop();
                postfix+=del;//concatenate char to postfix expr
            }
            s.pop();
        }
        else
        {
            while(!s.isempty()&&precedence(ch)<=precedence(s.stacktop()))
            {
                del=s.pop();
                postfix+=del;
            }
            s.push(ch);
        }
        count++;
    }
    while(!s.isempty()) // pop out remaining operator in stack
    {
        del=s.pop();
        postfix+=del;
    }
    cout<<"Converted  postfix expression :"<<postfix<<endl;
}
