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


set< pair<int,int> > St; 
set< pair<int,int> >::iterator it;
int A[400007][2];
int Occ[400007];
pair<int,int> temp;

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a=0,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(k);

	for(i=0;i<n;i++)
		sd(A[i][0]);

	for(i=0;i<400007;i++)
		Occ[i] = n;

	for(i=n-1;i>=0;i--)
	{
		A[i][1] = Occ[ A[i][0] ];
		Occ[ A[i][0] ] = i;
		// printf("%d ", A[i][1] );
	}
	// printf("\n");

	for(i=0;i<400007;i++)
		Occ[i] = -1;

	for(i=0;i<n;i++)
	{
		if(Occ[A[i][0]]!=-1)
		{
			St.erase( mp(Occ[A[i][0]],A[i][0]) );
			St.insert( mp(A[i][1],A[i][0]) );
			Occ[A[i][0]] = A[i][1];
		}
		else if(St.size()<k && Occ[A[i][0]]==-1)
		{
			St.insert( mp(A[i][1],A[i][0]) );
			Occ[ A[i][0] ] = A[i][1];
			a++;
		}
		else
		{
			if(Occ[A[i][0]]==-1)
			{
				it = St.end();	it--;
				temp = *it;

				St.erase(temp);
				Occ[temp.S] = -1;

				St.insert(mp(A[i][1],A[i][0]));
				Occ[ A[i][0] ] = A[i][1];
				a++;
			}

		}
	}

	printf("%d\n", a );

	return 0;
}