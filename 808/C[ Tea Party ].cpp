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

pair<int,int> A[107];
int ANS[107];

int ceilfun(int n)
{
	if(n%2==0)
		return n/2;
	else
		return n/2+1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,w;

	sd(n);	sd(w);

	for(i=0;i<n;i++)
	{
		sd(A[i].F);	A[i].S = i;
	}

	sort(A,A+n);
	
	k = 0; l = 0;
	for(i=0;i<n;i++)
	{
		k+=ceilfun(A[i].F);
		l+=(A[i].F);
	}

	if(k>w || l<w)
	{
		printf("-1\n");
		return 0;
	}	

	for(i=0;i<n;i++)
	{
		ANS[A[i].S]+=ceilfun(A[i].F);
		w-=ceilfun(A[i].F);
	}

	for(i=n-1;i>=0 && w>0;i--)
	{
		k=((A[i].F)-ANS[A[i].S]);
		ANS[A[i].S]+=min(k,w);
		w-=min(k,w);
	}

	for(i=0;i<n;i++)
		printf("%d ",ANS[i]);

	return 0;
}