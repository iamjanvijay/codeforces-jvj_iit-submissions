#include <bits/stdc++.h>
using namespace std;

#define sd(x)         scanf("%d",&x)
#define su(x)         scanf("%u",&x)
#define slld(x)     scanf("%lld",&x)
#define sc(x)         scanf("%c",&x)
#define ss(x)         scanf("%s",x)
#define sf(x)         scanf("%f",&x)
#define slf(x)        scanf("%lf",&x)
#define ll             long long int
#define mod(x,n)     (x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

int A[2000007];

int main()
{
    // freopen("input_file_name.in","r",stdin);
    // freopen("output_file_name.out","w",stdout);

    int i,j,k,l,m,n,x,y,z,a,b,c,r;
    // ll i,j,k,l,m,n,x,y,z,a,b,r;

    sd(n);
    for(i=0;i<n;i++)
        A[i] = i+1;

    for(a=0,i=2;i<=n;i++,a++)
    {
        c=a;    b=A[c];     c+=i;
        while(c<a+n)
        {
            x=A[c];
            A[c]=b;
            b=x;
            c+=i;
        }
        A[a+n]=b;
    }

    for(i=a;i<a+n;i++)
        printf("%d ", A[i] );
    printf("\n");
    
    return 0;
}