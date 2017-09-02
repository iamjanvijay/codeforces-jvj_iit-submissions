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

int ceil(int n,int x) // x/n
{
	if(n%x==0)
		return n/x;
	return n/x+1;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l=0,m,n;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
	{
		sd(m);
		l+=ceil(m,k);
	}

	printf("%d\n", ceil(l,2) );
	
	return 0;
}