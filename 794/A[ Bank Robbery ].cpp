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

map<int,int> Count;
set<int> St;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r,ans=0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(a);	sd(b);	sd(c);

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(k);
		Count[k]++;
		St.insert(k);
	}

	set<int>::iterator it;
	for(it=St.begin();it!=St.end();++it)
	{
		if((*it)>b && (*it)<c)
		{
			ans+=Count[*it];
		}
	}

	printf("%d\n", ans );

	return 0;
}