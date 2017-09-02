#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n;
    x=sqrt(n);
    if(x*x==n)
        cout<<x<<" "<<x<<endl;
    else
    {
        while(x)
        {
            y=n/x;
            if(x*y==n)
            {
                cout<<x<<" "<<y<<endl;
                break;
            }
            x--;
        }
    }
    return 0;
}
