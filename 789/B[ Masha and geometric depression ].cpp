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

set<int> A;
vector<int> X;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,b,q,l,m,n;

	sd(b);	sd(q);	sd(l);	sd(m);

	for(i=0;i<m;i++)
	{
		sd(k);	A.insert(k);
	}

	if(b==0)
	{
		if(A.count(0)==0)
		{
			printf("inf\n");
			return 0;
		}
	}
	else if(q==0)
	{
		bool flag = false;
		if( abs(b)<=l )
		{
			if(A.count(b)==0)
			{
				X.push_back(b);
			}
			flag = true;
		}		
		if(A.count(0)==0 && flag)
		{
			printf("inf\n");
			return 0;
		}	
	}
	else if(q==1)
	{
		if( abs(b)<=l )
		{
			if(A.count(b)==0)
			{
				printf("inf\n");
				return 0;
			}
		}
	}
	else if(q==-1)
	{
		if( abs(b)<=l )
		{
			if(A.count(b)==0)
			{
				printf("inf\n");
				return 0;
			}
			if(A.count(-b)==0)
			{
				printf("inf\n");
				return 0;
			}
		}
	}
	else
	{
		ll term=b;
		while(abs(term)<=l)
		{
			if(A.count(term)==0)
				X.push_back(term);
			term*=q;
		}
	}
	
	printf("%d\n", X.size() );

	return 0;
}