#include <bits/stdc++.h>
using namespace std;

#define sd(x) 		scanf("%d",&x)
#define su(x) 		scanf("%u",&x)
#define slld(x) 	scanf("%lld",&x)
#define sc(x) 		scanf("%c",&x)
#define ss(x) 		scanf("%s",x)
#define sf(x) 		scanf("%f",&x)
#define slf(x)		scanf("%lf",&x)
#define ll 			long long int
#define mod(x,n) 	(x+n)%n
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define Mod         1000000007

int A[1007];
int B[1007];
int C[1007];
bool isEx[1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=0;i<n;i++)
	{
		sd(A[i]);
	}

	for(i=0;i<n;i++)
	{
		sd(B[i]);
	}

	m = 0;
	for(i=0;i<n;i++)
	{
		if(A[i]!=B[i])
			m++;
	}

	if(m==1)
	{
		for(i=0;i<n;i++)
		{
			if(A[i]==B[i])
			{
				isEx[A[i]] = true;
				C[i] = A[i];
			}
			else
				k = i;
		}

		for(i=1;i<=n;i++)
		{
			if(!isEx[i])
				C[k] = i;
		}

	}
	else if(m==2)
	{
		k = l = -1;

		for(i=0;i<n;i++)
		{
			if(A[i]==B[i])
			{
				isEx[A[i]] = true;
				C[i] = A[i];
			}
			else
			{
				if(k==-1)
					k = i;
				else
					l = i;
			}
		}

		if( !isEx[ A[k] ]  && !isEx[ B[l] ] && A[k]!=B[l] )
		{
			C[k] = A[k];	C[l] = B[l];
		}
		else
		{
			C[k] = B[k];	C[l] = A[l];
		}

	}
	else
		return 0;

	for(i=0;i<n;i++)
		printf("%d ", C[i] );
	printf("\n");

	return 0;
}