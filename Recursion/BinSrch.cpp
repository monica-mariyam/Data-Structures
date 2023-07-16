#include<iostream>
using namespace std;
class BinSrch
{
    int a[10];
    public:
    BinSrch(int size)
    {
        cout<<"Enter "<<size<< " elements for an ordered list:";
        for(int i=0;i<size;i++)
        {
           cin>>a[i]; 
        }
        
    }
    
    int recBinSrch(int low,int high,int target)
    {
        int mid;
        if(low<=high)
        {
            mid=(low+high)/2;
            if(target==a[mid])
            {
                return mid;
            }
            else if(target>a[mid])
            {
                return recBinSrch(mid+1,high,target);
            }
            else
            {
                return recBinSrch(low,mid-1,target);
            }
        }
        else
            return -1;
    }
};
int main()
{
    int size;
    cout<<"Enter the size of array:";
    cin>>size;
    BinSrch ob(size);
    int target,low=0,high=size-1;
    cout<<"Enter the search element:";
    cin>>target;
    int found=ob.recBinSrch(low,high,target);
    if(found!=-1)
        cout<<"Element "<<target<<" found at position "<<found<<endl;
    else
        cout<<"Element "<<target<<" not found\n";
}
