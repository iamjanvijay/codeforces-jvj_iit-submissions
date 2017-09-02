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

int A[10000007];
char S[17];
int m;

bool Ans(int j,int w,int l)
{
	// printf("%d %d %d\n",j,w,l );
	if(l==m)
		return true;

	bool flag = false;

	for(int a=1;a<=10;a++)
	{
		if(l%2==0)
		{
			if(S[a]==&#39;1&#39; && a!=j && w-a!=0 && w*(w-a)<=0)
			{
				A[l] = a;
				// printf("%d %d %d\n", a,w-a,l+1 );
				flag |= Ans(a,w-a,l+1);
			}
		}
		else
		{
			if(S[a]==&#39;1&#39; && a!=j && w+a!=0 && w*(w+a)<=0)
			{
				A[l] = a;
				// printf("%d %d %d\n", a,w+a,l+1 );
				flag |= Ans(a,w+a,l+1);
			}
		}
		if(flag)
			return true;				
	}
	return false;	
}

int main()
{
	ss(S+1);

	int i,j,k,l,n;

	sd(m);

	if( Ans(0,0,0) )
	{
		printf("YES\n");
		for(j=0;j<m;j++)
			printf("%d ",A[j]);
		printf("\n");
	}
	else
	{
		printf("NO\n");
	}	

	return 0;
}
