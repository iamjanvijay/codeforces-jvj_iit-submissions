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

int RMQ[100007][18][7];
int pow2[100007];

void init()
{
	int i;
	pow2[1] = 0;
	for(i=2;i<=100000;i++)
	{
		if( (1<<(pow2[i-1]+1)) <= i )
			pow2[i] = pow2[i-1]+1;
		else
			pow2[i] = pow2[i-1];
		// if(i<=20)
		// 	printf("%d\n", pow2[i] );
	}
}

void createRMQ(int x,int n,int m)
{
	int i,j;
	for(i=1;(1<<i)<=n;i++)
	{
		for(j=0;(j+(1<<i))-1<n;j++)
		{
			RMQ[j][i][x] = max( RMQ[j][i-1][x],RMQ[j+(1<<(i-1))][i-1][x] );
		}
	}
}

int maxQuery(int x,int l,int r)
{
	int z = r-l+1;
	if(z==0)
		return 0;
	return max( RMQ[l][pow2[z]][x], RMQ[r-(1<<pow2[z])+1][pow2[z]][x] );
}

bool chk(int l,int r,int k,int m)
{
	if(r-l+1==0)
		return true;
	int i;ll z = 0;

	for(i=0;i<m;i++)
	{
		z+=maxQuery(i,l,r);
	}

	if(z<=k)
		return true;
	return false;
}

int binary(int n,int m,int k)
{
	int first = 0,last = n,mid,i;
	bool flag;
	while(first+1<last)
	{
		mid = (first+last)/2;
		flag = false;
		for(i=0;i+mid-1<n;i++)
		{
			if(chk(i,i+mid-1,k,m))
			{
				flag = true;
				break;
			}
		}

		if(flag)
			first = mid;
		else
			last = mid;

	}

	mid = last;
	flag = false;
	for(i=0;i+mid-1<n;i++)
	{
		if(chk(i,i+mid-1,k,m))
		{
			flag = true;
			break;
		}
	}

	if(flag)
		return last;
	return first;

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,n,m,ans;
	init();
	sd(n);	sd(m);	sd(k);

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			sd(RMQ[i][0][j]);
		}
	}

	for(i=0;i<m;i++)
	{
		createRMQ(i,n,m);
	}

	ans = binary(n,m,k);

	for(i=0;i+ans-1<n;i++)
	{
		if(chk(i,i+ans-1,k,m))
		{
			for(j=0;j<m;j++)
			{
				printf("%d ", maxQuery(j,i,i+ans-1) );
			}
			printf("\n");
			return 0;
		}
	}
	
	return 0;
}