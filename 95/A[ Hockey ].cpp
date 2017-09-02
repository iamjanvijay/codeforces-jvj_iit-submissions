#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

char s[107][107];
char w[107];
char t[7];
bool replac[107];

char low(char c)
{
	if(&#39;A&#39;<=c && c<=&#39;Z&#39;)
		return (char)((int)c - &#39;A&#39; + &#39;a&#39;);
	return c;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		ss(s[i]);

	ss(w);
	ss(t);

	for(i=0;i<n;i++)
	{
		for(j=0;w[j]!=&#39;\0&#39;;j++)
		{
			for(l=0;s[i][l]!=&#39;\0&#39;;l++)
			{
				if(w[j+l]==&#39;\0&#39; || low(s[i][l])!=low(w[j+l]))
					break;
			}
			if(s[i][l]==&#39;\0&#39;)
			{
				for(l=0;s[i][l]!=&#39;\0&#39;;l++)
				{
					replac[j+l] = true;
				}
			}
		}
	}

	for(i=0;w[i]!=&#39;\0&#39;;i++)
	{
		if(replac[i])
		{
			if(t[0]==&#39;a&#39;)
			{
				if(&#39;A&#39;<=w[i] && w[i]<=&#39;Z&#39;)
				{
					if(w[i]==&#39;A&#39;)
						w[i] = &#39;B&#39;;
					else
						w[i] = char(int(t[0] - &#39;a&#39; + &#39;A&#39;));
				}
				else
				{
					if(w[i]==&#39;a&#39;)
						w[i] = &#39;b&#39;;
					else
						w[i] = t[0];
				}
			}
			else
			{
				if(&#39;A&#39;<=w[i] && w[i]<=&#39;Z&#39;)
				{
					if(w[i]==char(int(t[0] - &#39;a&#39; + &#39;A&#39;)))
						w[i] = &#39;A&#39;;
					else
						w[i] = char(int(t[0] - &#39;a&#39; + &#39;A&#39;));
				}
				else
				{
					if(w[i]==t[0])
						w[i] = &#39;a&#39;;
					else
						w[i] = t[0];
				}
			}
		}
	}
	
	printf("%s\n", w );

	return 0;
}