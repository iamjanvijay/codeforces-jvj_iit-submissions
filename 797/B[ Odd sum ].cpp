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

int A[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,o,p,q,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);

	a = 0;	b = INT_MIN; c = INT_MAX;

	for(i=0;i<n;i++)
	{
		if(A[i]%2!=0)
		{
			if(A[i]<0)
			{
				b = max(b,A[i]);
			}
			else
			{
				c = min(c,A[i]);
			}
		}

		if(A[i]>0)
		{
			a+=A[i];
		}
	}

	if(a%2!=0)
	{
		printf("%d\n", a );
	}
	else
	{
		if( b!=INT_MIN && c!=INT_MAX )
		{
			if(-b<c)
			{
				printf("%d\n", a+b );
			}
			else
			{
				printf("%d\n", a-c );
			}
		}
		else if( b!=INT_MIN )
		{
			printf("%d\n", a+b );
		}
		else
		{
			printf("%d\n", a-c );
		}
	}
	
	return 0;
}