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

int A[100007];
int B[100007];
int C[10000007];
map<int,int> MA[100007];
map<int,int> MB[100007];
map<int,int> CMA;
map<int,int> CMB;

int power(int x,int y)
{
	if(y==0)
		return 1;
	int t = power(x,y/2);
	if(y%2==0)
		return t*t;
	else
		return x*t*t;
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,p;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	for(i=2;i*i<10000007;i++)
	{
		if(C[i]==0)
		{
			for(j=i*i;j<10000007;j+=i)
			{
				C[j] = i;
			}
		}
	}

	// a = 0;
	for(i=2;i<10000007;i++)
	{
		if(C[i]==0)
		{
			// a++;
			C[i] = i;
		}
	}

	// printf("%d\n", a );
	
	sd(n);	sd(m);

	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=0;i<m;i++)
		sd(B[i]);	

	for(i=0;i<n;i++)
	{
		x = A[i];
		while(x!=1)
		{
			MA[i][C[x]]++;
			CMA[C[x]]++;
			x/=C[x];
		}
	}

	for(i=0;i<m;i++)
	{
		x = B[i];
		while(x!=1)
		{
			MB[i][C[x]]++;
			CMB[C[x]]++;
			x/=C[x];
		}
	}

	map<int,int>::iterator it;
  	for (it=CMA.begin(); it!=CMA.end(); ++it)
    {
    	(it->S) = min( (it->S), CMB[(it->F)] );
    }

  	for (it=CMB.begin(); it!=CMB.end(); ++it)
    {
    	(it->S) = min( (it->S), CMA[(it->F)] );
    }


	for(i=0;i<n;i++)
	{
	  	for (it=MA[i].begin(); it!=MA[i].end(); ++it)
	    {
	    	x = min( (it->S), CMA[(it->F)] );
	    	(it->S)-=x;	CMA[(it->F)]-=x;
	    	A[i]/=power((it->F),x);
	    }
	}

	for(i=0;i<m;i++)
	{
	  	for (it=MB[i].begin(); it!=MB[i].end(); ++it)
	    {
	    	x = min( (it->S), CMB[(it->F)] );
	    	(it->S)-=x;	CMB[(it->F)]-=x;
	    	B[i]/=power((it->F),x);
	    }
	}

	printf("%d %d\n", n , m );

	for(i=0;i<n;i++)
		printf("%d ", A[i] );
	printf("\n");
	for(i=0;i<m;i++)
		printf("%d ", B[i] );	

	return 0;
}