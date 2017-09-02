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

int A[200007];
int R[200007];
int L[200007];
int Ans[200007];
multiset<int> T;
vector<int> V[200007];
stack<int> S;

int main()
{
	int i,j,k,N;
	sd(N);

	for(i=0;i<N;i++)
		sd(A[i]);

	for(i=0;i<N;i++)
	{
		while( !(S.empty()) && A[S.top()] > A[i] )
		{
			R[ S.top() ] = i-1;
			S.pop();
		}
		S.push(i);
	}
	while( !(S.empty()) )
	{
		R[ S.top() ] = N-1;
		S.pop();
	}

	for(i=N-1;i>=0;i--)
	{
		while( !(S.empty()) && A[S.top()] > A[i] )
		{
			L[ S.top() ] = i+1;
			S.pop();
		}
		S.push(i);
	}
	while( !(S.empty()) )
	{
		L[ S.top() ] = 0;
		S.pop();
	}	

	// for(i=0;i<N;i++)
		// printf("(%d) %d %d | ", i, L[i] , R[i] );	

	for(i=0;i<N;i++)
	{
		T.insert(A[i]);
		V[R[i]-L[i]+2].push_back(A[i]);
	}
	// printf("\n");
	multiset<int>::iterator it;
	for(i=1;i<=N;i++)
	{
		for(j=0;j<V[i].size();j++)
		{
			// printf("*Erasing %d ",V[i][j]);

			it = T.find(V[i][j]);
			if(it!=T.end())
			{
			    T.erase(it);
			}
		}
		// printf("\n Final :");
		// for(it = T.begin();it!=T.end();++it)
		// 	printf("%d ",*it );
		// printf("\n");
		it = T.end();
		it--;
		printf("%d ", *it );
	}
	printf("\n");
	return 0;
}

