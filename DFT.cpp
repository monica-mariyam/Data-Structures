#include <iostream>
#define size 5
using namespace std;
class stackarray
{
    int top,stack[10];
    public:
    stackarray()
    {
        top=-1;
    }
    void push(int x)
    {
        if(top<size-1)
        {
            stack[++top]=x;
        }
        else cout<<"Overflow\n";
    }
    int pop()
    {
        if(top!=-1)
        {
            int y=stack[top--];
            return y;
        }
        else 
        {
            cout<<"Underflow\n";return 0;
        }
    }
    int isEmpty()
    {
        if(top==-1) return 1;
        else return 0;
    }
};
class Graph
{
    int Adj[size][size];
    int processed[size];
    int inStack[size];
    stackarray s;
    public:
    Graph()
    {
        for(int i=0;i<size;i++)
        {
            processed[i]=0;
            inStack[i]=0;
        }
        cout<<"Enter the adjacency matrix elements :\n";
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                cin>>Adj[i][j];
    }
    void DFT()
    {
        int vertex;
        cout<<"Depth-first traversal of the graph :\n";
        for(int i=0;i<size;i++)
        {
            if(processed[i]==0)
            {
                if(inStack[i]==0)
                {
                    s.push(i);
                    inStack[i]=1;
                }
                while(!s.isEmpty())
                {
                    vertex=s.pop();
                    if(vertex==-1)
                    {
                        cout<<"ERROR\n";return;
                    }
                    cout<<vertex<<"\t";
                    processed[vertex]=1;
                    for(int j=0;j<size;j++)
                    {
                        if(Adj[vertex][j]==1)
                        {
                        if(processed[j]==0&&inStack[j]==0)
                        {
                            s.push(j);
                            inStack[j]=1;
                        }}
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.DFT();
    return 0;
}
