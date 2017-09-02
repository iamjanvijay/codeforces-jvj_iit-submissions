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

ll Mod=1000000007;
char St[107];
ll Pow2[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(St);	n=strlen(St);

	Pow2[0] = 1;
	for(i=1;i<107;i++)
		Pow2[i] = (2*Pow2[i-1])%Mod;

	for(i=0,j=0,k=n-1;i<n;i++,k--,j++)
	{
		if(St[i]==&#39;1&#39;)
			a = ( a + ((((Pow2[k]*Pow2[k])%Mod)*Pow2[j])%Mod) )%Mod;
	}

	printf("%lld\n", a );
	
	return 0;
}