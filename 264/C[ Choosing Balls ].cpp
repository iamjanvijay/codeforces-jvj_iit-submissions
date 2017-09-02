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

ll V[100007] = {0};
ll C[100007] = {0};
ll A[100007] = {0};

int main()
{
	ll i,j,N,a,temp,b,ans,Q,max1,col1,max2,col2;
	slld(N); slld(Q);

	for(i=0;i<N;i++)
		slld(V[i]);

	for(i=0;i<N;i++)
		slld(C[i]);

	while(Q--)
	{
		for(i=0;i<N;i++)
		{
			A[ C[i] ] = LLONG_MIN;
		}
		col1 = -1; col2 = -1;
		max1 = 0; max2 = 0; 
		ans = LLONG_MIN;

		slld(a); slld(b);

		for(i=0;i<N;i++)
		{
			temp = b * V[i];

			if(  A[ C[i] ] != LLONG_MIN  )
			{
				temp = max( A[ C[i] ] + a * V[i] , temp );
			}

			if(col1 != -1 && col1 != C[i])
			{
				temp = max( max1 + b * V[i] , temp );
			}

			else if(col2 != -1 && col2 != C[i])
			{
				temp = max( max2 + b * V[i] , temp );
			}

			ans = max(ans, temp);
			A[ C[i] ] = max(A[ C[i] ],temp);

			if(col1==-1)
			{
				col1 = C[i]; max1 = temp;  
			}
			else 
			{
				if(max1 <= temp)
				{
					if(C[i]==col1)
					{
						max1 = temp;
					}
					else
					{
						col2 = col1;	max2 = max1;
						col1 = C[i]; 	max1 = temp;  	
					}
				}
				else if( C[i]!=col1 && (col2==-1 || (max2 < temp )) )
				{
					col2 = C[i]; 	max2 = temp; 
				}
			}
			// printf("Col1 %lld Max1 %lld\nCol2 %lld Max2 %lld\n", col1,max1,col2,max2);	

		}

		printf("%lld\n", max(0LL,ans));	


	}	

	return 0;
}
