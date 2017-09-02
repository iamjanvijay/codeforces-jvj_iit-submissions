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
int H[107];
int X[107];
int Y[107];
int m;

int Find(int u)
{
	if(A[u]==u)
		return u;
	int x = Find(A[u]);
	A[u] = x;
	return x;
}

bool Union(int u,int v)
{
	int Pu = Find(u), Pv = Find(v);
	if(Pu==Pv)
		return false;
	if(H[Pu]>H[Pv])
		A[Pv] = Pu;
	else if(H[Pu]<H[Pv])
		A[Pu] = Pv;
	else
	{
		A[Pu] = Pv;
		H[Pv]++;
	}
}

int main()
{
	int i,j,k,l,n;

	sd(n);
	for(i=0;i<n;i++)
	{
		sd(X[i]);	sd(Y[i]);
	}
	m=n;

	for(i=1;i<=n;i++)
	{
		A[i] = i;
		H[i] = 1;
	}

	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if( (X[i]==X[j]) || (Y[i]==Y[j]) )
			{
				if(Union(i+1,j+1))
					m--;
			}
		}	
	}	

	printf("%d\n", m-1 );

	return 0;
}
