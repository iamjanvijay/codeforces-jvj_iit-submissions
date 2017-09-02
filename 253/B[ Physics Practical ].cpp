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

bool chk(int n,int k)
{
	int i,j;

	for(i=0,j=n-1-k;j<n;i++,j++)
	{
		if(A[j] <= 2*A[i])
			return true;
	}
	return false;	
}

int main()
{

	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);
		
	sort(A,A+n);
	
	int first = 0, last = n-1, mid;

	while( first+1 < last )
	{
		mid = (first+last)/2;

		if(chk(n,mid))
			last = mid;
		else
			first = mid;

	}

	if(chk(n,first))
		printf("%d\n", first );	
	else
		printf("%d\n", last );	
	return 0;
}