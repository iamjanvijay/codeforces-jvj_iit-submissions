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

vector< pair<int,int> > V;

int main()
{
	int i,j,p,q,k,l,n;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(p);	sd(q);
		V.push_back( make_pair(p,q) );
	}

	sort(V.begin(), V.end());

	i=0;
	l=INT_MIN;
	while(i<n)
	{
		j=i;
		k=l;
		while(V[j].first == V[i].first)
		{
			if(V[j].second < l)
			{
				printf("Happy Alex\n");
				return 0;
			}
			k = max(k,V[j].second);
			j++;
		}
		l=k;
		i=j;	

	}

	printf("Poor Alex\n");	

	return 0;
}
