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
char P[100007];
int Suff[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	char w;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	ss(P);

	for(i=0;i<n/2;i++)
	{
		w = P[i];
		P[i] = P[n-1-i];
		P[n-1-i] = w;
		x = A[i];
		A[i] = A[n-1-i];
		A[n-1-i] = x;
	}

	// printf("-> %s\n", P );

	for(i=n-1;i>=0;i--)
		Suff[i] = Suff[i+1] + A[i];

	for(a=0,b=0,i=0;i<n;i++)
	{
		if(P[i]==&#39;1&#39;)
		{
			b = max(b, a+Suff[i+1]);
		}

		if(P[i]==&#39;1&#39;)
			a += A[i];
	}

	b = max(b, a);

	printf("%d\n", b ); 
	
	return 0;
}