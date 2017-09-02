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

int A[100007];	int B[100007];	int C[100007];

// bool chk(int k,int n)
// {

// }

// int binary(int n)
// {
// 	int first=1, last=n, mid;

// 	while(first+1<last)
// 	{
// 		mid = (first+last)/2;
// 		if( chk(mid,n) )
// 			first = mid;
// 		else
// 			last = mid;
// 	}

// 	if(chk(last,n))
// 		return last;
// 	else
// 		return first;
// }

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);
	for(i=1;i<=n;i++)
		sd(A[i]);

	if(n==1)
		l = 1;
	else
		l = 2;

	B[1]=1;
	for(i=2;i<=n;i++)
	{
		if(A[i-1]<A[i])
			B[i]=1+B[i-1];
		else
			B[i]=1;
	}


	i = n;
	while(i>=1)
	{
		j=i;	k=B[j];
		while(B[j]!=1)
		{
			C[j]=k;	j--;
		}
		C[j]=k;		i=j-1;
	}

	bool flag=false;
	for(i=2;i<=n;i++)
		if(C[i]!=C[i-1] || C[i]==1)
			flag=true;

	if(flag)
		for(i=1;i<=n;i++)
			l = max(l,C[i]+1);	
	else
		l = C[n];	

	for(i=2;i<=n;i++)
	{
		if(B[i]==1)
		{
			if(i-1>=1 && i+1<=n)
			{
				if( C[i]!=1 && A[i-1]+1<A[i+1] )
					l = max(l,C[i-1]+C[i]);
				else 
					l = max(l,C[i-1]+1);
			}

			if(i-2>=1 && i<=n)
			{
				if( C[i-1]!=1 && A[i-2]+1<A[i] )
					l = max(l,C[i]+C[i-1]);
				else 
					l = max(l,C[i]+1);
			}

		}
	}

	// for(i=1;i<=n;i++)
	// 	printf("%d ", C[i] );
	// printf("%d\n", binary(n) );

	printf("%d\n", min(n,l) );
	
	return 0;
}