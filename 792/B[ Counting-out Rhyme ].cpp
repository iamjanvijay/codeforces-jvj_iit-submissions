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

int A[107];
int B[107];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);
	int i,j,k,l,m,n;

	sd(n);	sd(k);

	for(i=0;i<k;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
		B[i] = i;

	i = 0;
	j = 0;
	while(i<k)
	{
		m = (j + A[i]) % n;
		printf("%d ", B[m]+1 );
		if(m!=n-1)
		{
			j = m;
			for(m;m+1<n;m++)
				B[m] = B[m+1];
		}
		else
			j = 0;
		n--;
		i++;
	}

	printf("\n");	
	return 0;
}