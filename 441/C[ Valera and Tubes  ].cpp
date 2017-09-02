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
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l=0,cur=1,m,n;

	sd(n);	sd(m);	sd(k);

	for(i=0;i<n;i++)
	{
		if(i%2 == 0)
			for(j=0;j<m;j++)
			{
				if(l==0)
				{
					if(cur!=k)
						printf("2 ");
					else 
						printf("%d ", n*m - 2*(k-1) );	
				}

				printf("%d %d ", i+1, j+1 );
				l++;

				if(cur<k && l==2)
				{
					printf("\n");
					cur++;
					l = 0;
				}

			}
		else	
			for(j=m-1;j>=0;j--)
			{
				if(l==0)
				{
					if(cur!=k)
						printf("2 ");
					else 
						printf("%d ", n*m - 2*(k-1) );	
				}		

				printf("%d %d ", i+1, j+1 );
				l++;

				if(cur<k && l==2)
				{
					printf("\n");
					cur++;
					l = 0;
				}
					
			}			
	}	
	printf("\n");
	return 0;
}