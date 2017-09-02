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

int Mod=1000000007;
int A[200007];
int cnt[1000007];
int Pow2[200007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
	{
		for(j=1;j*j<=A[i];j++)
		{
			if(A[i]%j==0)
			{
				cnt[j]++;
				if(j*j!=A[i])
					cnt[A[i]/j]++;
			}
		}
	}

	Pow2[0] = 1;
	for(i=1;i<200007;i++)
		Pow2[i] = (2LL * Pow2[i-1])%Mod;

	for(i=2;i<1000007;i++)
		cnt[i] = (1LL * cnt[i] * Pow2[max(0,cnt[i]-1)])%Mod;;

	for(i=1000000;i>=1;i--)
	{
		for(j=2*i;j<=1000000;j+=i)
		{
			cnt[i] = (cnt[i] - cnt[j] + Mod)%Mod;
		}
	}	 
	
	ans = 0;

	for(i=2;i<=1000000;i++)
	{
		ans = (ans + 1LL * cnt[i] * i)%Mod;
	}

	printf("%d\n", ans );

	return 0;
}