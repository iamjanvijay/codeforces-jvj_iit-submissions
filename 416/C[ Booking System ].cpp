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

vector< pair< pair<int,int> ,int > > Orders;
int Table[1007];
bool isBooked[1007];

vector< pair<int,int> > Fans;

int main()
{
	int i,j,k,l,m,n,ans=0,anscount=0;

	sd(m);

	for(i=0;i<m;i++)
	{
		sd(j);	sd(k);
		Orders.push_back( make_pair( make_pair(k,j) , i+1 ) );
	}

	sort(Orders.begin(), Orders.end());

	sd(n);

	for(i=0;i<n;i++)
		sd(Table[i]);

	for(i=m-1;i>=0;i--)
	{
		k = INT_MAX;
		l = -1;
		for(j=0;j<n;j++)
		{
			if(!isBooked[j] && Table[j] >= Orders[i].first.second)
			{
				if(k > Table[j])
				{
					k = Table[j];
					l = j;
				}
			}	

		}
		if(l!=-1)
		{
			anscount++;
			ans += Orders[i].first.first;
			// printf("\n* %d %d\n", ans , l );
			isBooked[l] = true;
			Fans.push_back( make_pair(Orders[i].second , l+1) );
		}	
	}

	printf("%d %d\n",anscount,ans);

	sort(Fans.begin(),Fans.end());

	for(i=0;i < Fans.size() ; i++ )
	{
		printf("%d %d\n", Fans[i].first , Fans[i].second );
	}	


	return 0;
}
