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

char St[1000007];
int ANS[1000007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=1,n,x=0,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ANS[0] = 0;
	ss(St);	n = strlen(St);
	bool flag = true;
	for(i=0;i<n;i++)
	{
		if(St[i]==&#39;M&#39;)
			flag = false;
		else
		{
			if(flag)
			{
				ANS[m] = 0;
			}
			else
			{
				// printf("%d : %d (%d)\n", i, i-x, ANS[m-1] );
				if((i-x)>ANS[m-1])
				{
					ANS[m] = i-x;
					// printf("HERE\n");
				}
				else
				{
					ANS[m] = ANS[m-1] + 1;
					// printf("HERE 1\n");
				}
			}
			// printf("*%d\n", ANS[m] );
			m++;
			x++;
		}
	}

	printf("%d\n", ANS[m-1] );
	
	return 0;
}