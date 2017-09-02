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


vector< int > V1;
vector< int > V2;

bool chk(int k)
{
	int i,j;
	for(i=0;i<V2.size();i++)
	{
		j = k-2*i;
		if(j<0 || j>=V1.size())
			continue;
		if( i*2+j >= V2[V2.size()-1-i] + V1[V1.size()-1-j] )
			return true;
	}
	return false;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l=0,t,w,m=0,n,first,last,mid;

	sd(n);
	V1.push_back(0);	V2.push_back(0);
	for(i=0;i<n;i++)
	{
		sd(t);	sd(w);
		m+=t;
		if(t==1)
			V1.push_back(w);
		else
			V2.push_back(w);
	}

	sort(V1.begin(), V1.end());
	sort(V2.begin(), V2.end());

	for(i=1;i<V2.size();i++)
		V2[i] += V2[i-1];

	for(i=1;i<V1.size();i++)
		V1[i] += V1[i-1];	

	first = 1;last = m;
	while(first+1<last)
	{
		mid = (first+last)/2;
	
		if( chk(mid) )
			last = mid;
		else
			first = mid;

	}

	if(chk(first))
		printf("%d\n", first );	
	else
		printf("%d\n", last );	

	return 0;
}