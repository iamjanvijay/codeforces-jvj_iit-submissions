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

vector< pair<int,int> > A;
ll Fact[200007];
ll Pow2[200007];
ll CalcPow2[21];
ll Remaining[200007];

// pair<int,int> ext_gcd(int a, int b)
// {
//     if(b==0)
//         return mp(1, 0);
//     else
//     {
//         pair<int,int> temp = ext_gcd(b, a%b);
//         int x = temp.F, y = temp.S;
//         return mp(y, x-(a/b)*y);
//     }
// }

// int mod_inv(int a,int N)  // a&#39;s inverse modulo N
// {
//     pair<int,int> temp = ext_gcd(a, N);
//     int x = temp.F, y = temp.S;
//     return (x+N)%N;
// }

ll power2(ll y, int m)
{
	if(y<=0)
		return 1;
	ll temp = power2(y/2,m);
	if(y%2==0)
		return (temp*temp)%m;
	else
		return (2*((temp*temp)%m))%m;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,b;
	ll p, ans = 1;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=1;i<=n;i++)
	{
		sd(k);
		A.pb( mp(k,i) );
	}

	for(i=1;i<=n;i++)
	{
		sd(k);
		A.pb( mp(k,i) );
	}

	sd(m);

	for(i=2;i<200007;i*=2)
	{
		for(j=i;j<200007;j+=i)
		{
			Pow2[j]++;
		}
	}

	CalcPow2[0] = 1;
	for(i=1;i<21;i++)
		CalcPow2[i] = (2*CalcPow2[i-1]);


	Fact[0] = 1;
	Remaining[0] = 0;
	for(i=1;i<200007;i++)
	{
		Fact[i] = ((i/CalcPow2[ Pow2[i] ]) * Fact[i-1])%m;
		Remaining[i] = Remaining[i-1] + Pow2[i];
	}

	sort(A.begin(), A.end());

	ll r=0;
	i = 0;	j = 0;	ll a = 0;	
	while( i < 2*n )
	{
		j = i;
		while(j+1<2*n && A[i].F==A[j+1].F)
			j++;

		for(x=i+1;x<=j;x++)
		{
			if( A[x] == A[x-1] )
			{
				a++;
			}
		}

		ans = (ans * Fact[j-i+1])%m;
		r += Remaining[j-i+1];

		i = j+1;
	}

	if(r-a<0)
	{
		printf("FUCK YOU\n");
		return 0;
	}

	ans = (ans * power2(r-a,m) )%m;

	printf("%lld\n", ans  );
	
	return 0;
}