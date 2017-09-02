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

int B[100007];
int P[100007];

bool chk(int n,int a)
{
	if(n==0)
		return true;

	int i;ll j=0;
	for(i=0;i<n;i++)
	{
		if(B[i]>=P[n-1-i])
			continue;
		j += (P[n-1-i]-B[i]);
	}

	if(j<=a)
		return true;
	return false;
}

int ans(int n,int a)
{
	if(n==0)
		return 0;
	int i,j=0,k;	
	for(i=0;i<n;i++)
	{
		if(B[i]>=P[n-1-i])
			j+=P[n-1-i];
		else
		{
			j+=B[i];
			a-=(P[n-1-i]-B[i]);
		}	
	}

	return max(0,j-a);

}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,a,r,s,first,last,mid;

	sd(n);	sd(m);	sd(a);

	for(i=0;i<n;i++)
		sd(B[i]);

	for(i=0;i<m;i++)
		sd(P[i]);

	sort(B,B+n,greater<int>());
	sort(P,P+m);

	first=0;last=min(n,m);

	while(first+1<last)
	{
		mid = (first+last)/2;
		if(chk(mid,a))
			first = mid;
		else
			last = mid;
	} 

	if(chk(last,a))
		r = last;
	else
		r = first;

	s = ans(r,a);

	printf("%d %d\n", r , s );

	return 0;
}