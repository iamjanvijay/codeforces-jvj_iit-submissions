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

int C[1007];

bool isValid(int x)
{
	bool v = true;
	if( (x & ((1<<7)|(1<<6))) == ((1<<7)|(1<<6)) )
		v = false;
	if( (x & ((1<<7)|(1<<5))) == ((1<<7)|(1<<5)) )
		v = false;	
	if( (x & ((1<<7)|(1<<0))) == ((1<<7)|(1<<0)) )
		v = false;
	if( (x & ((1<<4)|(1<<6))) == ((1<<4)|(1<<6)) )
		v = false;
	if( (x & ((1<<1)|(1<<6))) == ((1<<1)|(1<<6)) )
		v = false;
	if( (x & ((1<<2)|(1<<5))) == ((1<<2)|(1<<5)) )
		v = false;
	if( (x & ((1<<4)|(1<<5))) == ((1<<4)|(1<<5)) )
		v = false;
	if( (x & ((1<<2)|(1<<3))) == ((1<<2)|(1<<3)) )
		v = false;
	if( (x & ((1<<2)|(1<<0))) == ((1<<2)|(1<<0)) )
		v = false;	
	if( (x & ((1<<1)|(1<<0))) == ((1<<1)|(1<<0)) )
		v = false;
	if( (x & ((1<<3)|(1<<4))) == ((1<<3)|(1<<4)) )
		v = false;							
	if( (x & ((1<<1)|(1<<3))) == ((1<<1)|(1<<3)) )
		v = false;							
	return v;				
}

int CountBits(int x)
{
	int i,ans = 0;
	for(i=0;i<=7;i++)
		if(x & (1<<i))
			ans++;
	return ans;
}

void print(int x)
{
	stack<int> St;
	int i;
	for(i=0;i<=7;i++)
		if(x & (1<<i))
			St.push(1);
		else
			St.push(0);
	while(!St.empty())
	{
		printf("%d", St.top() );
		St.pop();
	}	
	printf("\n");
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m,n,x,y,z,a,b,r,ans=0;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);	sd(m);

	for(i=0;i<1007;i++)
		C[i] = (1<<4)-1;

	for(i=1;i<=m;i++)
	{
		sd(x);	sd(y);
		C[x] &= (~(1<<1));	C[x] &= (~(1<<0));
		C[y] &= (~(1<<3));	C[y] &= (~(1<<2));
	}

	// for(i=2;i<=n-1;i++)
	// 	print(C[i]);

	if(n<=2)
	{
		printf("%d\n", 0 );
		return 0;
	}

	for(i=2;i<=n/2;i++)
	{
		a = i;	b = n-i+1;
		// printf(": %d %d\n", a, b );
		// if(i>=10)
		// 	break;
		// printf("A : ");	print(C[a]); printf("B : ");	print(C[b]);
		z = 0;
		for(j=0;j<(1<<8);j++)
		{
			if(isValid(j))
			{
				// if( CountBits( ((C[a]<<4) | (C[b])) & (j) ) > 1 )
				// 	print(j);
				z = max( z, CountBits( ((C[a]<<4) | (C[b])) & (j) ) );
			}
		}
		// printf("%d %d\n", i , z );
		ans += z;
	}

	if(n%2==1)
	{
		if( CountBits( C[(n+1)/2] ) >=1 )
		{
			// printf("*%d\n", CountBits( C[(n+1)/2] ) );
			// print(C[(n+1)/2]);
			ans++;
		}
	}

	printf("%d\n", ans );
	
	return 0;
}