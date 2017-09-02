#include <bits/stdc++.h>
using namespace std;

#define sd(x) scanf("%d",&x)
#define su(x) scanf("%u",&x)
#define slld(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define sf(x) scanf("%f",&x)
#define slf(x) scanf("%lf",&x)
#define ll long long int
#define mod(x,n) (x+n)%n


int A[100007];
int B[100007];

bool check(int h,int m,int n,int w)
{
	ll i,ans=0,S=0;

	for(i=0;i<=n;i++)
		B[i] = 0;

	for(i=1;i<=n;i++)	
	{
		if( i - w >= 1 )
			S -= B[ i - w ];		
		if( S + A[i] < h )
		{
			B[ i ] = h - S - A[i];
			ans += B[i];
			S += B[i];
		}	
	}

	if(ans<=m)
		return true;
	return false;		
}

int binary(int n,int m,int w)
{
	int first = 1,mid, last = 1000100000;

	while( first + 1 < last )
	{
		mid = (first+last)/2;
		if( check(mid,m,n,w) )
		{
			first = mid;
		}
		else
		{
			last = mid;
		}	
	}

	if( check(last,m,n,w) )
		return last;
	else
		return first;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int n,m,w,i,j,k,l;

	sd(n);	sd(m);	sd(w);

	for(i=1;i<=n;i++)
		sd(A[i]);

	printf("%d\n", binary(n,m,w) );
		
	return 0;
}