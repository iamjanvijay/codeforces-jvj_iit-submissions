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

int Occ[87];
int A[87];
set<int> St;
set<int>::iterator it;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans = 0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<n;i++)
	{
		if(St.empty())
		{
			St.insert(A[i]);
			ans++;
		}
		else if( St.count(A[i])==0 && St.size()<k )
		{
			St.insert(A[i]);
			ans++;
		}
		else if( St.count(A[i])==0 && St.size()==k )
		{
			for(j=1;j<=n;j++)
				Occ[j] = INT_MAX;

			for(j=i+1;j<n;j++)
			{
				Occ[ A[j] ] = min(Occ[ A[j] ],j);
			}	

			a = -1;

			for(it=St.begin();it!=St.end();++it)
			{
				if(Occ[*it]>a)
				{
					a = Occ[*it];
					b = *it;
				}
			}

			St.erase(b);
			St.insert(A[i]);
			ans++;
		}

	}  

	printf("%d\n", ans );
	
	return 0;
}