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

map<string,int> M;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	string S;
	int i,j,k,l,m,n,ans=0;

	M["Tetrahedron"] = 4;
	M["Cube"] = 6;
	M["Octahedron"] = 8;
	M["Dodecahedron"] = 12;
	M["Icosahedron"] = 20;

	sd(n);

	for(i=0;i<n;i++)
	{
		cin >> S;
		ans += M[S];
	}

	printf("%d\n", ans );

	return 0;
}