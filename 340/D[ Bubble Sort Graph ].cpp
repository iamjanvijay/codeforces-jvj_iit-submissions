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
vector<int> V;
vector<int>::iterator it;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n;

	sd(n);

	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
	{
		if(V.empty() || V[V.size()-1] < A[i])
			V.push_back(A[i]);
		else
		{
			it = lower_bound(V.begin(),V.end(),A[i]);
			*it = A[i];
		}
	}	

	printf("%d\n", V.size() );
	
	return 0;
}