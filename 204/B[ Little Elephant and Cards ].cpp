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

set<int> S;
map<int,int> Already;
map<int,int> Moves;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,f,b,ans=INT_MAX;

	sd(n);
	if(n%2==0)
		m=n/2;
	else
		m=n/2+1;
	for(i=0;i<n;i++)
	{
		sd(f);	sd(b);
		S.insert(f);	S.insert(b);

		if(f==b)
		{
			Already[f]++;
		}
		else
		{
			Already[f]++;	Moves[b]++;
		}

	}

	set<int>::iterator it;
	for(it=S.begin();it!=S.end();it++)
	{
		if(Already[*it]+Moves[*it]>=m && ans>max(0,m-Already[*it]))
			ans = max(0,m-Already[*it]);
	}

	if(ans==INT_MAX)
		printf("-1\n");
	else
		printf("%d\n",ans );
	
	return 0;
}