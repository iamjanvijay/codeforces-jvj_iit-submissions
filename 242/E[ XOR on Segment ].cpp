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

int Tree[270000][40];
int Lazy[270000];
int A[100007];

void create(int first,int last,int cur)
{
	int i;
	if(first==last)
	{
		for(i=0;i<31;i++)
		{
			if( ( (A[first] >> i) & 1) != 0 )
				Tree[cur][i] = 1;
			else
				Tree[cur][i] = 0;
		}
		return;
	}

	create(first,(first+last)/2,2*cur+1);
	create(1+(first+last)/2,last,2*cur+2);

	for(i=0;i<38;i++)
	{
		Tree[cur][i] = Tree[2*cur+1][i] + Tree[2*cur+2][i];
	}
}

void printTree(int first,int last,int cur)
{
	int i;
	if(first==last)
	{
		for(i=3;i>=0;i--)
		{
			printf("%d",Tree[cur][i]);
		}
		printf("( %d )\n",Lazy[cur]);
		return;
	}

	printTree(first,(first+last)/2,2*cur+1);
	printTree(1+(first+last)/2,last,2*cur+2);

	for(i=3;i>=0;i--)
	{
		printf("%d",Tree[cur][i]);
	}
	printf("( %d )\n",Lazy[cur]);	
}

void update(int first,int last,int cur,int qfirst,int qlast,int x)
{
	int i;
	if(Lazy[cur]!=0)
	{
		if(first!=last)
		{
			Lazy[2*cur+1] ^= Lazy[cur];	Lazy[2*cur+2] ^= Lazy[cur];
		}
		
		for(i=0;i<31;i++)
		{
			if( ( (Lazy[cur] >> i) & 1) != 0 )
			{
				Tree[cur][i] = last-first+1 - Tree[cur][i];
			}
		}

		Lazy[cur] = 0;
	}

	if(qfirst<=first && last<=qlast)
	{
		for(i=0;i<31;i++)
		{
			if( ( (x >> i) & 1) != 0 )
			{
				Tree[cur][i] = last-first+1 - Tree[cur][i];
			}
		}		

		if(first!=last)
		{
			Lazy[2*cur+1] ^= x;	Lazy[2*cur+2] ^= x;
		}
		return;
	}

	if(last<qfirst || qlast<first)
		return;

	update(first,(first+last)/2,2*cur+1,qfirst,qlast,x);
	update(1+(first+last)/2,last,2*cur+2,qfirst,qlast,x);

	for(i=0;i<31;i++)
	{
		Tree[cur][i] = Tree[2*cur+1][i] + Tree[2*cur+2][i];
	}

}

ll sum(int first,int last,int cur,int qfirst,int qlast)
{
	int i;
	if(Lazy[cur]!=0)
	{
		if(first!=last)
		{
			Lazy[2*cur+1] ^= Lazy[cur];	Lazy[2*cur+2] ^= Lazy[cur];
		}
		
		for(i=0;i<31;i++)
		{
			if( ( (Lazy[cur] >> i) & 1) != 0 )
			{
				Tree[cur][i] = last-first+1 - Tree[cur][i];
			}
		}

		Lazy[cur] = 0;
	}

	ll ret=0;
	if(qfirst<=first && last<=qlast)
	{
		int i;
		ll prod=1;
		for(i=0;i<31;i++,prod*=2)
		{
			// printf("%d",Tree[cur][i]);
			ret += prod*Tree[cur][i];
		}
		// printf("\n");
		return ret;
	}

	if(last<qfirst || qlast<first)
		return 0;	

	return sum(first,(first+last)/2,2*cur+1,qfirst,qlast) + sum(1+(first+last)/2,last,2*cur+2,qfirst,qlast);

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n,t,x;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	create(0,n-1,0);

	sd(m);
	while(m--)
	{
		sd(t);	
		if(t==1)
		{
			sd(l);	sd(r);	l--;	r--;
			printf("%lld\n", sum(0,n-1,0,l,r) );
		}
		else
		{
			sd(l);	sd(r);	sd(x);	l--;	r--;
			update(0,n-1,0,l,r,x);
		}
		// printTree(0,n-1,0);
	}
	
	return 0;
}