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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n,p,cost=0;

	sd(n);	sd(p);

	ss(S+1);

	if( p > n/2 )
		p = 1 + n-p;

	for(l=-1,i=p;i>=1;i--)
		if(S[i]!=S[n-i+1])
		{
			cost += min( 26 - abs(S[n-i+1]-S[i]),abs(S[n-i+1]-S[i]) );
			l = i;
		}

	for(r=-1,i=p;i<=n/2;i++)
		if(S[i]!=S[n-i+1])
		{
			cost += min( 26 - abs(S[n-i+1]-S[i]),abs(S[n-i+1]-S[i]) );
			r = i;
		}	

	cost -= min( 26 - abs(S[n-p+1]-S[p]),abs(S[n-p+1]-S[p]) );	

	if(l==-1 && r!=-1)
	{
		cost += (r-p) ;
		printf("%d\n", cost );
	}	
	else if(l!=-1 && r==-1)
	{
		cost += (p-l) ;
		printf("%d\n", cost );
	}
	else if(l==-1 && r==-1)
	{
		printf("0\n");
	}
	else
	{
		cost += min( (p-l) + (r-l),	(r-p) + (r-l) );
		printf("%d\n", cost );
	}
	
	return 0;
}