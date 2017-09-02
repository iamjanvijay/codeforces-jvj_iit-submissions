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

char S[107][107];
bool isDeleted[107];

int main()
{
	int i,j,k,l=0,prl=-1,m,n;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
	{
		ss(S[i]);
	}


	while(prl!=l)
	{
		prl = l;	
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<m;j++)
			{
				if( !isDeleted[j] )
				{
					if(S[i][j] < S[i+1][j])
						break;
					if(S[i][j] > S[i+1][j])
					{
						isDeleted[j] = true;
						l++;
					}
				}	
			}	
		}
	}

	printf("%d\n", l );	

	return 0;
}
