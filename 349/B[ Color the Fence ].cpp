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
int ANS[10];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,v;
	bool flag = true;

	sd(v);

	for(i=1;i<=9;i++)
		sd(A[i]);

	k = A[1];
	j = 1;
	
	for(i=1;i<=9;i++)
	{
		if( (k > A[i]) || (k==A[i] && i>j) )
		{
			k = A[i];
			j = i;
		}	
	}


	for(i=1;i<=9;i++)
		A[i] -= k;

	ANS[j] = v/k;

	v%=k;

	// printf("A\n");
	// for(i=1;i<=9;i++)
	// 	printf("(%d)%d ",i,A[i] );
	// printf("\n");

	// printf("ANS\n");
	// for(i=1;i<=9;i++)
	// 	printf("(%d)%d ",i,ANS[i] );
	// printf("\n");

	// printf("v = %d\n", v );	

	for(i=9;i>j;i--)
	{
		while(v >= A[i])
		{
			v -= A[i];
			ANS[i]++;
			ANS[j]--;
		}	
	}

	for(i=9;i>=1;i--)
	{
		while( ANS[i]-- )
		{
			printf("%d", i);
			flag = false;
		}
	}	

	if(flag)
		printf("-1");

	printf("\n");
	
	return 0;
}