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

int C[107]={0};
int temp[107] = {0};

int main()
{
	int i,j,k,l,n,ans=0;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(C[i]);
	}

	sort(C,C+n);	

	k = n;

	while(k!=0)
	{
		l = 0;
		j = 0;
		ans++;
		for(i=0;i<k;i++)
		{
			if(l<=C[i])
			{
				l++;
			}
			else
			{
				temp[j++] = C[i];
			}	
		}
		k -= l;
		for(i=0;i<k;i++)
		{
			C[i] = temp[i];
		}	
	}	

	printf("%d\n", ans );

	return 0;
}
