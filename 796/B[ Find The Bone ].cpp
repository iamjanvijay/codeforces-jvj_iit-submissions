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

bool H[1000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,r,ans=1;
	// ll i,j,k,l,m,n,x,y,z,r;
	sd(n);	sd(m);	sd(r);

	for(i=0;i<m;i++)
	{
		sd(k);	H[k]=true;
	}

	while(r--)
	{
		sd(j);	sd(k);

		if(!H[ans])
		{
			if(ans==j)
			{
				ans=k;
			}
			else if(ans==k)
			{
				ans=j;
			}
		}

	}

	printf("%d\n", ans );
	
	return 0;
}