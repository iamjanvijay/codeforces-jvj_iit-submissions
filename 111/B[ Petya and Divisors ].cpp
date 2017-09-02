#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n

int A[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y;

	for(i=0;i<100007;i++)
		A[i] = -1;

	sd(n);
	for(l=0;l<n;l++)
	{
		sd(x);	sd(y);
		k = 0;

		for(i=1;i*i<=x;i++)
		{
			if(x%i==0)
			{
				if(l-A[i] > y)
					k++;
				A[i] = l;	
				if(i*i!=x)
				{
					if(l-A[x/i] > y)
						k++;						
					A[x/i] = l;	
				}
			}
		}

		printf("%d\n",k);
	}
	
	return 0;
}