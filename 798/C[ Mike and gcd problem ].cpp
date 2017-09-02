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

int gcdUtil(int a,int b)
{
	if(a==0)
		return b;
	return gcdUtil(b%a,a);
}

int gcd(int a,int b)
{
	return gcdUtil(min(a,b),max(a,b));
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b=0,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;
	sd(n);
	for(i=0;i<n;i++)
	{
		sd(A[i]);
	}

	a = A[0];
	for(i=1;i<n;i++)
	{
		a = gcd(a,A[i]);
	}

	if(a>1)
	{
		printf("YES\n0\n");	return 0;
	}

	a = 0;
	for(i=0;i<n;i++)
	{
		if(A[i]%2!=0)
		{
			a++;
		}
		else
		{
			if(a%2==0)
				b+=(a/2);
			else
				b+=(a/2+2);
			a=0;
		}
	}

	if(a%2==0)
		b+=(a/2);
	else
		b+=(a/2+2);	

	printf("YES\n%d\n",b );

	return 0;
}