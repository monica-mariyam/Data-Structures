#include <iostream>
#define size 4
using namespace std;
class queuearray
{
    int rear,front,queue[10];
    public:
    queuearray()
    {
        front=rear=-1;
    }
    void enqueue(int x)
    {
        if(rear<size-1)
        {
            queue[++rear]=x;
            if(front==-1)front++;
        }
        else cout<<"Overflow\n";
    }
    int dequeue()
    {
        if(front!=-1)
        {
            int y=queue[front];
            if(front==rear) front=rear=-1;
            front++;
            return y;
        }
        else 
        {
            cout<<"Underflow\n";return 0;
        }
    }
    int isEmpty()
    {
        if(rear==-1) return 1;
        else return 0;
    }
};
class Graph
{
    int Adj[size][size];
    int processed[size];
    int inQueue[size];
    queuearray q;
    public:
    Graph()
    {
        for(int i=0;i<size;i++)
        {
            processed[i]=0;
            inQueue[i]=0;
        }
        cout<<"Enter the adjacency matrix elements :\n";
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++)
                cin>>Adj[i][j];
    }
    void BFT()
    {
        int vertex;
        cout<<"Breadth-first traversal of the graph :\n";
        for(int i=0;i<size;i++)
        {
            if(processed[i]==0)
            {
                if(inQueue[i]==0)
                {
                    q.enqueue(i);
                    inQueue[i]=1;
                }
                while(!q.isEmpty())
                {
                    vertex=q.dequeue();
                    if(vertex==-1)
                    {
                        cout<<"ERROR\n";return;
                    }
                    cout<<vertex<<"\t";
                    processed[vertex]=1;
                    for(int j=0;j<size;j++)
                    {
                        if(Adj[i][j]==1)
                        {
                            if(processed[j]==0&&inQueue[j]==0)
                            {
                                q.enqueue(j);
                                inQueue[j]=1;
                            }
                            
                        }
                    }
                }
            }
        }
    }
};
int main()
{
    Graph g;
    g.BFT();
    return 0;
}
