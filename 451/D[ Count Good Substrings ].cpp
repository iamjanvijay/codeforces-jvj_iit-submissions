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

char S[100007];
int A[100007][3];
int B[100007][3];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,na=0,nb=0;
	ll odds = 0,evens=0,ansodds=0,ansevens=0,x,y,z;
	ss(S);
	
	i=0;
	while(S[i]!=&#39;\0&#39;)
	{
		j=i;
		while(S[j]==S[j+1])
			j++;

		if(S[j]==&#39;a&#39;)
		{
			if( (j-i+1)%2 == 0)
			{
				A[na][0] = A[na][1] = (j-i+1)/2;
			}
			else
			{
				if(i%2==0)
				{
					A[na][0] = (j-i+1)/2 + 1;
					A[na][1] = (j-i+1)/2;
				}
				else
				{
					A[na][0] = (j-i+1)/2;
					A[na][1] = (j-i+1)/2 + 1;
				}
			}
			na++;
		}

		if(S[j]==&#39;b&#39;)
		{
			if( (j-i+1)%2 == 0)
			{
				B[nb][0] = B[nb][1] = (j-i+1)/2;
			}
			else
			{
				if(i%2==0)
				{
					B[nb][0] = (j-i+1)/2 + 1;
					B[nb][1] = (j-i+1)/2;
				}
				else
				{
					B[nb][0] = (j-i+1)/2;
					B[nb][1] = (j-i+1)/2 + 1;
				}
			}
			nb++;
		}
		i=j+1;
	}


	// for(i=0;i<na;i++)
		// printf("%d %d\n",A[i][0],A[i][1] );

	for(i=na-1;i>=0;i--)
	{
		z = A[i][0]+A[i][1];
		z = z*(z+1)/2;
		y = ((ll)A[i][0])*(A[i][0]+1)/2 + ((ll)A[i][1])*(A[i][1]+1)/2;
		z -= y;
		ansodds += y;
		ansevens += z;
		ansevens += (odds*A[i][0]) + (evens*A[i][1]);
		ansodds += (evens*A[i][0]) + (odds*A[i][1]);
		odds+=A[i][1];
		evens+=A[i][0];
	}

	odds = 0; evens = 0;

	for(i=nb-1;i>=0;i--)
	{
		z = B[i][0]+B[i][1];
		z = z*(z+1)/2;
		y = ((ll)B[i][0])*(B[i][0]+1)/2 + ((ll)B[i][1])*(B[i][1]+1)/2;
		z -= y;
		ansodds += y;
		ansevens += z;
		ansevens += (odds*B[i][0]) + (evens*B[i][1]);
		ansodds += (evens*B[i][0]) + (odds*B[i][1]);
		odds+=B[i][1];
		evens+=B[i][0];
	}	

	printf("%lld %lld\n",ansevens,ansodds );

	return 0;
}