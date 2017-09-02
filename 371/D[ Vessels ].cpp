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

ll Tree[600000];
bool Lazy[600000];
int A[200007];

void create(int first,int last,int cur)
{
	if(first==last)
	{
		Tree[cur] = A[first];
		return;
	}
	create(first,(first+last)/2,2*cur+1);
	create(1+(first+last)/2,last,2*cur+2);
	Tree[cur] = Tree[2*cur+1]+Tree[2*cur+2];
}

void update(int first,int last,int cur,int q,int x)
{
	if(Lazy[cur])
	{
		Tree[cur] = 0;
		if(first!=last)
			Lazy[2*cur+1] = Lazy[2*cur+2] = true;
		Lazy[cur] = false;
	}		
	if(last<q || q<first)
		return;	
	if(first==last)
	{
		Tree[cur] = x;
		return;
	}
	update(first,(first+last)/2,2*cur+1,q,x);
	update(1+(first+last)/2,last,2*cur+2,q,x);
	Tree[cur] = Tree[2*cur+1]+Tree[2*cur+2];
}

void set0(int first,int last,int cur,int qfirst,int qlast)
{
	if(qlast<qfirst)
		return;	
	if(Lazy[cur])
	{
		Tree[cur] = 0;
		if(first!=last)
			Lazy[2*cur+1] = Lazy[2*cur+2] = true;
		Lazy[cur] = false;
	}
	if(Tree[cur]==0 || last<qfirst || qlast<first)
		return;	
	if(qfirst<=first && last<=qlast)
	{
		Tree[cur] = 0;
		if(first!=last)
			Lazy[2*cur+1] = Lazy[2*cur+2] = true;	
		return;		
	}
	set0(first,(first+last)/2,2*cur+1,qfirst,qlast);
	set0(1+(first+last)/2,last,2*cur+2,qfirst,qlast);
	Tree[cur] = Tree[2*cur+1]+Tree[2*cur+2];
}

ll sum(int first,int last,int cur,int qfirst,int qlast)
{
	if(qlast<qfirst)
		return 0;
	if(Lazy[cur])
	{
		Tree[cur] = 0;
		if(first!=last)
			Lazy[2*cur+1] = Lazy[2*cur+2] = true;
		Lazy[cur] = false;
	}	
	if(last<qfirst || qlast<first)
		return 0;	
	if(qfirst<=first && last<=qlast)
		return Tree[cur];
	return sum(first,(first+last)/2,2*cur+1,qfirst,qlast)+sum(1+(first+last)/2,last,2*cur+2,qfirst,qlast);		
}



int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,t,r,x,p;
	int first,last,mid;
	ll z;
	sd(n);
	for(i=0;i<n;i++)
	{
		sd(A[i]);
	}
	create(0,n-1,0);
	sd(m);
	while(m--)
	{
		sd(t);
		if(t==1)
		{
			sd(p);	sd(x);
			first = p-1;	last = n-1;
			if(sum(0,n-1,0,first,last) < x)
				set0(0,n-1,0,first,last);
			else
			{
				while(1+first<last)
				{
					mid = (first+last)/2;
					if( sum(0,n-1,0,p-1,mid) >= x)
						last = mid;
					else
						first = mid;
				}
				z = sum(0,n-1,0,p-1,first);
				if( z >= x)
				{
					if(first!=p-1)
					{
						set0(0,n-1,0,p-1,first-1);
					}
					update(0,n-1,0,first,z-x);
				}
				else
				{
					z = sum(0,n-1,0,p-1,last);
					if(last!=p-1)
					{
						set0(0,n-1,0,p-1,last-1);
					}
					update(0,n-1,0,last,z-x);
				}
			}
			// printf("%lld %lld %lld\n", Tree[0] , Tree[1] , Tree[2] );
		}
		else
		{
			sd(k);	k--;
			printf("%d\n", A[k]-sum(0,n-1,0,k,k) );
			// printf("%lld %lld %lld\n", Tree[0] , Tree[1] , Tree[2] );
		}
	}
	
	return 0;
}