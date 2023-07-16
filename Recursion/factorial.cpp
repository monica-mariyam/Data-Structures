#include <iostream>

using namespace std;
int fact(int n)
{
    if(n==1)
      return 1;
    return n*fact(n-1);
}
int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    cout<<"Factorial of "<<n<<" is:"<<fact(n)<<endl;
}

Ouput:
Enter a number:5
Factorial of 5 is:120
FIBONACCI SERIES USING RECURSION
#include <iostream>
using namespace std;
int fibo(int n)
{
    if(n==1||n==0)
      return n;
    return (fibo(n-1)+fibo(n-2));
}
int main()
{
    int n;
    cout<<"Enter number of terms:";
    cin>>n;
    cout<<"Fibonacci series upto "<<n<<" are:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<fibo(i)<<endl;
    }
}
