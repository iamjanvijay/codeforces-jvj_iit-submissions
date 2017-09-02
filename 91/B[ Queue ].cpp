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
stack<int> St;

int search(int k,int m)
{
	if(m==0)
		return -1;

	if( A[ B[m-1] ] >= A[k] )
		return -1;

	int first,last,mid;

	first = 0;	last = m-1;

	while(first+1<last)
	{
		mid = (first+last)/2;

		if( A[B[mid]] < A[k] )
			last = mid;
		else
			first = mid;
	}

	if( A[ B[first] ] < A[k] )
	{
		return B[first]-k-1;
	}
	else
	{
		return B[last]-k-1;	
	}	
}

int main()
{
	// freopen("input_file_name.in","r",stdin);
	// freopen("output_file_name.out","w",stdout);

	int i,j,k,l,m=0,n,x,y,z,a,b,r;
	// ll i,j,k,l,m,n,x,y,z,a,b,r;

	sd(n);
	for(i=0;i<n;i++)
		sd(A[i]);

	for(i=n-1;i>=0;i--)
	{
		St.push( search(i,m) );
		if(m==0)
		{
			B[m++] = i;
		}
		else
		{
			if(A[B[m-1]]>A[i])
				B[m++] = i;
		}
	}
	
	while(!St.empty())
	{
		printf("%d ", St.top() );
		St.pop();
	}

	return 0;
}