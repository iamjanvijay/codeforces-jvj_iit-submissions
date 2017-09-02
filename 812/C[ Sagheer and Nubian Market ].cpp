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

ll A[100007];
ll temp[100007];

ll minCost(ll n,ll k)
{
	int i;
	if(k==0)
		return 0;
	for(i=0;i<n;i++)
		temp[i] = A[i] + (i+1)*k;

	sort(temp,temp+n);

	ll s = 0;
	for(i=0;i<k;i++)
		s+=temp[i];
	return s;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	ll i,j,k,l,m,n,o,p,q,s,x,y,z,a,b,c,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	slld(n);	slld(s);

	for(i=0;i<n;i++)
		slld(A[i]);

	ll first = 0,last = n,mid,ans;

	while(first+1<last)
	{
		mid = (first+last)/2;

		x = minCost(n,mid);

		if(x<=s)
		{
			first = mid;
			ans = x;
		}
		else
		{
			last = mid;
		}

	}	

	if(minCost(n,last)<=s)
		printf("%lld %lld\n", last, minCost(n,last) );
	else
		printf("%lld %lld\n", first, minCost(n,first) );
	
	return 0;
}