#include<iostream>
using namespace std;
class LinSrch
{
    int a[10];
    public:
    LinSrch(int size)
    {
        cout<<"Enter "<<size<< " elements :";
        for(int i=0;i<size;i++)
        {
           cin>>a[i]; 
        }
        
    }
    
    int recLinSrch(int target,int index,int last,int locn)
    {
        if(index>last)
        {
            return -1;
        }
        if(a[index]==target)
        {
            locn=index;
            return locn;
        }
        else
            return recLinSrch(target,index+1,last,locn);
    }
};
int main()
{
    int size,target,locn,index=0;
    cout<<"Enter the size of array:";
    cin>>size;
    LinSrch ob(size);
    cout<<"Enter the search element:";
    cin>>target;
    int found=ob.recLinSrch(target,index,size-1,locn);
    if(found!=-1)
        cout<<"Element "<<target<<" found at position "<<found<<endl;
    else
        cout<<"Element "<<target<<" not found\n";
}
