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

int A[1000000];

int sumLR(int l, int r)
{
	return ((r>=1000000)?A[1000000-1]:A[r]) - ((l-1)<0?0:A[l-1]);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<1000000;i++)
		A[i] = 1;

	for(i=0;i<n;i++)
	{
		sd(x);	A[x] = 0;
	}

	for(i=1;i<1000000;i++)
		A[i] += A[i-1];

	x = 0;

	while(m--)
	{
		sd(y);
		x ^= y;

		a = 0;
		for(i=30;i>=0;i--)
		{
			if(sumLR( a | ((1<<i) & x) , a | ((1<<i) & x) | ((1<<i) - 1)  )!=0)
				a |= ((1<<i) & x);
			else
			{
				if(((1<<i) & x)==0)
					a |= (1<<i); 
			}
			
		}

		printf("%d\n", x^a );
	}
	
	return 0;
}