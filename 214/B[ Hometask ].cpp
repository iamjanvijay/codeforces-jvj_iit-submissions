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

int A[10];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(k);
		A[k]++;
	}


	if(A[0]==0)
	{
		printf("-1\n");
		return 0;
	}

	for(i=0;i<10;i++)
		m = (m+i*A[i])%3;

	if(m%3==0)
	{
	bool flag = false;
	for(i=9;i>=0;i--)
	{
		if(i!=0 && A[i]>0)
			flag=true;
		if(!flag && i==0)
			printf("0");
		else
		while(A[i]--)
		{
			printf("%d", i );
		}
	}
	printf("\n");
		return 0;
	}

	if(m%3==1)
	{
		if(A[1]+A[4]+A[7]>=1)
		{
			if(A[1])
				A[1]--;
			else if(A[4])
				A[4]--;
			else
				A[7]--;
		}
		else if(A[2]+A[5]+A[8]>=2)
		{
			k = 2;
			while(A[2]>0 && k>0)
			{
				A[2]--;	k--;
			}
			while(A[5]>0 && k>0)
			{
				A[5]--;	k--;
			}
			while(A[8]>0 && k>0)
			{
				A[8]--;	k--;
			}						
		}

	bool flag = false;
	for(i=9;i>=0;i--)
	{
		if(i!=0 && A[i]>0)
			flag=true;
		if(!flag && i==0)
			printf("0");
		else
		while(A[i]--)
		{
			printf("%d", i );
		}
	}
	printf("\n");
		return 0;

	}

	if(A[2]+A[5]+A[8]>=1)
	{
		if(A[2])
			A[2]--;
		else if(A[5])
			A[5]--;
		else
			A[8]--;
	}	
	else if(A[1]+A[4]+A[7]>=2)
	{
		k = 2;
		while(A[1]>0 && k>0)
		{
			A[1]--;	k--;
		}
		while(A[4]>0 && k>0)
		{
			A[4]--;	k--;
		}
		while(A[7]>0 && k>0)
		{
			A[7]--;	k--;
		}						
	}

	bool flag = false;
	for(i=9;i>=0;i--)
	{
		if(i!=0 && A[i]>0)
			flag=true;
		if(!flag && i==0)
			printf("0");
		else
		while(A[i]--)
		{
			printf("%d", i );
		}
	}
	printf("\n");
	
	return 0;
}