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
#define sz(x)       (int)x.size()
#define Mod         1000000007

char S[100007];
int Z[100007];
ll DP[100007];

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,l,m,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	ss(S);	n = strlen(S);

    int L, R, k;
 
    L = R = 0;
    for (i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;

            while (R<n && S[R-L] == S[R])
                R++;
            Z[i] = R-L;
            R--;
        }
        else
        {

            k = i-L;

            if (Z[k] < R-i+1)
                 Z[i] = Z[k];

            else
            {
                L = i;
                while (R<n && S[R-L] == S[R])
                    R++;
                Z[i] = R-L;
                R--;
            }
        }
    }

    for(i=0;i<n;i++)
    {
    	DP[ Z[i] ]++;
    }

    for(i=n-1;i>=0;i--)
    {
    	DP[i] += DP[i+1];
    }

    m = 0;
    for(i=n-1;i>0;i--)
    {
    	if( Z[i]+i == n )
    	{
    		m++;
    	}
    }

    printf("%d\n", m+1 );

    for(i=n-1;i>0;i--)
    {
    	if( Z[i]+i == n )
    	{
    		printf("%d %d\n",Z[i],DP[ Z[i] ]+1);
    	}
    }    

    printf("%d %d\n",n,1 );
	
	return 0;
}