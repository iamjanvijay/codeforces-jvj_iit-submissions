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
map<ll,int> Pre;
map<ll,int> Suf;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll tsum=0,csum=0,k;
	int i,j,l,m,n,w;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(A[i]);
		tsum+=A[i];
		Suf[A[i]]++;
	}	

	for(i=0;i<n;i++)
	{
		Suf[A[i]]--;	Pre[A[i]]++;
		csum+=A[i];	k=tsum-csum;
		if(csum-k==0)
		{
			printf("YES\n");	return 0;
		}
		else if(csum-k>0)
		{
			if((csum-k)%2==0 && Pre[(csum-k)/2]>=1)
			{
				printf("YES\n");	return 0;
			}
		}
		else
		{
			if((k-csum)%2==0 && Suf[(k-csum)/2]>=1)
			{
				printf("YES\n");	return 0;
			}	
		}
	}

	printf("NO\n");	

	return 0;
}