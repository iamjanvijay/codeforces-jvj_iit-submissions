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

int a[100007];
int IncInd[100007];
int DecInd[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,r,m,n;

	sd(n);	sd(m);
	for(i=0;i<n;i++)
		sd(a[i]);

	i=0;j=0;

	while(i<n)
	{
		j=i;
		while(j<n && a[j]<=a[j+1])
			j++;
		if(j==n)
			j--;		
		for(l=i;l<=j;l++)
			IncInd[l] = j;
		i=j+1;
	}

	i=0;j=0;

	while(i<n)
	{
		j=i;
		while(j<n && a[j]>=a[j+1])
			j++;
		if(j==n)
			j--;
		for(l=i;l<=j;l++)
			DecInd[l] = j;
		i=j+1;
	}

	while(m--)
	{
		sd(l);	sd(r);
		l--;	r--;
		k = DecInd[ IncInd[l] ];
		// printf("*** %d %d : %d\n",l,r,k );
		if(r<=k)
			printf("Yes\n");
		else
			printf("No\n");
	}	
	
	return 0;
}