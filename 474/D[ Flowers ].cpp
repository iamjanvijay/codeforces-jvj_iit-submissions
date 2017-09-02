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

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,t;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(t);	sd(k);

	A[0] = 1;
	for(i=1;i<=100000;i++)
	{
		if(i-1>=0)
			A[i]=(A[i]+A[i-1])%Mod;
		if(i-k>=0)
			A[i]=(A[i]+A[i-k])%Mod;
	}

	for(i=1;i<=100000;i++)
	{
		A[i]=(A[i]+A[i-1])%Mod;
	}

	while(t--)
	{
		sd(l);	sd(r);
		printf("%d\n", (A[r]-A[l-1]+Mod)%Mod );
	}

	return 0;
}