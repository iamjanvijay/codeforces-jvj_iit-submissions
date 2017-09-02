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

int A[100007];
int Ones[100007];
int Twos[100007];
vector< pair<int, int> > ans;

int ind(int A[], int key, int fs, int ls)
{
	if(key > A[ls])
		return -1;

	int md;
	while(fs+1<ls)
	{
		md = (fs+ls)/2;
		if( key <= A[md] )
			ls = md;
		else
			fs = md;
	}

	if(key<=A[fs])
		return fs;
	return ls;
}

int findS(int t, int n)
{
	int i, j, win1, win2, x1, x2, c;
	win1 = win2 = 0;

	i = 1;
	while(i<=n)
	{
		x1 = ind(Ones, Ones[i-1] + t, i, n);
		x2 = ind(Twos, Twos[i-1] + t, i, n);
		if(x1 == -1 && x2 == -1)
			return -1;
		else if(x1==-1)
		{
			c = 2;
			win2++;
			i = x2 + 1;
		}
		else if(x2==-1)
		{
			c = 1;
			win1++;
			i = x1 + 1;
		}
		else if(x2<x1)
		{
			c = 2;
			win2++;
			i = x2 + 1;
		}
		else if(x2>x1)
		{
			c = 1;
			win1++;
			i = x1 + 1;
		}
	} 
	if((win1==win2) || (win1>win2 && c!=1) || (win1<win2 && c!=2) )
		return -1;
	return max(win2, win1);
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,t,s;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(A[i]);

		if(A[i]==1)
			Ones[i] = Ones[i-1] + 1;
		else
			Ones[i] = Ones[i-1];

		if(A[i]==2)
			Twos[i] = Twos[i-1] + 1;
		else
			Twos[i] = Twos[i-1];
	}

	for(t=1;t<=n;t++)
	{
		s = findS(t,n);
		if(s!=-1)
			ans.pb( mp(s, t) );
	}

	sort(ans.begin(), ans.end());

	printf("%d\n", sz(ans) );
	for(i=0;i<sz(ans);i++)
		printf("%d %d\n", ans[i].F, ans[i].S );
	
	return 0;
}