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

pair< pair<int,int> , unsigned int > Q[100007];
unsigned int Tree[270000];
unsigned int Lazy[270000];
unsigned int U=1;

void update(int first,int last,int cur,int qfirst,int qlast,unsigned int x)
{
	if(Lazy[cur]!=0)
	{
		Tree[cur] |= Lazy[cur];
		if(first!=last)
		{
			Lazy[2*cur+1] |= Lazy[cur];
			Lazy[2*cur+2] |= Lazy[cur];
		}
		Lazy[cur] = 0;
	}

	if( qfirst<=first && last<=qlast )
	{
		Tree[cur] |= x;
		if(first!=last)
		{
			Lazy[2*cur+1] |= x;
			Lazy[2*cur+2] |= x;
		}
		return;
	}

	if( qlast<first || last<qfirst )
		return;
	update(first,(first+last)/2,2*cur+1,qfirst,qlast,x);
	update(1+(first+last)/2,last,2*cur+2,qfirst,qlast,x);

	Tree[cur] = Tree[2*cur+1] & Tree[2*cur+2];
}

int query(int first,int last,int cur,int qfirst,int qlast)
{
	if(Lazy[cur]!=0)
	{
		Tree[cur] |= Lazy[cur];
		if(first!=last)
		{
			Lazy[2*cur+1] |= Lazy[cur];
			Lazy[2*cur+2] |= Lazy[cur];
		}
		Lazy[cur] = 0;
	}

	if( qlast<first || last<qfirst )
		return (U<<31)-1;

	if( qfirst<=first && last<=qlast )
	{
		return Tree[cur];
	}

	return query(first,(first+last)/2,2*cur+1,qfirst,qlast) & query(1+(first+last)/2,last,2*cur+2,qfirst,qlast);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,q,n,m;

	sd(n);	sd(m);	

	for(i=0;i<m;i++)
	{
		sd(l);	sd(r);	sd(q);	l--;	r--;
		update(0,n-1,0,l,r,q);
		Q[i] = make_pair( make_pair(l,r) , q );
	}

	for(i=0;i<m;i++)
	{
		if( query(0,n-1,0,Q[i].first.first,Q[i].first.second) != Q[i].second )
		{
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");
	for(i=0;i<n;i++)
	{
		printf("%d ", query(0,n-1,0,i,i) );
	}
	printf("\n");
	
	return 0;
}