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

int A[100007];
int Pos[100007];

int main()
{
	int i,j,k,N,M;
	ll L=0,R=0;

	sd(N);

	for(i=1;i<=N;i++)
	{
		sd(A[i]);
		Pos[ A[i] ] = i;
	}

	sd(M);

	while(M--)
	{
		sd(k);
		L+= Pos[k];
		R+= N-Pos[k]+1;
	}

	cout<<L<<" "<<R<<endl;

	return 0;
}