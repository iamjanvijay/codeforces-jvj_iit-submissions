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

string s;
vector<int> g[1007];
map<string, int> exists;
int val[1007];
int coun[1007];
int curVal=1;
int curNode=1;

int computeGraph(string &s, int first, int last)
{
	int i, node, l, count, prev;

	for(i=first,l=0; !(s[i]==&#39;.&#39;||s[i]==&#39;:&#39;) ;i++,l++);

	node = curNode++;	

	string temp = s.substr(first,l);

	// cout << temp << " : " << node << " " << first << " " << last << endl;  

	if(exists[temp]!=0)	
		val[node] = exists[temp];
	else
		val[node] = exists[temp] = curVal++;

	if(s[i]==&#39;:&#39;)
	{
		prev = i+1; count = 0;
		for(i=i+1;i<last;i++)
		{
			if(s[i]==&#39;:&#39;)
				count++;
			else if(s[i]==&#39;.&#39; && s[i-1]==&#39;.&#39;)
				count--;
			if(count==0 && s[i]==&#39;.&#39;)
			{
				g[node].pb( computeGraph(s, prev, i) );
				prev = i + 2;
			}
		}
	}

	return node;
}

void dfs(int src, int &ans)
{
	ans += coun[ val[src] ];
	coun[ val[src] ]++;
	for(int i=0;i<sz(g[src]);i++)
	{
		dfs(g[src][i], ans);
	}
	coun[ val[src] ]--;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	cin >> s;

	int src = computeGraph(s, 0, s.length()-1);

	a = 0;
	dfs(src, a);

	// for(i=1;i< curNode ;i++)
	// {
	// 	printf("%d : ", i );
	// 	for(j=0;j<sz(g[i]);j++)
	// 	{
	// 		printf("%d ", g[i][j] );
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", a );
	
	return 0;
}