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

int a_C[100007];
int b_C[100007];
int a_AC[100007];
int b_AC[100007];
bool exist[100007] = {false};
int counter = 0;

int DP_C[100007][20][2]; // 0 - min / 1 - final
int DP_AC[100007][20][2]; 

int main()
{
	int i,j,k,l,n,p,mini,final;
	bool flag;
	sd(n);
	
	for(i=0;i<n;i++)
		sd(a_C[i]);
	for(i=0;i<n;i++)
		sd(b_C[i]);

	for(i=0;i<n;i++)
		a_AC[n-1-i] = a_C[i];
	for(i=0;i<n;i++)
		b_AC[i] = b_C[mod(n-2-i,n)];

	for(i=0;i<n;i++)
	{
		DP_C[i][0][0] = DP_C[i][0][1] = a_C[i] - b_C[i];
	}	
	
	for(i=0;i<n;i++)
	{
		DP_AC[i][0][0] = DP_AC[i][0][1] = a_AC[i] - b_AC[i];
	}

	j = n;
	k = 0;
	while(j!=0)
	{
		k++;
		j = j>>1;
	}
	// printf("%d\n",k);

	for(i=1;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			DP_C[j][i][0] = min(DP_C[j][i-1][0], DP_C[j][i-1][1] + DP_C[(j+(1<<(i-1)))%n][i-1][0]);
			DP_C[j][i][1] = DP_C[j][i-1][1] + DP_C[(j+(1<<(i-1)))%n][i-1][1];
		}
	}

	for(i=1;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			DP_AC[j][i][0] = min(DP_AC[j][i-1][0], DP_AC[j][i-1][1] + DP_AC[(j+(1<<(i-1)))%n][i-1][0]);
			DP_AC[j][i][1] = DP_AC[j][i-1][1] + DP_AC[(j+(1<<(i-1)))%n][i-1][1];
		}
	}	

	// for(i=0;i<k;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 	{
	// 		printf("(%d %d) ",DP_C[j][i][0],DP_C[j][i][1]);
	// 	}
	// 	printf("\n");
	// }

	for(j=0;j<n;j++)
	{
		mini = INT_MAX; final = 0;
		l = k-1;	flag = true;
		p = j;

		while(l>=0)
		{
			if( ((1<<l)&n) != 0 )
			{
				mini = min(mini,final+DP_C[p][l][0]);
				final = final + DP_C[p][l][1];
				p = (p+(1<<(l)))%n;
			}
			l--;
			if(mini<0)
			{
				flag = false;	break;
			}	
		}

		if(exist[j]==false && flag == true)
		{
			exist[j] = true;
			counter++;
		}	

	}	

	for(j=0;j<n;j++)
	{
		mini = INT_MAX; final = 0;
		l = k-1;	flag = true;
		p = j;

		while(l>=0)
		{
			if( ((1<<l)&n) != 0 )
			{
				mini = min(mini,final+DP_AC[p][l][0]);
				final = final + DP_AC[p][l][1];
				p = (p+(1<<(l)))%n;
			}
			l--;
			if(mini<0)
			{
				flag = false;	break;
			}	
		}

		if(exist[n-1-j]==false && flag == true)
		{
			exist[n-1-j] = true;
			counter++;
		}	

	}

	printf("%d\n",counter);
	for(i=0;i<n;i++)
		if(exist[i])
			printf("%d ",i+1 );
	printf("\n");	
	return 0;
}
