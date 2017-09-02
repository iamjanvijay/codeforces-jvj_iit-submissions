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

int Treasures[30007];
int DP[30007][502];
int off;

int DPCalc(int cur,int prevLen)
{
	if(cur>30000)
		return 0;

	if(DP[cur][prevLen+off]==0)
	{
		if(prevLen==1)
		{
			DP[cur][prevLen+off] = Treasures[cur] + max(DPCalc(cur+prevLen,prevLen),DPCalc(cur+prevLen+1,prevLen+1));
		}
		else
		{
			DP[cur][prevLen+off] = Treasures[cur] + max(DPCalc(cur+prevLen-1,prevLen-1), max(DPCalc(cur+prevLen,prevLen), DPCalc(cur+prevLen+1,prevLen+1)));
		}

		if(DP[cur][prevLen+off]==0)
			DP[cur][prevLen+off] = INT_MIN;
	}

	if( DP[cur][prevLen+off] == INT_MIN )
		return 0;
	return 	DP[cur][prevLen+off];	
}

int main()
{
	int i,j,k,l,m,n,d;

	sd(n);	sd(d);

	off = -d+250;

	for(i=0;i<n;i++)
	{
		sd(k);
		Treasures[k]++;
	}

	printf("%d\n", DPCalc(d,d) );	

	return 0;
}
