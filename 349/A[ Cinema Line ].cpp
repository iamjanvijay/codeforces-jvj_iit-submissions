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

int C[3]={0}; // 25 50 100

int main()
{
	int i,j,k,l,n;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(k);
		if(k==25)
		{
			C[0]++;
		}
		else if(k==50)
		{
			if(C[0]==0)
				break;
			else
			{
				C[0]--;
				C[1]++;
			}
		}
		else
		{
			if(C[0]!=0 && C[1]!=0)
			{
				C[0]--;	C[1]--;
			}
			else if(C[0]>=3)
			{
				C[0]-=3;
			}
			else
			{
				break;
			}	
		}	
	}

	if(i<n)
		printf("NO\n");
	else
		printf("YES\n");		

	return 0;
}
