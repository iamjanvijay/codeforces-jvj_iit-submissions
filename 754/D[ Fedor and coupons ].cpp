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

vector<pair<pair<int, int>,int> > V; 
priority_queue<int, vector<int>, greater<int> > minHeap;

int chk(int &k, int x)
{
	while(!minHeap.empty())
		minHeap.pop();
	for(int i=0;i<sz(V);i++)
	{
		while(!minHeap.empty() && minHeap.top() < V[i].F.F + 1LL*x - 1LL)
			minHeap.pop();
		if( (V[i].F.S >= V[i].F.F + 1LL*x - 1LL) && ( minHeap.size() >= k-1 )  ) 
			return i;
		minHeap.push(V[i].F.S);
	}
	return -1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	ll fs,ls,md;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	for(i=1;i<=n;i++)
	{
		sd(l);	sd(r);
		V.pb( mp( mp(l,r) , i ) );
	}

	sort(V.begin(), V.end());

	fs = 0;		ls = 2000000007LL;

	b = -1;
	while(fs+1<ls)
	{
		md = (fs+ls)/2;
		j = chk(k,md);
		if(j!=-1)
		{
			b = j;
			fs = md;
		}
		else
			ls = md;
	}

	printf("%d\n", fs );
	for(i=0;i<sz(V) && k>0;i++)
	{
		if( (b==-1) || (V[i].F.F <= V[b].F.F && V[b].F.F + 1LL*fs - 1LL <= V[i].F.S) )
		{
			printf("%d ", V[i].S );
			k--;
		}
	}

	return 0;
}