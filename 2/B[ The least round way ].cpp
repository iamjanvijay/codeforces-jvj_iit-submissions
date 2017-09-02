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

int  Count2[1007][1007];
int  Count5[1007][1007];
int  DP2[1007][1007];
int  DP5[1007][1007];
char Way2[1007][1007];
char Way5[1007][1007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,c,r;
	bool aZero = false;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			sd(k);

			if(k==0)
			{
				aZero = true;
				x = i;	y = j;
				Count2[i][j] = Count5[i][j] = INT_MAX;
				continue;
			}

			a = 0;
			while(k%2==0)
			{
				k/=2;	a++;
			}
			Count2[i][j] = a;

			a = 0;
			while(k%5==0)
			{
				k/=5;	a++;
			}
			Count5[i][j] = a;			
		}
	}


	for(i=n;i>=1;i--)
	{
		for(j=n;j>=1;j--)
		{
			if(i==n && j==n)
			{
				DP5[i][j]  = Count5[i][j];
				Way5[i][j] = &#39;\0&#39;;				
				DP2[i][j]  = Count2[i][j];
				Way2[i][j] = &#39;\0&#39;;
			}	
			else if(i==n)
			{
				if(DP5[i][j+1]==INT_MAX || Count5[i][j]==INT_MAX)
					DP5[i][j] = INT_MAX;
				else
					DP5[i][j] = Count5[i][j] + DP5[i][j+1];
				Way5[i][j] = &#39;R&#39;;	

				if(DP2[i][j+1]==INT_MAX || Count2[i][j]==INT_MAX)
					DP2[i][j] = INT_MAX;
				else
					DP2[i][j] = Count2[i][j] + DP2[i][j+1];
				Way2[i][j] = &#39;R&#39;;
			}
			else if(j==n)
			{
				if(DP5[i+1][j]==INT_MAX || Count5[i][j]==INT_MAX)
					DP5[i][j] = INT_MAX;
				else
					DP5[i][j] = Count5[i][j] + DP5[i+1][j];
				Way5[i][j] = &#39;D&#39;;	


				if(DP2[i+1][j]==INT_MAX || Count2[i][j]==INT_MAX)
					DP2[i][j] = INT_MAX;
				else
					DP2[i][j] = Count2[i][j] + DP2[i+1][j];
				Way2[i][j] = &#39;D&#39;;
			}
			else
			{
				if(DP5[i][j+1] < DP5[i+1][j])
				{
					if(Count5[i][j]==INT_MAX)
						DP5[i][j] = INT_MAX;
					else
						DP5[i][j] = Count5[i][j] + DP5[i][j+1];
					Way5[i][j] = &#39;R&#39;;
				}
				else
				{
					if(DP5[i+1][j]==INT_MAX || Count5[i][j]==INT_MAX)
						DP5[i][j] = INT_MAX;
					else
						DP5[i][j] = Count5[i][j] + DP5[i+1][j];
					Way5[i][j] = &#39;D&#39;;	
				}

				if(DP2[i][j+1] < DP2[i+1][j])
				{
					if(Count2[i][j]==INT_MAX)
						DP2[i][j] = INT_MAX;
					else
						DP2[i][j] = Count2[i][j] + DP2[i][j+1];
					Way2[i][j] = &#39;R&#39;;
				}
				else
				{
					if(DP2[i+1][j]==INT_MAX || Count2[i][j]==INT_MAX)
						DP2[i][j] = INT_MAX;
					else
						DP2[i][j] = Count2[i][j] + DP2[i+1][j];
					Way2[i][j] = &#39;D&#39;;
				}
			}
		}
	}

	if(!aZero)
	{
		printf("%d\n", min(DP2[1][1],DP5[1][1]));

		i=j=1;

		if(DP2[1][1]<DP5[1][1])
		{
			while(!(i==n && j==n))
			{
				printf("%c", Way2[i][j] );
				if(Way2[i][j]==&#39;D&#39;)
					i++;
				else
					j++;
			}
			printf("\n");
		}
		else
		{
			while(!(i==n && j==n))
			{
				printf("%c", Way5[i][j] );
				if(Way5[i][j]==&#39;D&#39;)
					i++;
				else
					j++;
			}
			printf("\n");
		}
	}
	else
	{
		if( min(DP2[1][1],DP5[1][1]) <= 1 )
		{
			printf("%d\n", min(DP2[1][1],DP5[1][1]));

			i=j=1;

			if(DP2[1][1]<DP5[1][1])
			{
				while(!(i==n && j==n))
				{
					printf("%c", Way2[i][j] );
					if(Way2[i][j]==&#39;D&#39;)
						i++;
					else
						j++;
				}
				printf("\n");
			}
			else
			{
				while(!(i==n && j==n))
				{
					printf("%c", Way5[i][j] );
					if(Way5[i][j]==&#39;D&#39;)
						i++;
					else
						j++;
				}
				printf("\n");
			}
		}
		else
		{
			printf("%d\n", 1);

			i = j = 1;

			while(i<x)
			{
				printf("D");
				i++;
			}

			while(j<y)
			{
				printf("R");
				j++;
			}	

			while(i<n)
			{
				printf("D");
				i++;
			}

			while(j<n)
			{
				printf("R");
				j++;
			}	

			printf("\n");				

		}
	}
	
	return 0;
}