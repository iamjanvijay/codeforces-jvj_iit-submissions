#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

vector<int> v;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);	sd(k);

	if(k==1)
	{
		k = 1;
		while(k<m+n+1)
		{
			v.pb(k);
			k = k+n-1;
		}

		printf("%d\n", sz(v) );
		for(i=0;i<sz(v);i++)
		{
			printf("%d",v[i]);
			if(i!=sz(v)-1)
				printf(" ");
		}
		printf("\n");
		return 0;
	}

	if(  (m+n)%n == 0 )
	{
		z = (m+n)/n*k+1;
	}	
	else
	{
		z = (m+n)/n*k+k;
	}

	printf("%d\n", z );

	for(i=0;i<k;i++)
	{
		printf("1 ");
		z--;
	}

	i = 1;
	while(true)
	{
		if(z>0)
		{
			printf("%d",i*n);	z--;
			if(z!=0)
				printf(" ");
		}
		else
		{
			printf("\n");
			break;
		}

		if(z>0)
		{
			for(j=0;j<k-1 && z>0;j++)
			{
				printf("%d", i*n+1 );	z--;
				if(z!=0)
					printf(" ");
			}
		}
		else
		{
			printf("\n");
			break;
		}

		i++;

	}
	
	return 0;
}