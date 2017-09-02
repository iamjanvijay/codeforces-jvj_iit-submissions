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

char M[20][107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,o,p,q,x,y,z,a,b,c,r,lc,rc;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);	m+=2;

	for(i=0;i<n;i++)
		ss(M[i]);

	int ans;

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(M[i][j]==&#39;1&#39;)
				break;
		}
		if(j<m)
			break;
	}

	// printf("%d\n", i );

	if(i>=n)
	{
		printf("0\n");
		return 0;
	}
	// printf("%d\n",i);

	k = i;
	lc = rc = -1;
	for(i=k;i<n-1;i++)
	{


		l = INT_MAX;	r = INT_MIN;

		for(j=0;j<m;j++)
		{
			if(M[i][j]==&#39;1&#39;)
			{
				l = min(l,j);	r = max(r,j);
			}
		}

		// printf("***%d %d\n", l ,r );

		if(l==INT_MAX && r==INT_MIN)
		{
			
		}
		else if(lc==-1 && rc==-1)
		{
			lc = r;	rc = m-l-1;
		}
		else
		{
			x = lc;		y = rc;
			lc = min(x+2*r,m-1+y);	rc = min(m-1+x,y+2*(m-l-1));
		}

		// printf("#%d %d\n", lc , rc );


		lc++;	rc++;

	}

	l = INT_MAX;	r = INT_MIN;

	for(j=0;j<m;j++)
	{
		if(M[n-1][j]==&#39;1&#39;)
		{
			l = min(l,j);	r = max(r,j);
		}
	}

	if(lc==-1 && rc==-1)
	{
		lc = r;	
	}
	else
	{
		x = lc;		y = rc;
		lc = min(x+2*r,m-1+y);	
	}	

	printf("%d\n", lc );

	return 0;
}