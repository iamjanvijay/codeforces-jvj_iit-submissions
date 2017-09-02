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
#define pb push_back
#define mp make_pair

vector<ll> Odds;
vector<ll> Evens;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,l,k,p,n;

	sd(n);	sd(k);	sd(p);

	for(i=0;i<n;i++)
	{
		sd(l);
		if( l%2 == 0 )
			Evens.pb(l);
		else
			Odds.pb(l);
	}

	if( (Odds.size()) < (k-p) || (k-p)%2 != (Odds.size())%2 || ( (Odds.size()) - (k-p) )/2 + (Evens.size()) < p )	
	{
		printf("NO\n");
		return 0;
	}
	
	printf("YES\n");

	for(i=0;i<(k-p);i++)
	{
		if(i!=k-p-1)
		{
			printf("%d %lld\n", 1, Odds[i] );
		}
		else
		{
			if(p==0)
			{
				printf("%d ", (Evens.size()) + (Odds.size() - i) );
				for(j=0;j<Evens.size();j++)
					printf("%lld ", Evens[j] );
				for(j=i;j<Odds.size();j++)
					printf("%lld ", Odds[j] );
				printf("\n");
			}
			else
				printf("%d %lld\n", 1, Odds[i] );
		}	
	}

	l = 0;
	for(j=0;j<p;j++)
	{
		if(j == p-1)
		{
			printf("%d ", (Odds.size() - i) + (Evens.size()-l) );
			for(i;i<Odds.size();i++)
				printf("%lld ", Odds[i] );
			for(l;l<Evens.size();l++)
				printf("%lld ", Evens[l] );
			printf("\n");
			return 0;
		}	

		if(i != Odds.size())
		{
			printf("2 ");
			printf("%lld ", Odds[i] );	i++;
			printf("%lld\n", Odds[i] );	i++;
		}
		else
		{
			printf("1 ");
			printf("%lld\n", Evens[l] );	l++;
		}	
	}

	return 0;
}