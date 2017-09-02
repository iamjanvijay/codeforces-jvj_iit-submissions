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

int Mod = 1000000007;
vector< pair<int, int> > V;
set<int> dis; 
set<int>::iterator it;
map<int, int> maps;
// vector<int> disVec;

int Tree[524288];

int rangeSum(int fs, int ls, int qfs, int qls, int cur)
{
	if(qfs<=fs && ls<=qls)
		return Tree[cur];
	if(qfs>ls || fs>qls)
		return 0;
	return (rangeSum(fs, (fs+ls)/2, qfs, qls, 2*cur+1) + rangeSum(1+(fs+ls)/2, ls, qfs, qls, 2*cur+2))%Mod;
}

void update(int fs, int ls, int qk, int qval, int cur)
{
	if(fs>qk || qk>ls)
		return;
	if(fs==ls)
	{
		Tree[cur] = (Tree[cur] + qval)%Mod;
		return;
	}
	update(fs, (fs+ls)/2, qk, qval, 2*cur+1);
	update(1+(fs+ls)/2, ls, qk, qval, 2*cur+2);
	Tree[cur] = (Tree[2*cur+1] + Tree[2*cur+2])%Mod;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,s,t;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	dis.insert(0);
	dis.insert(n);
	for(i=0;i<m;i++)
	{
		sd(s);	sd(t);
		dis.insert(s);	dis.insert(t);
		V.pb( mp(t,s) );
	}

	sort(V.begin(), V.end());

	for(i=0,it=dis.begin();it!=dis.end();++it,++i)
	{
		maps[*it] = i;		
		// disVec.pb( *it );
	}

	// printf("Updating Key %d by %d\n", 0, 1);
	update(0, sz(dis)-1, 0, 1, 0);
	for(i=0;i<sz(V);i++)
	{
		k = rangeSum(0, sz(dis)-1, maps[V[i].S], maps[V[i].F] - 1, 0);
		// printf("Returning Sum %d to %d : %d\n", maps[V[i].S], maps[V[i].F] - 1, k );
		// printf("Updating Key %d by %d\n", maps[V[i].F], k);
		update(0, sz(dis)-1, maps[V[i].F], k, 0);
	}
	
	printf("%d\n", rangeSum(0, sz(dis)-1, sz(dis)-1, sz(dis)-1, 0));

	return 0;
}