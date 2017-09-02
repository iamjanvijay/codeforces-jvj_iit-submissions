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

int H[500007];

int main()
{
	int n,k,i,j,l,mini,cur;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
		sd(H[i]);

	cur = 0;
	for(i=0;i<k;i++)
	{
		cur+=H[i];
	}

	mini = cur;

	for(i,j=0,l=0;i<n;i++,j++)
	{
		cur += H[i] - H[j];
		if(cur < mini)
		{
			mini = cur;
			l = j+1;
		}
		// mini = min(cur,mini);
	}

	printf("%d\n", l+1 );	

	return 0;
}
