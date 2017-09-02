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


int main()
{
	int i,j,k,l,m=0,n,a,b,c,ans=0;

	sd(n);	sd(a);	sd(b);	sd(c);

	if(n%a==0)
		ans = max(ans,n/a);
	if(n%b==0)
		ans = max(ans,n/b);
	if(n%c==0)
		ans = max(ans,n/c);

	for(i=1;i<=4000;i++)
	{
		j = n-a*i;
		if(j<=0)
			break;		
		if(j%b==0)
			ans = max(ans,i + j/b);
	}

	for(i=1;i<=4000;i++)
	{
		j = n-a*i;
		if(j<=0)
			break;		
		if(j%c==0)
			ans = max(ans,i + j/c);
	}

	for(i=1;i<=4000;i++)
	{
		j = n-c*i;
		if(j<=0)
			break;
		if(j%b==0)
			ans = max(ans,i + j/b);
	}

	for(i=1;i<=4000;i++)
	{
		k = n-a*i;
		if(k<=0)
			break;
		for(j=1;j<=4000;j++)
		{
			l = k-b*j;
			if(l<=0)
				break;
			if(l%c==0)
				ans = max(ans,i+j+l/c);
		}	
	}

	for(i=1;i<=4000;i++)
	{
		k = n-a*i;
		if(k<=0)
			break;
		for(j=1;j<=4000;j++)
		{
			l = k-c*j;
			if(l<=0)
				break;
			if(l%b==0)
				ans = max(ans,i+j+l/b);
		}	
	}

	for(i=1;i<=4000;i++)
	{
		k = n-c*i;
		if(k<=0)
			break;
		for(j=1;j<=4000;j++)
		{
			l = k-b*j;
			if(l<=0)
				break;
			if(l%a==0)
				ans = max(ans,i+j+l/a);
		}	
	}						

	printf("%d\n", ans );

	return 0;
}
