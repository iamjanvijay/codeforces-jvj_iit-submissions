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

char St[207][207];
char col[3];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r;
	char c;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<n;i++)
		ss(St[i]);

	bool flag = false;

	if( n%3==0 )
	{
		bool flag1 = true;
		for(i=0;i<(n/3*1);i++)
		{
			for(j=0;j<m;j++)
			{
				if( i==0 && j==0 )
					c = St[i][j];
				else
				{
					if(c!=St[i][j])
						flag1 = false;
				}
			}
		}
		col[0] = c;

		for(i;i<(n/3*2);i++)
		{
			for(j=0;j<m;j++)
			{
				if( i==(n/3*1) && j==0 )
					c = St[i][j];
				else
				{
					if(c!=St[i][j])
						flag1 = false;
				}
			}
		}
		col[1] = c;

		for(i;i<(n);i++)
		{
			for(j=0;j<m;j++)
			{
				if( i==(n/3*2) && j==0 )
					c = St[i][j];
				else
				{
					if(c!=St[i][j])
						flag1 = false;
				}
			}
		}
		col[2] = c;
		// printf("HELLO\n");
		// printf("%c %c %c\n", col[0], col[1], col[2] );

		if( flag1 && ( (col[0]==&#39;R&#39; && col[1]==&#39;G&#39; && col[2]==&#39;B&#39;) || (col[0]==&#39;R&#39; && col[1]==&#39;B&#39; && col[2]==&#39;G&#39;) || (col[0]==&#39;G&#39; && col[1]==&#39;R&#39; && col[2]==&#39;B&#39;) || (col[0]==&#39;G&#39; && col[1]==&#39;B&#39; && col[2]==&#39;R&#39;) || (col[0]==&#39;B&#39; && col[1]==&#39;G&#39; && col[2]==&#39;R&#39;) || (col[0]==&#39;B&#39; && col[1]==&#39;R&#39; && col[2]==&#39;G&#39;) ) )
			flag = true;
	}

	if( m%3 == 0 )
	{
		bool flag1 = true;
		for(j=0;j<(m/3*1);j++)
		{
			for(i=0;i<n;i++)
			{
				if( i==0 && j==0 )
					c = St[i][j];
				else
				{
					// printf("Hey1\n");
					if(c!=St[i][j])
						flag1 = false;
				}
			}
		}
		col[0] = c;

		for(j;j<(m/3*2);j++)
		{
			for(i=0;i<n;i++)
			{
				if( j==(m/3*1) && i==0 )
					c = St[i][j];
				else
				{
					// printf("Hey2\n");
					if(c!=St[i][j])
						flag1 = false;
				}
			}
		}
		col[1] = c;

		for(j;j<(m);j++)
		{
			for(i=0;i<n;i++)
			{
				if( j==(m/3*2) && i==0 )
					c = St[i][j];
				else
				{
					// printf("Hey3\n");
					if(c!=St[i][j])
						flag1 = false;
				}
			}
		}
		col[2] = c;

		// printf("%c %c %c\n", col[0], col[1], col[2] );
		// if(flag1)
		// 		printf("Hey\n");

		if( flag1 && ( (col[0]==&#39;R&#39; && col[1]==&#39;G&#39; && col[2]==&#39;B&#39;) || (col[0]==&#39;R&#39; && col[1]==&#39;B&#39; && col[2]==&#39;G&#39;) || (col[0]==&#39;G&#39; && col[1]==&#39;R&#39; && col[2]==&#39;B&#39;) || (col[0]==&#39;G&#39; && col[1]==&#39;B&#39; && col[2]==&#39;R&#39;) || (col[0]==&#39;B&#39; && col[1]==&#39;G&#39; && col[2]==&#39;R&#39;) || (col[0]==&#39;B&#39; && col[1]==&#39;R&#39; && col[2]==&#39;G&#39;) ) )
			flag = true;		
	}

	if(flag)
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}