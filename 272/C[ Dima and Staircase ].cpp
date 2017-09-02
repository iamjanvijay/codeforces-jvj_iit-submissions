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

ll Tree[262167];
ll lazy[262167];
ll A[100007];

void createTree(int first,int last,int cur)
{
	if(first==last)
	{
		Tree[cur] = A[first];
		return;
	}

	int mid = (first+last)/2;

	createTree(first,mid,2*cur+1);
	createTree(1+mid,last,2*cur+2);

	Tree[cur] = max(Tree[2*cur+1],Tree[2*cur+2]);
}

void update(int first,int last,int qfirst,int qlast,int cur,ll val)
{
	if(lazy[cur]!=0)
	{
		if(first!=last)
		{
			lazy[2*cur+1] = lazy[cur];
			lazy[2*cur+2] = lazy[cur];
		}
		Tree[cur] = lazy[cur];
		lazy[cur] = 0;	
	}

	if(qfirst<=first && last<=qlast)
	{
		Tree[cur] = val;
		if(first!=last)
		{
			lazy[2*cur+1] = val;
			lazy[2*cur+2] = val;
		}		
		return;
	}
	if(first>qlast || qfirst>last)
		return;

	int mid = (first+last)/2;
	update(first,mid,qfirst,qlast,2*cur+1,val);		
	update(1+mid,last,qfirst,qlast,2*cur+2,val);
	Tree[cur] = max(Tree[2*cur+1],Tree[2*cur+2]);
}

ll query(int first,int last,int qfirst,int qlast,int cur)
{
	if(lazy[cur]!=0)
	{
		if(first!=last)
		{
			lazy[2*cur+1] = lazy[cur];
			lazy[2*cur+2] = lazy[cur];
		}
		Tree[cur] = lazy[cur];
		lazy[cur] = 0;	
	}

	if(qfirst<=first && last<=qlast)
		return Tree[cur];
	if(first>qlast || qfirst>last)
		return LLONG_MIN;

	int mid = (first+last)/2;

	return max( query(first,mid,qfirst,qlast,2*cur+1), query(1+mid,last,qfirst,qlast,2*cur+2) );	
}

int main()
{
	int i,j,k,l,m,n,w;
	ll temp,h;

	sd(n);
	for(i=0;i<n;i++)
	{
		slld(A[i]);
	}

	createTree(0,n-1,0);

	sd(m);

	// for(i=0;i<8;i++)
	// 	printf("%d:%lld:%lld  ", i,Tree[i],lazy[i] );
	// printf("\n");
	while(m--)
	{
		sd(w);	slld(h);
		temp = query(0,n-1,0,w-1,0);
		printf("%lld\n", temp);
		update(0,n-1,0,w-1,0,h+temp);

		// for(i=0;i<8;i++)
		// 	printf("%d:%lld:%lld  ", i,Tree[i],lazy[i] );
		// printf("\n");

	}	

		// printf("\n");
	return 0;
}
