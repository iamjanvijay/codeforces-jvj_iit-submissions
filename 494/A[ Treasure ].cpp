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
vector<int> V;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k=0,l=0,m=0,n;
	ss(S);

	for(i=0;S[i]!=&#39;\0&#39;;i++)
		if(S[i]==&#39;(&#39;)
			m++;
		else if(S[i]==&#39;)&#39;)
			m--;
		else
			l++;

	if( l > m )
	{
		printf("-1\n");
	}
	else 
	{
		k=0;
		for(i=0;S[i]!=&#39;\0&#39;;i++)
		{
			if(S[i]==&#39;#&#39;)
			{
				if(l>1)
				{
					V.push_back(1);
					k--;	m--;
				}
				else
				{
					V.push_back(m);					
					k-=m;	m-=m;
				}	
				l--;	
			}
			else
			{
				if(S[i]==&#39;(&#39;)
					k++;
				else
					k--;
			}
			if(k<0)
			{
				printf("-1\n");
				return 0;
			}
		}
	}	

	for(i=0;i<V.size();i++)
		printf("%d\n", V[i] );
	
	return 0;
}