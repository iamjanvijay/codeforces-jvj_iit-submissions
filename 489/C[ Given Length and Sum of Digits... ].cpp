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

char SLargest[107];
char SSmallest[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,s;

	sd(m);	sd(s);

	if(s==0 && m==1)
	{
		strcpy(SLargest,"0");
	}
	else if(s>9*m || (s==0 && m>1))
	{
		strcpy(SLargest,"-1");
	}	
	else
	{
		for(j=s,i=0;i<m;i++)
		{
			if(j>=9)
			{
				SLargest[i] = &#39;9&#39;;
				j-=9;
			}
			else
			{
				SLargest[i] = &#39;0&#39;+j;
				j-=j;
			}	
		}
		SLargest[i] = &#39;\0&#39;;
	}

	if(s==0 && m==1)
	{
		strcpy(SSmallest,"0");
	}
	else if(s>9*m || (s==0 && m>1))
	{
		strcpy(SSmallest,"-1");
	}
	else
	{
		for(i=1;i<=9;i++)
			if(i+9*(m-1)>=s)
				break;

		j=s;	
		SSmallest[0] = &#39;0&#39;+i;	j-=i;
		
		for(i=m-1;i>=1;i--)
		{
			if(j>=9)
			{
				SSmallest[i] = &#39;9&#39;;
				j-=9;
			}
			else
			{
				SSmallest[i] = &#39;0&#39;+j;
				j-=j;
			}	
		}
		SSmallest[m] = &#39;\0&#39;;
	}

	printf("%s %s\n", SSmallest,SLargest );
	
	return 0;
}