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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	// int i,j,k,l,m,n,x,y,z,a,b,r,q;
	ll i,j,k,l,m,n=0,x=0,y=1,z,a,b,r,q;

	slld(q);

	// if(q==1)
	// {
	// 	printf("1\n0\n");
	// 	return 0;
	// }

	m = q;
	for(i=2;i*i<=q;i++)
	{
		while( (m%i) == 0 )
		{
			// printf("#%d\n", i );
			m/=i;	n++;	
		}
	}

	if(m!=1)
	{
		// printf("#%d\n", m );
		n++;	
	}

	// printf("*%d\n",n);

	if(n<=1)
	{
		printf("1\n0\n");
	}
	else if(n==2)
	{
		printf("2\n");
	}
	else
	{
		printf("1\n");
		n = 0;
		m = q;
		for(i=2;i*i<=q;i++)
		{
			while( (m%i) == 0 )
			{
				// printf("#%d\n", i );
				y*=i;
				m/=i;
				n++;
				if(n==2)
				{
					printf("%lld\n", y );
					return 0;
				}	
			}
		}

		if(m!=1)
		{
			// printf("#%d\n", m );
			y*=i;
			m/=m;
			n++;
			if(n==2)
			{
				printf("%lld\n", y );
				return 0;
			}					
		}
	}
	
	return 0;
}