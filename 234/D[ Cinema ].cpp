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

bool isFav[107];
bool atleastAllPresent;
bool allPresent[107];
char s[17];
vector< pair<int, int> > V; 

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,f,d,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(m);	sd(k);

	for(i=0;i<k;i++)
	{
		sd(a);	isFav[a] = true;
	}

	sd(n);


	x = 0;
	while(x<n)
	{
		ss(s);		sd(d);

		for(f=0,z=0,i=0;i<d;i++)
		{
			sd(b);
			if(b==0)
				z++;
			if(b!=0 && isFav[b])
				f++;
		}

		if(d==m || f==k)
		{
			atleastAllPresent = allPresent[x] = true;
		}

		V.pb( mp(f + max(0,k+d-m-f), min(k,z+f)) );
		x++;
	}

	// for(i=0;i<n;i++)
	// {
	// 	printf("Case : %d\n", i+1 );
	// 	printf("%d %d\n", V[i].F, V[i].S );
	// }

	// printf("--------------------\n");
	bool lose,win;
	if(atleastAllPresent)
	{	
		for(i=0;i<n;i++)
			{
				if(allPresent[i])
					printf("0\n");
				else
				{
					if(V[i].S<k)
						printf("1\n");
					else
						printf("2\n");
				}
			}
	}
	else
	{	
		for(i=0;i<n;i++)
		{
			for(lose=false,win=true,j=0;j<n;j++)
			{
				if(i==j)
					continue;
				if( V[i].S < V[j].F )
					lose = true;
				if( V[i].F < V[j].S )
					win = false;
			}
			if(lose)
				printf("1\n");
			else if(win)
				printf("0\n");
			else
				printf("2\n");
		}	
	}
	
	return 0;
}

